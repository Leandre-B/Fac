N=7
sol=0

def trouve_les_solutions(echiquier, x:int) -> None :
    global N
    global sol
    if(x==N):
        sol+=1
    else :
        for i in range(N) :
            if echiquier[x][i]==0 :
                echiquier=place_reine(echiquier,x,i)

                """
                print(f'\nboard :')
                for j in range(N):
                    print(f'{echiquier[j]}')
                """
                
                trouve_les_solutions(echiquier,x+1)
                echiquier=supprime_reine(echiquier,x,i)

def place_reine(echiquier,x,y) :
    global N

    #invalide colonne
    for i in range(N) :
        echiquier[i][y]=x+1
    
    #invalide diagos hautes
    for i in range(1,x+1) :
        if(0<=y-i<N):
            echiquier[x-i][y-i]=x+1
        if(0<=y+i<N):
            echiquier[x-i][y+i]=x+1

    #invalide diagos basses
    for i in range(1,N-x) :
        if(0<=y+i<N):
            echiquier[x+i][y+i]=x+1
        if(0<=y-i<N):
            echiquier[x+i][y-i]=x+1

    echiquier[x][y]=x+1

    return echiquier

def supprime_reine(echiquier,x,y) :
    global N
    to_supr = echiquier[x][y]
    for i in range(0,N):
        for j in range(0,N):
            if(echiquier[i][j]==to_supr):
                echiquier[i][j]=0

    return echiquier



def main() : 
    echiquier = [[0]*N for _ in range(N)]
    trouve_les_solutions(echiquier,0)
    print(f'solultions : {sol}')


if __name__=='__main__' : 
    main()
