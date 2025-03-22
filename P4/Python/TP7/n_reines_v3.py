N=7
sol=0


def aff (echiquier):
    print(f'\nboard :')
    for j in range(N):
        print(f'{echiquier[j]}')


def trouve_les_solutions(echiquier, x:int) -> None :
    global N
    global sol
    if(x==N):
        #if sol<10 :
            #aff(echiquier)
        sol+=1
    else :
        for i in range(N) :
            if echiquier[x][i]==0 :
                place_reine(echiquier,x,i)
                
                trouve_les_solutions(echiquier,x+1)
                
                supprime_reine(echiquier,x)

def place_reine(echiquier,x,y) :
    global N

    #invalide colonne basse
    for i in range(x,N) :
        if echiquier[i][y]==0 :
            echiquier[i][y]=x+1
    """
    #bah inutile en fait
    #invalide diagos hautes
    for i in range(1,x+1) :
        if(0<=y-i<N and echiquier[x-i][y-i]==0):
            echiquier[x-i][y-i]=x+1
        if(0<=y+i<N and echiquier[x-i][y+i]==0):
            echiquier[x-i][y+i]=x+1
    """

    #invalide diagos basses
    for i in range(1,N-x) :
        if(0<=y+i<N and echiquier[x+i][y+i]==0):
            echiquier[x+i][y+i]=x+1
        if(0<=y-i<N and echiquier[x+i][y-i]==0):
            echiquier[x+i][y-i]=x+1

    echiquier[x][y]=x+1

def supprime_reine(echiquier,x) :
    global N
    for i in range(0,N):
        for j in range(0,N):
            if(echiquier[i][j]==x+1):
                echiquier[i][j]=0

def test(echiquier):
    place_reine(echiquier,0,1)
    aff(echiquier)
    supprime_reine(echiquier,0,1)
    aff(echiquier)


def main() : 
    echiquier = [[0]*N for _ in range(N)]
    trouve_les_solutions(echiquier,0)
    print(f'solultions : {sol}')
    #test(echiquier)

if __name__=='__main__' : 
    main()
