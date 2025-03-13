import numpy as np
import math

def racine(x) :
    return math.sqrt(x)

#======= exo 6.1 ======
def exo6_1():
    X = np.arange(1,3,0.5)
    Y = np.arange(3,1,-0.5)
    Z=X+Y
    print(f'X={X}')
    print(f'Y={Y}')
    print(f'Z=X+Y={Z}')
    
    vec_racine=np.vectorize(racine)
    Z=vec_racine(Z)
    print(f'Z=sqrt(Z)={Z}')


#======= exo 6.2 ======
def exo6_2():
    M1=np.arange(1,16).reshape(3,5)
    M2=np.arange(15,0,-1).reshape(5,3)

    M3=np.dot(M1,M2)
    M4=np.transpose(M3)
    somme=M4.sum()

    print(f'M1 = {M1}')
    print(f'M2 = {M2}')
    print(f'M3 = {M3}')
    print(f'M4 = {M4}')
    print(f'Sum = {somme}')


def exo6_3():
    M=np.ones((5,3))
    col = np.array([1,3,5,7,9]).reshape(5,1)
    M=np.append(M,col,axis=1)
    col = np.array([2,3,6,8,10]).reshape(5,1)
    M=np.append(M,col,axis=1)

    print(M)

def is_btw_1_5(x):
    if 1<=x<=5:
        x=True
    else : 
        x=False
    return x


def exo6_4():
    X=np.random.uniform(1.0,10.0,10)
    print(f'X = {X}')

    vec_btw_1_5 =np.vectorize(is_btw_1_5)
    Y=vec_btw_1_5(X)
    print(f'Y = {Y}')

    
    Z=[]
    for i in range(np.size(Y)) :
        if Y[i]==True:
            Z=np.append(Z,X[i])
    print(Z)

def main() : 
    exo6_4()




if __name__ == '__main__' : 
    main()