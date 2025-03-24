import matplotlib.pyplot as plt
import numpy as np
import string
from matplotlib.colors import ListedColormap

def lire_fichier(file_name : str)->str : 
   try :
      with open(file_name,'r',encoding='utf-8') as fichier:
         texte = fichier.read() #stock l'entierté du contenue de {file_name}

   except FileNotFoundError:
      print("fichier non existant")

   return texte

malibu=lire_fichier('mu.csv').replace('\n',',').split(',')
#print(malibu)

etat=[malibu[i] for i in range(0,len(malibu)-1,3)]
indices_etats=etat
for i in range(len(indices_etats)):
   if(indices_etats[i]=='arizona') : indices_etats[i] = 0
   elif(indices_etats[i]=='california') : indices_etats[i] = 1
   else : indices_etats[i] = 2

print(indices_etats)
note_math=[malibu[i] for i in range(1,len(malibu),3)]
note_info=[malibu[i] for i in range(2,len(malibu),3)]


# création d'une colormap afin de distinguer chaque groupe
# d'étudiant en fonction de l'état de provenance
colors = ['orangered', 'dodgerblue', 'chartreuse', 'peru' ]
jmr_cmap = ListedColormap(colors)

plt.figure(figsize=(10, 8))
ax = plt.axes()
ax.set_facecolor("cornsilk")
 
plt.xlabel("notes math")
plt.ylabel("notes info")
plt.xlim(0,22)
plt.ylim(0,22)

# affichage des diagonales
x=np.arange(1,20)
y1=x
y2=20-x
plt.plot(x, y1, "silver", linestyle='--', alpha=0.6)
plt.plot(x, y2, "silver", linestyle='--', alpha=0.6)

# affichage des données
plt.scatter(note_math, note_info, c=indices_etats, cmap=jmr_cmap, s=50)
 
plt.show()
 
plt.scatter(x_values, y_values)
plt.show()

#TODO : AXE CHELOU MDRR
#faut juste convertir les axes en entier 
