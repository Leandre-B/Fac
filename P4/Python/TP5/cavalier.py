deplacement_x=[-1,  1, 2,  2, 1, -1, -2, -2]    
deplacement_y=[-2, -2, 1, -1, 2,  2, -1, 1]
dim_echequier = 5
echequier = [[0]*dim_echequier for _ in range(dim_echequier)]
nb_sol=0
trouve = False

def aff(echequier) :
    for case in echequier :
        print (f'{case[0]:>2} | {case[1]:>2} | {case[2]:>2} | {case[3]:>2} | {case[4]:>2}')
        print('----------------------')



def position_valide(x,y) -> bool :
    if 0<=x<dim_echequier and 0<=y<dim_echequier: 
        return True
    return False


def trouve_sol(x,y,etape) :
    global nb_sol
    if(etape == dim_echequier*dim_echequier+1):
        nb_sol+=1
    else : 
        """
        for i in range(len(deplacement_x)) :
            next_x=x+deplacement_x[i]
            next_y=y+deplacement_y[i]
            if(position_valide(next_x,next_y)) : 
                if(echequier[next_x][next_y]==0) :
                    echequier[next_x][next_y] = etape
                    trouve_sol(next_x,next_y,etape+1)
                    echequier[next_x][next_y]=0
        """
        
        r=warnsdorff(y,x)
        if (len(x))>0
            for position in r :
                next_y=position[0]
                next_x=position[1]


#on regarde pour chaque deplacement possible, le nombres de déplacement après coup possible
def warnsdorff(y,x) :
    r=[]
    for i in range(len(deplacement_x)) :
        next_x=x+deplacement_x[i]
        next_y=y+deplacement_y[i]
        if(position_valide(next_x,next_y)) : 
              if(echequier[next_x][next_y]==0) :
                nbr=0
                echequier[next_x][next_y]=9999

                for j in range(len(deplacement_x)) :
                    futur_x=next_x+deplacement_x[j]
                    futur_y=next_y+deplacement_y[j]
                    if position_valide(futur_x,futur_y):
                        if echequier[futur_x][futur_y]==0
                            nbr+=1
            echequier[next_x][next_y]=0
            r.append([next_x,next_y,nbr])
    
    #tri la liste en fonction de nbr 
    r=sorted(r,key=lambda x : x[2])
    return r



def trouve_uniq_sol(x,y,etape) :
    global trouve
    global nb_sol
    global echequier
    
    if(etape == dim_echequier*dim_echequier+1):
        aff(echequier)
        trouve = True
        nb_sol+=1
    elif not trouve :
            for i in range(len(deplacement_x)) :
                next_x=x+deplacement_x[i]
                next_y=y+deplacement_y[i]
                if(position_valide(next_x,next_y)) : 
                    if(echequier[next_x][next_y]==0) :
                        echequier[next_x][next_y] = etape
                        trouve_uniq_sol(next_x,next_y,etape+1)
                        echequier[next_x][next_y]=0

#TODO - def choisir_best_dpl()
    
def main() : 
    echequier[0][0]=1
    trouve_uniq_sol(0,0,2)
    print(nb_sol)




if __name__=='__main__' : 
    main()
