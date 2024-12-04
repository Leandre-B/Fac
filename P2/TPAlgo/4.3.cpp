#include <iostream>
#include <array>
#include <vector>
#include <stdlib.h>
#include <time.h>


using tab = std::array<std::array<char,100>,100>;
using tabInt = std::array<std::array<int,100>,100>;

struct coord{
    std::array<int,2> arr;
};

void init(tab & board, int & taille, char & j){
    std::cout<<"Entrez la taille du jeu du morpion : ";
    std::cin>>taille;
    for(int i = 0;i<taille; ++i){
        for(int j = 0;j<taille; ++j)
            board[i][j]=' ';
    }
    j = 'X';
}

bool testfin(tab board, int taille){
    //test pions aligne hori
    for(int i =0;i<taille;++i){
        for(int j = 0;j<taille-3;++j){
            if(board[i][j]==board[i][j+1] and board[i][j+2]==board[i][j+3] and board[i][j]==board[i][j+3] and board[i][j]!=' '){
                return true;
            }
        }
    }

    //test pions aligne vertc
    for(int i =0;i<taille;++i){
        for(int j = 0;j<taille-3;++j){
            if(board[j][i]==board[j+1][i] and board[j+2][i]==board[j+3][i] and board[j][i]==board[j+3][i] and board[j][i]!=' '){
                return true;
            }
        }
    }

    //diag h-b  g-d
    for(int i =0;i<taille-3;++i){
        for(int j = 0;j<taille-3;++j){
            if(board[j][i]==board[j+1][i+1] and board[j+2][i+2]==board[j+3][i+3] and board[j][i]==board[j+3][i+3] and board[j][i]!=' '){
                return true;
            }
        }
    }

    //diag h-b d-g
    for(int i =0;i<taille-3;++i){
        for(int j = taille-1;j>2;--j){
            if(board[j][i]==board[j-1][i+1] and board[j-2][i+2]==board[j-3][i+3] and board[j][i]==board[j-3][i-3] and board[j][i]!=' '){
                return true;
            }
        }
    }

    bool full=true;
    for(int i =0;i<taille;++i){
        for(int j = 0;j<taille;++j){
            if(board[i][j]==' '){
                full=false;
            }
        }
    }
    if(full)
        return true;

    return false;
}

char changeJ(char j){
    if(j=='X')
        return 'O';
    return 'X';
}

void initBstMove(tabInt & bstMove, int t)
{
    for(int i = 0;i<t;++i)
        for(int j =0;j<t;++j){
            bstMove[i][j]=0;
    }
}

void listMove(tabInt bstMove, int plsHautScore, int t, std::vector<coord> & tabListMove)
{
    coord move;
    for(int i = 0;i<t;++i){
        for(int j = 0;j<t;++j){
            if(bstMove[i][j]==plsHautScore){
                move.arr[0]=i;
                move.arr[1]=j;
                tabListMove.push_back(move);
            }
        }
    }
}

void chooseMove(std::vector<coord> tabListMove, int & i, int & j){
    srand((time(NULL)));
    int rdm;
    if(tabListMove.size()==1){
        i=tabListMove[0].arr[0];
        j=tabListMove[0].arr[1];
    }else{
        rdm=rand()%tabListMove.size();
        i=tabListMove[rdm].arr[0];
        j=tabListMove[rdm].arr[1];
    }
}

// void closeToLose(tab board, int taille, tabInt & bstMove){
//     std::vector<true> pionAlign;
//     //test pions aligne hori
//     for(int i =0;i<taille;++i){
//         for(int j = 0;j<taille-3;++j){
//             for(int k=0;k<4;++4){
//                 if(board[i][j+k]!=' ')
//                     pionAlign.push_back(true);
//                 else
//                     pionAlign.push_back(false);
//             }
//
//         }
//     }
//
/*
    //test pions aligne vertc
    for(int i =0;i<taille;++i){
        for(int j = 0;j<taille-2;++j){
            if(board[j][i]==board[j+1][i] and board[j+1][i]==board[j+2][i] and board[j][i]!=' '){
                bstMove[j+3][i]+=5;
                bstMove[j-3][i]+=5;
            }
        }
    }

    //diag h-b  g-d
    for(int i =0;i<taille-2;++i){
        for(int j = 0;j<taille-2;++j){
            if(board[j][i]==board[j+1][i+1] and board[j][i]==board[j+2][i+2] and board[j][i]!=' '){
                bstMove[j+3][i+3]+=5;
                bstMove[j-3][i-3]+=5;
            }
        }
    }

    //diag h-b d-g
    for(int i =0;i<taille-2;++i){
        for(int j = taille-1;j>3;--j){
            if(board[j][i]==board[j-1][i+1] and board[j-2][i+2]==board[j][i] and board[j][i]!=' '){
                bstMove[j-3][i+3]+=5;
                bstMove[j+3][i-3]+=5;
            }
        }
    }
}*/

