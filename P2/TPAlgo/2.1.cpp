#include <iostream>
#include <array>

const int taillemax = 100;
using liste = std::array<float,taillemax>;


void saisie (liste & l , int & taille){ //l et taille resultat

    std::cout<<"Entrez nombre val : ";
    std::cin>>taille;

    for(int i = 0; i<taille; ++i)
        std::cin>>l[i];

}

void aff(liste l, int taille){

    std::cout<<l[0];
    for(int i = 1;i<taille;++i){
        std::cout<<";"<<l[i];
    }
}

bool trier(liste l, int taille){
    int i =1;
    while(i<taille){
        if(l[i-1]>l[i]){
            return false;
        }
        ++i;
    }
    return true;
}

float ecart (liste l, int taille){

    float ecartMax = 0;
    for(int i = 1;i<taille;++i){
        if(abs(l[i-1]-l[i])>ecart)
            ecartMax = abs(l[i-1]-l[i]);
    }
    return ecartMax;
}
float abs(float a){

}
int main(){

    liste l;
    int taille;

    saisie(l,taille);
    aff(l,taille);
    std::cout<<std::endl;

    trier(l,taille);
    if(trier(l,taille))
        std::cout<<"Tab triee par ordre croissant"<<std::endl;
    else
        std::cout<<"Tab pas triee par ordre croissant"<<std::endl;

    std::cout<<"Le plus grand ecart entre 2 nmbr consecutifs est : "<<ecart(l,taille);

    return 0;
}
