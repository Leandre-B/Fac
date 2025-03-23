import matplotlib.pyplot as plt
import math
import numpy as np


def f1(x) :
    return np.sqrt(np.abs(x)-3) * x

def f2(x) :
    return x * np.log10(x)

def f3(x) :
    return x * x




def main():
    #genere 100 val de 0 a 10
    x_val = np.linspace(0,10,100)
    y1_val = f1(x_val)
    y2_val = f2(x_val)
    y3_val = f3(x_val)

    plt.plot(x_val,y1_val,color='red')
    plt.plot(x_val,y2_val,color='blue')
    plt.plot(x_val,y3_val,color='green')
    plt.grid()
    plt.ylabel='f(x)'
    plt.xlabel='x'
    plt.show()


if __name__=='__main__' :
    main()
