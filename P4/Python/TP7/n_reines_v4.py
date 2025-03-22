import sys
N=int(sys.argv[1])
sol=0

def trouve_les_solutions(rangees,droite,gauche, x:int) -> None :
    global N
    global sol
    if(x==N):
        sol+=1
    else :
        for i in range(N) :
            if (rangees[i] and droite[x+i] and gauche[N+x-i] == True):
                rangees[i]=False
                droite[x+i]=False
                gauche[N+x-i]=False

                trouve_les_solutions(rangees,droite,gauche,x+1)

                rangees[i]=True
                droite[x+i]=True
                gauche[N+x-i]=True
                



def main() :
    rangees = [True]*(N)
    droite = [True]*(2*N)
    gauche = [True]*(2*N)
    print (gauche)
    trouve_les_solutions(rangees,droite,gauche,0)
    print(f'solultions : {sol}')
    
    
if __name__=='__main__' : 
    main()