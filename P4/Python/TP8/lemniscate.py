import matplotlib.pyplot as plt
import math
import numpy as np


def x(t) :
    return (4*np.cos(t))/(1+np.sin(t)*np.sin(t))

def y(t) :
    return (8*np.cos(t)*np.sin(t))/(1+np.sin(t)*np.sin(t))




def main():
    #genere 100 val de 0 a 10
    t = np.linspace(0,2*np.pi,50)
    x_val = x(t)
    y_val = y(t)

    plt.figure(figsize=(10, 8))
    plt.plot(x_val,y_val,color='red')
    plt.ylim(-10,10)
    plt.grid()
    plt.show()
    #coucou


if __name__=='__main__' :
    main()
