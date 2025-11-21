#include <iostream>

int main(){

    int n,facto;
    facto=1;
    std::cout<<"Entrer un nombre entier : ";
    std::cin>>n;
    
    for(int i=1;i<=n;++i){
        facto*=i;
    }
    std::cout << n << " factorielle est egal a : "<<facto<<std::endl;

    return 0;
}
