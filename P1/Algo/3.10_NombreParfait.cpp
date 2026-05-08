#include <iostream>

int main(){

    int min,max,somme;

    std::cout<<"Entrez la borne inférieure des nombres à vérifier : ";
    std::cin>>min;
    std::cout<<"Entrez la borne supérieur des nombres à vérifier : ";
    std::cin>>max;

    for(int j=min;j<=max;++j){
        somme=0;
        for(int i=1;i<=j;++i){
            if(j%i==0)
                somme=somme+i;
        }

        if(((somme)/2)==j)
            std::cout<<j<<" est un nombre parfait !"<<std::endl;

    }

    return 0;
}
