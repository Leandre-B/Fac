from function import f
from sympy import *
epsi = 1e-8


def zero_dichoto(a: float,b:float) -> float :
    m = (a+b)/2
    count = 0
    while not(abs(f(m))<epsi) :
        count+=1 
        if (f(a)*f(m))<0.0 : 
            b=m
        else : 
            a=m
        m = (a+b)/2
    return m,f(m),count

def zero_secante(a:float, b:float) ->float : 
    count=0
    m = (a * f(b) - b * f(a)) / (f(b) - f(a))   
    while not abs(f(m))<epsi :
        count+=1
        if f(a)*f(m)<0 : 
            b=m
        else : 
            a=m
        m = (a * f(b) - b * f(a)) / (f(b) - f(a))
    return m,f(m),count

def zero_tangente(a:float, b:float)->float :
    count=0
    m=(a+b)/2
    while not abs(f(m))<epsi : 
        count+=1
        m=m-(f(m)/((f(m+epsi)-f(m))/epsi))
    return m,f(m),count

def main():
    m,fm,count=zero_tangente(4.0,7.0)
    print(f'{count} {round(m,3)} {fm}')

    #bornes : 
    a=1
    b=10

    #listes de x et f(x)
    l_x = [((b-a)*i)/200 +a for i in range(1,201)]
    l_y=[f(x) for x in l_x]
    
    couples=[]
    for i in range(len(l_x)-1):
        if f(l_x[i])*f(l_x[i+1])<0 :
            couples +=[[l_x[i],l_x[i+1]]]

    print('Couple : ')
    for couple in couples : 
        print(couple)
    
    for couple in couples : 
        print('--------------')
        print(f'Couple : {couple}')
        m,fm,count=zero_dichoto(couple[0],couple[1])
        print(f'{count:>2} {m:>20} {fm:>1}')

        m,fm,count=zero_secante(couple[0],couple[1])
        print(f'{count:>2} {m:>20} {fm:>1}')
        
        m,fm,count=zero_tangente(couple[0],couple[1])
        print(f'{count:>2} {m:>20} {fm:>1}')
        

if __name__=='__main__' : 
    main()
