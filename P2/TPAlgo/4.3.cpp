#include <iostream>
#include <array>
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

    return false;
}

char changeJ(char j){
    if(j=='X')
        return 'O';
    return 'X';
}

void jouer(tab & board, int taille, char j){
    // int col, lign;
    std::string c;
    do{
        std::cout<<"Entrez case (ex:B1) : ";
        std::cin>>c;

        if( (int(c[1])-48<=0 or int(c[1])-48>taille or int(c[0])-64<=0 or int(c[0])-64>taille or board[int(c[1])-48-1][int(c[0])-64-1]!=' '))
            std::cout<<"Valeures incorrectes : veuillez reessayer."<<std::endl;

    }while((int(c[1])-48<=0 or int(c[1])-48>taille or int(c[0])-64<=0 or int(c[0])-64>taille or board[int(c[1])-48-1][int(c[0])-64-1]!=' '));

    board[int(c[1])-48-1][int(c[0])-64-1]=j;
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
    if(j=='X')
        std::cout<<"Les X ont gagnes !"<<std::endl;
    else
        std::cout<<"Les O ont gagnes !"<<std::endl;
    return 0;
}