void jouerBot(tab & board, int t, char cJ){
    tabInt bstMove;
    initBstMove(bstMove,t);
    int plsHautScore=-1;
    for(int i = 0;i<t;++i){
        for(int j =0;j<t;++j){

            if(board[i][j]==' '){

                for(int x=i-1 ; x<i+1 ; ++x){
                    for(int y=j-1 ; y<j+1 ; ++y){

                        if(x>=0 and y>=0 and x<t and y<t){
                            if(board[x][y]==cJ)
                                ++bstMove[i][j];
                        }
                    }
                }
                //closeToLose(board, t,bstMove);

                if(plsHautScore<bstMove[i][j])
                    plsHautScore=bstMove[i][j];

                std::cout<<char(j+65)<<i+1<<"  Pls haut score : "<<plsHautScore<<" | Score = "<<bstMove[i][j]<<"  coord : "<<i<<" "<<j<<std::endl;
            }

        }
    }
    std::vector<coord> tabListMove;
    listMove(bstMove, plsHautScore,t,tabListMove);
    int i,j;
    chooseMove(tabListMove, i, j);
    board[i][j]=cJ;

}

void jouer(tab & board, int taille, char j){
    if(j=='X'){
        jouerBot(board, taille, j);

    }else{
        std::string c;
        do{
            std::cout<<"Entrez case (ex:B1) : ";
            std::cin>>c;

            if( (int(c[1])-48<=0 or int(c[1])-48>taille or int(c[0])-64<=0 or int(c[0])-64>taille or board[int(c[1])-48-1][int(c[0])-64-1]!=' '))
                std::cout<<"Valeures incorrectes : veuillez reessayer."<<std::endl;

        }while((int(c[1])-48<=0 or int(c[1])-48>taille or int(c[0])-64<=0 or int(c[0])-64>taille or board[int(c[1])-48-1][int(c[0])-64-1]!=' '));

        board[int(c[1])-48-1][int(c[0])-64-1]=j;
    }
}

void aff(tab board, int taille){
    std::cout<<"----- Jeu -----"<<std::endl<<std::endl<<"   ";
    for(int i = 0;i<taille; ++i){
        std::cout<<" "<<char(65+i)<<"  ";
    }
    std::cout<<std::endl<<std::endl;
    for(int i = 0;i<taille; ++i){
        std::cout<<i+1<<"  ";
        for(int j = 0;j<taille; ++j){
            if(j==0)
                std::cout<<" "<<board[i][j];
            else
                std::cout<<" | "<<board[i][j];
        }
        std::cout<<std::endl<<"   ";
        if(i!=taille-1){
            for(int k = 0;k<taille;++k){
                if(i!=taille-1)
                    std::cout<<"----";
                else
                    std::cout<<"---";
            }
        }
        std::cout<<std::endl;
    }
}

int main(){
    int taille;
    char j;
    tab board;
    bool fin = false;
    init(board, taille,j);
    aff(board, taille);
    do{
        j = changeJ(j);
        jouer(board, taille,j);
        fin = testfin(board,taille);
        aff(board, taille);
    }while(!fin);
    std::cout<<"Fin du jeu !"<<std::endl;
    // if(j=='X')
    //     std::cout<<"Les X ont gagnes !"<<std::endl;
    // else
    //     std::cout<<"Les O ont gagnes !"<<std::endl;
    return 0;
}
