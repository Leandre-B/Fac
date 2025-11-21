#include <iostream>

int main(){

    int n,nbFibo=1,Un1=0,Un2=1;
    std::cout<<"Entrez les n premiers nombres de la suite de fibonacci que vous voulez afficher : ";
    std::cin>>n;

    for(int i=1;i<=n;++i){
        // std::cout<<nbFibo<<" ";
        nbFibo=Un1+Un2;
        Un1=Un2;
        Un2=nbFibo;
    }

    if(n%2==0){
        for(int lgn = 1 ;lgn<=nbFibo;++lgn){
            for(int col=1;col<=Un1+nbFibo;++col){
                std::cout<<"O";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}
