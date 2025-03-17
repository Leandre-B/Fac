N=7
sol=0

def trouve_les_solutions(echiquier, x:int) -> None :
    global N
    global sol
    if(x==N):
        sol+=1
    else :
        for i in range(N) :
            if not existe_conflit(echiquier,x,i) :
                echiquier[x][i]=x+1

                print(f'\nboard :')
                for i in range(N):
                    print(f'{echiquier[i]}')
                
                trouve_les_solutions(echiquier,x+1)
                echiquier[x][i]=0


def existe_conflit(echiquier, x,y) -> bool :
    #verif colonne
    global N
    for i in range(x) :
        if(echiquier[i][y]!=0):
            return True 
    
    #verif diagos
    for i in range(1,x) :
        if(0<=y-i<N):
            if(echiquier[x-i][y-i]!=0): return True
        if(0<=y+i<N):
            if(echiquier[x-i][y+i]!=0): return True

    return False
        




def main() :
    echiquier = [[0]*N for _ in range(N)]
    trouve_les_solutions(echiquier,0)
    print(sol)
    
    
if __name__=='__main__' : 
    main()