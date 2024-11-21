#include <iostream>
#include <array>
using tab = std::array<std::array<char,100>,100>;

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
    for(int  j =0;j<taille;++j){
        for(int i = 0:i<taille-3;++i){
            if(//4 pions aligne verti (ou hori jsp)
        }
    }
}

char changeJ(char j){
    if(j=='X')
        return 'O';
    return 'X';
}

void jouer(tab & board, int taille, char j){
    int col, lign;
    do{
        std::cout<<"Entrez la col ou jouer : ";
        std::cin>>col;
        std::cout<<"Entrez la lign ou jouer : ";
        std::cin>>lign;

        if( col<=0 or col>taille or lign<=0 or lign>taille)
            std::cout<<"Valeures incorrectes : veuillez reessayer."<<std::endl;

    }while(col<=0 or col>taille or lign<=0 or lign>taille);

    board[lign-1][col-1]=j;
}

void aff(tab board, int taille){
    std::cout<<"----- Jeu -----"<<std::endl<<std::endl;
    for(int i = 0;i<taille; ++i){
        for(int j = 0;j<taille; ++j){
            if(j==0)
                std::cout<<board[i][j];
            else
                std::cout<<" | "<<board[i][j];
        }
        std::cout<<std::endl;
        if(i!=taille-1){
            for(int k = 0;k<taille;++k)
                std::cout<<"---";
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

    return 0;
}
