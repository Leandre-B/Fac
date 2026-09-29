import pandas as pd

def lire (fichier, perequation, competitions) :
    df = pd.read_csv(fichier)


# ((df["lb_nom_abg"].str.contains("DFU")) |
#          (df["lb_nom_abg"].str.contains("DFU"))
#          (df["lb_nom_abg"].str.contains("DFU"))
#         )


    df = df.loc[
        (df["libelle"] == "Arbitre") &
        (df["presence"] == "P") &
        (df["indemnite"] != "") &
        ((pd.notna(df["indemnite"])))
    , :]
    df_clean = pd.DataFrame(columns = df.columns)

    for p in perequation :
        df_clean = pd.concat([df_clean, df.loc[(df["lb_nom_abg"].str.contains(p)), :]], ignore_index=True)

    for c in competitions :
        df_clean = pd.concat([df_clean, df.loc[(df["lb_nom_abg"].str.contains(c)), :]], ignore_index=True)

    print(df_clean["indemnite"])
    COLUMNS =  ["id", "nom", "prenom", "licence", "indemnite"]
    arbitres = pd.DataFrame(columns = COLUMNS)

    for index, row in df_clean.iterrows():
        # Cherche l'arbitre dans df_arbrite et update l'indemnite si trouve
        found = 0
        for indexC, rowC in arbitres.iterrows():
            if(rowC['id'] == row['id']) :
                found = 1
                print("add ", row['indemnite']/2, "to ", rowC['indemnite'])
                arbitres['indemnite'][indexC] += row['indemnite']/2
                break 
        if found == 0 :
            arbitres = pd.concat(
            [
                arbitres, 
                pd.DataFrame([
                    [row['id'], 
                    row['nom'],
                    row['prenom'],
                    row['numero_licence'],
                    row['indemnite'] /2
                ]], columns=COLUMNS)
            ])


    arbitres = arbitres.sort_values(by=["indemnite"])
    print(arbitres)


    clubs = pd.DataFrame(columns=["club", "facture"])
    for index, row in df_clean.iterrows():
        # Cherche l'arbitre dans df_arbrite et update l'indemnite si trouve
        found = 0
        cs = [[row["GS1"].split("-")[1], False], [row["GS2"].split("-")[1], False]]
        for indexC, rowC in clubs.iterrows():
            for c in cs :
                if(rowC['club'] == c[0]) :
                    c[1] = True
                    print("add ", row['indemnite']/2, "to ", rowC['facture'])
                    clubs['facture'][indexC] += row['indemnite']/2
                    break
        for c in cs :
            if not c[1] : 
                clubs = pd.concat([
                    clubs,
                    pd.DataFrame([[
                        c[0],
                        row['indemnite']
                    ]], columns=["club", "facture"])
                ])
    print(clubs)

    return [arbitres, clubs]

if __name__ == "__main__" :            
    lire("officiels.csv", ["PRM", "PRF"], ["DMU", "DFU"])