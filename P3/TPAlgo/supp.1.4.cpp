#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

const int NBMAX = 20;
using TabInt = std::array<int, NBMAX>;



void genTab(TabInt & tab, int n){
    if(n>0){
        tab[n-1]=rand()%20 +1;
        // std::cout<<"n= "<<n<<" tab[n-1]="<<tab[n-1]<<std::endl;
        genTab(tab, n-1);
    }
}

void affTab(TabInt tab, int n){
    if(n>0){
        affTab(tab, n-1);
        std::cout<<tab[n-1]<<" ";
    }
}


void separation(int p,TabInt tabOrigin, int n, TabInt & tabGauche, int & tailleTabGauche,TabInt & tabDroit, int & tailleTabDroit){
    if(n>0){

        if(tabOrigin[n-1]>=p){
            tabDroit[tailleTabDroit]=tabOrigin[n-1];
            ++tailleTabDroit;
        }else{
            tabGauche[tailleTabGauche]=tabOrigin[n-1];
            ++tailleTabGauche;
        }

        separation(p, tabOrigin, n-1, tabGauche, tailleTabGauche,tabDroit, tailleTabDroit);
    }
}

int kieme(int k,TabInt tab, int n){

    int nTabD=0;
    int nTabG=0;
    TabInt tabD, tabG;

    separation(tab[n-1], tab, n-1, tabG, nTabG,tabD, nTabD);

    if(nTabG==k-1) return tab[n-1];
    else{
        if(nTabG>k-1) return kieme(k,tabG, nTabG);
        else return kieme(k-nTabG-1,tabD,nTabD);
    }
}

int main(){
    std::srand(std::time(nullptr));
    int n;
    TabInt tab;


    std::cout<<"Combien de val voulez_vous ajouter dans le tableau ? "<<std::endl;
    std::cin>>n;

    genTab(tab, n);
    std::cout<<"Tableau genere : ";
    affTab(tab,n);
    std::cout<<std::endl;

    for(int i= 1;i<=n;++i){
        std::cout<<"Plus petit num "<<i<<" : "<<kieme(i,tab,n)<<std::endl;
    }
    return 0;
}
