#include <iostream>

int main(){

    int nb1,nb2,ope,resultat;
    std::cout<<"Quel type d'opération voulez-vous effectuer ? (entrer le num correspondant)"<<std::endl
        <<"1 - Addition"<<std::endl
        <<"2 - Soustraction"<<std::endl
        <<"3 - Multiplication"<<std::endl;
    std::cin>>ope;
    std::cout<<"Entrez deux nombres : ";
    std::cin>>nb1>>nb2;

    if(ope==1){
        std::cout<<"Combien font "<<nb1<<"+"<<nb2<<" ? ";
        std::cin>>resultat;
        if(resultat!=(nb1+nb2))
            std::cout<<"Erreur, cela fait "<<nb1+nb2;
        else
            std::cout<<"Bravo !";
    }
    if(ope==2){
        std::cout<<"Combien font "<<nb1<<"-"<<nb2<<" ?" ;
        std::cin>>resultat;
        if(resultat!=(nb1-nb2))
            std::cout<<"Erreur, cela fait "<<nb1-nb2;
        else
            std::cout<<"Bravo !";
    }
    if(ope==3){
        std::cout<<"Combien font "<<nb1<<"x"<<nb2<<" ? ";
        std::cin>>resultat;
        if(resultat!=(nb1*nb2))
            std::cout<<"Erreur, cela fait "<<nb1*nb2;
        else
            std::cout<<"Bravo !";
    }

    return 0;
}