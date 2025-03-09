import sys

def collatz (n:int) ->list:
    if(n==1) : return [1]
    elif (n%2==0) : return [n]+collatz(n//2)
    else :  return [n]+collatz(3*n+1)





def main() : 
    n=int(sys.argv[1])
    print(f'{collatz(n)}')


if __name__=='__main__' : 
    main()
