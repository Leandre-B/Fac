#include <iostream>
#include <array>


void aff(std::array<std::array<int, 20>, 20> tab, int n, int m){
    for(int i = 0;i<n;++i){

        if(i==0)
            for(int j = 0;j<m;++j){
                std::cout<<" "<<j<<" ";
            }
        else
            for(int j = 0;j<m;++j){
                std::cout<<"----";
            }

        std::cout<<std::endl;

        for(int j = 0;j<m;++j){
            if(j==0) std::cout<<"|";
            if(tab[i][j]<10)
                std::cout<<" "<<tab[i][j]<<" |";
            else
                std::cout<<tab[i][j]<<" |";
        }


        if(i==n-1){
            std::cout<<std::endl;
            for(int j = 0;j<m;++j){
                std::cout<<"----";
            }
        }
        std::cout<<std::endl;
    }
}

void remplir(std::array<std::array<int, 20>, 20> & tab, int x, int n,int m){
    if(x<n*m){
        tab[x/m][x%m]=x;
        remplir(tab, x+1,n,m);
    }
}

int main(){
    std::array<std::array<int, 20>, 20> tab;
    int n,m; //n lignes et m colonnes

    std::cout<<"Entrez le nombre de ligne de la matrice (n) : ";
    std::cin>>n;
    std::cout<<"Entrez le nombre de colonne de la matrice (m) : ";
    std::cin>>m;

    remplir(tab, 0,n,m);

    std::cout<<"Tableau numerote : "<<std::endl;
    aff(tab,n,m);

    return 0;
}
