import pandas as pd
import numpy as np

################ FILTRAGE ###############

df_filtre = df[(df['col_A'] < 5) | (df['col_B'] != 'Exclu')]

# Valeur présente dans une liste
df_filtre = df[df['col_D'].isin(['Valeur1', 'Valeur2'])]

# Condition sur du texte (na=False évite les erreurs s'il y a des valeurs manquantes)
df_filtre = df[df['col_Texte'].str.contains('mot', na=False)]

# Exclure les NA
df_filtre = df[df['col_A'].notna()]
# ou df_filtre = df.dropna(subset=['col_A'])

#########################################

################# MODIF #################

df['col_B'] = df['col_B'] * 1.2

# Modification avec condition : on utilise .loc[condition, 'colonne']
df.loc[(df['col_A'] > 10) & (df['col_B'] == 'Validé'), 'col_C'] = 'Gagnant'

# Colonnes
# Créer ou écraser une colonne directement
df['new_col'] = [4, 5, 6] 

df = df.drop(columns=['col_a_supprimer'])
df = df.drop(columns=['nom_col1', 'nom_col2'])
# Supprimer par index (ex: supprimer la 2ème colonne, index 1 car Python commence à 0)
df = df.drop(df.columns[1], axis=1) # axis : 0 -> lignes, 1 -> colonnes

# Lignes
# Pour ajouter des lignes, on utilise pd.concat avec une liste de dataframes
nouvelle_ligne = pd.DataFrame({'col_A': [10], 'col_B': ['Oui']})
df = pd.concat([df, nouvelle_ligne], ignore_index=True)
clubs = pd.concat([clubs_1, clubs_2], ignore_index=True)

# Supprimer par index (.iloc pour la position)
df = df.iloc[1:] # Supprime la 1ère ligne (index 0)
df = df.iloc[3:] # Supprime les lignes 1 à 3 (index 0, 1, 2)
df = df[df['col_A'] != 10] # Filtrage comme en haut

##########################################

######## Trucs cools #######
# Garde le premier rencontré (keep='first'), équivalent strict au duplicated de R
df_sans_doublons = df.drop_duplicates(subset=['nom', 'prenom', 'sexe'], keep='first')

# GroupBy (équivalent de aggregate)
# reset_index() permet de garder id, nom, prenom comme colonnes normales et non comme index
resultat = df_arbitres.groupby(['id', 'nom', 'prenom'])['indemnite'].sum().reset_index()

# Remplacer .sum() par :
# .mean() / .median() / .min() / .max()
# .size() : Compter le nombre d'éléments
# .std() : Écart-type
# .var() : Variance

clubs_1 = pd.DataFrame({
    'club': data['GS1'],
    'indemnite': data['indemnite'] / 2
})

# Attention Python commence à 0, donc le 2ème élément de strsplit est à l'index 1 (str[1])
data['GS1'] = data['GS1'].str.split(' - ').str[1]
##########################################

###### TRIER #######
df_trie = df.sort_values(by='age', ascending=False)

# Trier sur plusieurs colonnes avec des ordres différents
df_trie = df.sort_values(by=['niveau_etudes', 'age'], ascending=[False, True])

# Définir l'ordre logique des classes (équivalent des factors)
df['niveau'] = pd.Categorical(df['niveau'], 
                              categories=['Primaire', 'Collège', 'Lycée', 'Université'], 
                              ordered=True)

# sort_values() va maintenant trier selon cet ordre logique
df_trie = df.sort_values(by='niveau')

# Assigner des labels à des valeurs numériques (équivalent levels/labels de R)
m_etud = {0: 'NR', 1: 'Primaire', 2: 'Secondaire', 3: 'Bac', 4: 'Supérieur'}
data['ETUD'] = data['etu'].map(m_etud)

# Si tu veux en plus que ce soit ordonné dans pandas :
data['ETUD'] = pd.Categorical(data['ETUD'], 
                              categories=['NR', 'Primaire', 'Secondaire', 'Bac', 'Supérieur'], 
                              ordered=True)
###########################

######### GRAPH ############

import matplotlib.pyplot as plt

# Mise en forme commune à placer avant plt.show()
# plt.title("Mon Titre")
# plt.xlabel("Axe X")
# plt.ylabel("Axe Y")

# 1. Nuage de points ou Lignes
plt.scatter(df['x'], df['y'], color='blue') # Points
# ou plt.plot(df['x'], df['y'], color='red') # Lignes

# 2. Diagramme circulaire
effectifs = df['categorie'].value_counts()
plt.pie(effectifs, labels=effectifs.index, colors=['red', 'green', 'blue'])

# 3. Boîte à moustaches
# Le plus simple est d'utiliser la fonction intégrée de pandas
df.boxplot(column='age', by='niveau', color='orange')
plt.suptitle("") # Enlève le titre automatique généré par pandas

# 4. Histogramme
plt.hist(df['salaire'], bins=10, color='grey', edgecolor='black')
# bins = nombre de barres

# 5. Diagramme en barres
effectifs = df['sexe'].value_counts()
plt.bar(effectifs.index, effectifs.values, color=['pink', 'lightblue'])

# Toujours terminer par :
plt.show()

# version pandas
df.plot.scatter(x='x', y='y', color='blue', title="Mon Titre")
df.plot.line(x='x', y='y')

df['categorie'].value_counts().plot.pie(title="Répartition")

df.boxplot(column='age', by='niveau', figsize=(8,6))

df['salaire'].plot.hist(bins=10, title="Distribution", edgecolor='black')

df['sexe'].value_counts().plot.bar(title="Comptage", color=['pink', 'lightblue'])
###########################