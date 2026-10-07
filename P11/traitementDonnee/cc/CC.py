import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv("fete-de-la-musique-2019.csv", sep=";", header=0)
# print(data)

# titre_18 = data[data['Age minimum'].notna() & data['Titre (fr)'].notna()]
titre_18 = data[(data['Age minimum'] > 18)]

titre_18 = pd.DataFrame({
    'Titre (fr)': titre_18['Titre (fr)']
})
# print(titre_18)


repartition = data[data['Région'].notna()]
repartition['Région'].value_counts().plot.bar(title="Répartition des concerts par région")
plt.savefig("p_repartition_concerts_regions.png")

repartition['total'] = 1
repartition = repartition.groupby(['Région'])['total'].sum().reset_index()
# print(repartition)


labels = list(set(data['label_multivalued'].dropna().str.split(';').explode()))
# print(labels)

li = data['label_multivalued'].dropna().str.split(';').explode().value_counts()
# print(li)

