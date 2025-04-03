import matplotlib.pyplot as plt
import numpy as np

def f (x) : 
	return x*x - 4*x + 3 

#fonction pour calculer dérivée ??
#sympy

def f_deri (x):
	return 2*x -4

x = np.linspace(-2,6,100)
y = f(x)
y_deriv = f_deri(x)

plt.figure(figsize=(5,5))
plt.plot(x,y,color='red',label='f(x)')
plt.plot(x,y_deriv,color='green',label='dérivée')
plt.axhline(color='blue')


plt.grid()

plt.ylabel='f(x)'
plt.xlabel='x'

plt.legend(loc="lower right")

#changer couleur de l'axe x en bleu ???

plt.show()


