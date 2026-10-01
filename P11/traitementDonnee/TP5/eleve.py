import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv("eleves.tsv", sep="\t", header=0, encoding='latin-1')
# print(data)
data = data.drop_duplicates()

data_clean = pd.DataFrame(columns = data.columns)

for index, row in data.iterrows():
        keep = 1
        for indexC, rowC in data.iterrows():
            if index != indexC and data.loc[index, 'Identité']==data.loc[indexC, 'Identité']  and data.loc[index, 'Sexe']==data.loc[indexC, 'Sexe'] :
                # print(data.loc[index, 'Identité'])
                if int(data.loc[index, 'Âge']) < int(data.loc[indexC, 'Âge']) :
                    keep = 0
        if keep == 1 :
            data_clean.loc[len(data_clean)] = row

# print(data_clean)

#### Grap p_sexes barplot
n_f = (data_clean.loc[
        (data_clean["Sexe"] == "F")
    , :])[["Sexe"]]
n_h = (data_clean.loc[
        (data_clean["Sexe"] == "M")
    , :])[["Sexe"]]

# print(len(n_f))
# print(len(n_h))
df_s = (pd.DataFrame({"Sexes":["F", "M"], "Nombre d'élèves":[len(n_f), len(n_h)]}))

df_s.plot.bar(x="Sexes", y="Nombre d'élèves", rot=0)
plt.savefig("p_sexes.png")

#### Graph p_ages_etudes
age_etu = data_clean[["Âge", "Niveau d'études"]]
age_etu["Âge"] = age_etu["Âge"].astype(int)
age_etu["Niveau d'études"] = pd.Categorical(age_etu["Niveau d'études"],
    categories=["Primaire", "Collège", "Lycée", "Université"]
)
# print(age_etu)

age_etu.boxplot(column=["Âge"], by="Niveau d'études")

plt.savefig("p_ages_etudes.png")

