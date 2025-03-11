

def fibo(n:int) : 
    if n==0 : return 0
    elif n==1 : return 1
    else : return fibo(n-1)+fibo(n-2)


def main():
    for i in range(1,21) : 
        print(f'fibo({i:>2}) = {fibo(i):>5}')

if __name__ == '__main__' : 
    main()