import matplotlib.pyplot as plt
from matplotlib import cm
import math
import numpy as np
 
# langages de programmation
y_labels = [ 'C++', 'Ruby', 'Python', 'Php' ]
 
# x_values indique sur l'axe des x où on doit situer
# la barre verticale
x_values = [ 1, 2, 3, 4 ]
 
# y_values représentent les données associées à chaque langage
y_values = [ 20, 10, 30, 15 ]
"""
#====Barres horinzontales========
plt.bar(x=x_values, height=y_values, #valeurs en x, valeurs en y
   width=0.9, #largeure de chaque barres
   color='red', #couleur de chaque barres
   tick_label = y_labels) #légende des barres
"""

#====Barres verticales========
plt.barh(y=x_values, width=y_values, height=0.9,
   color=['#be7733', '#138ABc', '#89bf76', '#4A987f'],
   tick_label = y_labels,
   hatch="o", #effet "<symb>" dans les barres
   edgecolor='red') #couleur du hatch

#plt.savefig('img/plot_bar_chart.png')
plt.show()
