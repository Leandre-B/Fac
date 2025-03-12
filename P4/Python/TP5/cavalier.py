deplacement_x=[-1,  1, 2,  2, 1, -1, -2, -2]    
deplacement_y=[-2, -2, 1, -1, 2,  2, -1, 1]
dim_echequier = 5
echequier = [[0]*dim_echequier for _ in range(dim_echequier)]
nb_sol=0

def position_valide(x,y) -> bool :
    if 0<=x<dim_echequier and 0<=y<dim_echequier: 
        return True
    return False


def trouve_sol(x,y,etape) :
    global nb_sol
    if(etape == dim_echequier*dim_echequier+1):
        nb_sol+=1
    else : 
        for i in range(len(deplacement_x)) :
            next_x=x+deplacement_x[i]
            next_y=y+deplacement_y[i]
            if(position_valide(next_x,next_y)) : 
                if(echequier[next_x][next_y]==0) :
                    echequier[next_x][next_y] = etape
                    trouve_sol(next_x,next_y,etape+1)
                    echequier[next_x][next_y]=0


def trouve_uniq_sol(x,y,etape) :
    global echequier
    if(etape <= dim_echequier*dim_echequier+1):
        for i in range(len(deplacement_x)) :
            next_x=x+deplacement_x[i]
            next_y=y+deplacement_y[i]
            if(position_valide(next_x,next_y)) : 
                if(echequier[next_x][next_y]==0) :
                    echequier[next_x][next_y] = etape
                    trouve_sol(next_x,next_y,etape+1)
                    echequier[next_x][next_y]=0

def main() : 
    echequier[0][0]=1
    trouve_uniq_sol(0,0,2)
    print (f'{echequier[0]}\n{echequier[1]}\n{echequier[2]}\n{echequier[3]}\n{echequier[4]}\n')
    #print(f'Nombre de sol : {nb_sol}')




if __name__=='__main__' : 
    main()