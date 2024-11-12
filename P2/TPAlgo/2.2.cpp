#include <iostream>
#include <array>
#include <math.h>

const int TAILLE = 150;
using TabAges  = std::array<int, TAILLE>;

void  init(TabAges  & age){
    for(int i = 0;i<TAILLE;++i){
        age[i]= 0;
    }
}

void saisie(TabAges & tabAge){
    int age=0;
    std::cout<<"Saissiez les ages (-1 pour arreter la saisie)"<<std::endl;
    while(age!=-1){
        std::cin>>age;
        ++tabAge[age];
    }
}

void affTab(TabAges age){
    for(int i = 0;i<TAILLE;++i){
        if(age[i]!=0)
            std::cout<< "Nb "<<i<<" ans : "<<age[i]<<std::endl;
    }
}

void regroupe (TabAges age1, TabAges age2, TabAges & age3){
    for(int i=0;i<150;++i){
        age3[i]=age1[i]+age2[i];
    }
}

float moyenne(TabAges age){
    float nbAge = 0;
    float somme = 0;
    for(int i = 0;i<150;++i){
        if(age[i]!=0){
            somme +=i*age[i];
            nbAge+=age[i];
        }
    }
    return (somme/nbAge);
}

float variance(TabAges age){
    float moy=moyenne(age);
    float nbAge=0;
    float somme=0;
    for(int i = 0;i<150;++i){
        if(age[i]!=0){
            somme+=((i-moy)*(i-moy));
            nbAge+=age[i];
        }
    }
    return((1.0/nbAge)*somme);
}

float ecartType(TabAges age){
    return sqrt(variance(age));
}

float mediane(TabAges age){
    int nbVal = 0;
    int indMed=0;
    for(int i = 0;i<150;++i){
        nbVal+=age[i];
    }
    if(nbVal%2==0){

        int valBefMed=0;
        int valAftMed=0;
        indMed=age[0];
        //j'ai honte...
        while(indMed<((nbVal/2))){
            ++valBefMed;
            indMed +=age[valBefMed];
        }
        indMed=age[0];
        while(indMed<((nbVal/2)+1)){
            ++valAftMed;
            indMed +=age[valAftMed];
        }

        return ((valAftMed+valBefMed)/2.0);

    }else{
        int i = 0;
        indMed+=age[i];
        while(indMed<((nbVal+1)/2)){
            ++i;
            indMed +=age[i];
        }
        return (i);
    }
}

int main(){

    TabAges age1, age2,age3;

    init (age1);
    init (age2);
    init(age3);

    // saisie(age1);
    // saisie(age2);

    // regroupe(age1,age2,age3);
    saisie(age3);
    affTab(age3);

    std::cout<<"moy age3  : "<<moyenne(age3)<<std::endl
             <<"var age3 : "<<variance(age3)<<std::endl
             <<"ecart type age3 : "<<ecartType(age3)<<std::endl
             <<"ecart mediane age3 : "<<mediane(age3)<<std::endl;
    return 0;
}

