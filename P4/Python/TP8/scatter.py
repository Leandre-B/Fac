import matplotlib.pyplot as plt
import math
import numpy as np

def f(x):
   return 2*x+5
    
x_values = np.random.uniform(-0, 10.0, 50)
y_values = f(x_values) + np.random.uniform(-0.2,0.2,50)
 
plt.scatter(x_values, y_values)
plt.show()
