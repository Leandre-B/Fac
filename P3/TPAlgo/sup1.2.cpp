#include <iostream>

int somme(int n){
    if(n<10) return n;
    else return(somme(n/10)+n%10);
}

int superSomme(int n){
    if(n<10) return n;
    else return superSomme(somme(n));
}

int main(){
    int n;
    std::cout<<"Entrez un nombre positif: ";
    std::cin>>n;
    std::cout<<"Somme des chiffres de n : "<<somme(n)<<std::endl
              <<"Et la super somme : "<<superSomme(n)<<std::endl;
}
