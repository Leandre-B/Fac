N=7
sol=0

trouve_les_solutions(echiquier, y:int) -> None :
    global N
    if(y>N):
        sol+=1
    else :
        
        




def main() :
    echequier = [[0 for _ in range(N)]]*N
    trouve_les_solutions(echequier,0)
    
    
if __name__=='__main__' : 
    main()