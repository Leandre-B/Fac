from function import f
epsi = 1e-8


def zero_fonction(a: float,b:float) -> float :
    m = (a+b)/2
    count = 0
    while not(abs(f(m))<epsi) :
        count+=1 
        if (f(a)*f(m))<0.0 : 
            b=m
        else : 
            a=m
        m = (a+b)/2
    return m,count


def main():
    m,count=zero_fonction(6.0,7.0)
    print(f'{count} {round(m,3)} {f(m)}')
    



if __name__=='__main__' : 
    main()
