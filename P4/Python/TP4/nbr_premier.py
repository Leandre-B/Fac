import sys
import math



def est_premierV1 (n : int)->bool :
    nb_div=0
    for i in range(1,n+1):
        if(n%i==0):
            nb_div+=1
    if nb_div==2 : 
        return True
    else:
        return False
    

def est_premierV2(n:int)->bool :
    if (n<=1) : return False
    elif( n<=2 or n<=3) : return True
    elif n%2==0 : return False
    else :
        #recherche de diviseurs
        for i in range(3,int(math.sqrt(n))+2,2) :
            if n%i==0 :
                return False
    
    return True 

def erathostene(n:int)->list : 
    #on init un tab de booléen l'indice correspont au nb et sa val s'il est 1er ou non (True/False)
    t=[True for i in range(n+1)]

    #on met 0 et 1 a False (passe pas de crible erathostene)
    t[0]=False
    t[1]=False

    for i in range(2,n+1) :
        #on enleve les multiples des nbr 1er
        #le premier du tab est 3,
        #on enleve tout ses multiples
        #le prochain a True (5) est 1er (false)
        #on enleve tout ses multiples, le prochain a True(7)...
        if(t[i]==True) :
            for j in range(i*2,n+1,i) : t[j] = False

    #on return une liste avec seulement les nbr 1er (les indices à True)
    return [i for i in range(0,n+1) if t[i]==True]


#======FONCTION PRINCIPALE=======
def main():
    n=int(sys.argv[1])

    #liste_premier = [n for n in range(1,n+1) if est_premierV2(n)]
    #print(f'{liste_premier}\n{sum(liste_premier)}')
    l=erathostene(n)
    print(f'{l}\n {len(l)}')

#=====APPEL DU MAIN======#
if __name__=='__main__' : 
    main()