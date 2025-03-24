import matplotlib.pyplot as plt
from matplotlib import cm
import math
import numpy as np
 

x_values = np.random.uniform(0,50,10)
#x_labels = x_values

#possible de faire ça par compréhension ??
x_explode = [0 for _ in range(len(x_values))]
for i in range(len(x_values)) :
   if x_values[i]==max(x_values):
      x_explode[i]=0.1
#print(x_explode)

"""
plt.pie(x_values, labels=x_labels,
   autopct='%1.1f%%', #autopoucent, affiche un truc sur les slices, ici %
   explode=x_explode) #'decalement' des slices
"""

plt.pie(x_values,
   autopct='%1.1f%%',
   explode=x_explode)

plt.title("Utilisation des langages de programmation")
plt.show()

