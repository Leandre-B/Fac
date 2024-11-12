#include <iostream>
#include <string>
#include <array>
using tab = std::array<int,100>;

void saisie(tab & liste, int & n){
    std::cout<<"saisir nbr d'éléments :";
    std::cin>>n;
    for(int i= 0;i<n;++i){
        std::cin>>liste[i];
    }
}

void aff(tab liste, int n){
    for(int i= 0;i<n;++i){
        std::cout<<liste[i]<<" ";
    }
}

void uv(tab liste, tab & U, tab & V, int & nbU, int & nbV, int n){
    int x;
    std::cout<<"Choisir pivot : ";
    std::cin>>x;
    nbU=0;
    nbV=0;
    while((nbU+nbV)<n){
        if(liste[nbU+nbV]<x){
            ++nbV;
            V[nbV-1]=liste[nbU+nbV-1];
        }if(liste[nbU+nbV]>=x){
            ++nbU;
            U[nbU-1]=liste[nbU+nbV-1];
        }
    }

}

void fusion(tab & t3, tab t1, tab t2, int & nt3, int nt1, int nt2){

    nt3 = nt1+nt2;
    int i1 = 0;
    int i2=0;
    for(int i3=0;i3<nt3;++nt3){
        if((nt2==i3) or ((nt1<i1) and t1[i1]<t2[i2])){ //si t2 fini etc..)
            t3[i3]=t1[i1];
            ++i1;
        }else{
            t3[i3]=t2[i2];
            ++i2;
        }
    }
}

int main()
{
    // tab liste,U,V,UV;
    // int n,nbU,nbV;
    // saisie(liste,n);
    // uv(liste,U,V,nbU,nbV,n);
    // aff(liste, n);
    // std::cout<<std::endl;
    // aff(U,nbU);
    // std::cout<<std::endl;
    // aff(V,nbV);
    // std::cout<<std::endl;

    tab t1,t2,t3;
    int nt1, nt2,nt3;

    saisie(t1,nt1);
    saisie(t2,nt2);
    fusion(t3,t1,t2,nt3,nt1,nt2);
    aff(t3,nt3);


    return 0;

}
