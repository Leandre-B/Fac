#include <iostream>

void saisie(int & e){
    std::cout <<"Saisir e : ";
    std::cin>>e;
    if(e<=0) saisie(e);
}

void affichage(int & e){
    std::cout<<e<<" ";
    if(e!=1){
        if(e%2==0) e=e/2;
            else e=3*e+1;
        affichage(e);
    }

}

int main(){
    int e;
    saisie(e);
    affichage(e);
}
