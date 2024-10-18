#include <iostream>

int main()
{

    int nb1, nb2;

    std::cout<< "Entrez un entier : ";
    std::cin>> nb1;
    std::cout<< "Entrez un autre entier : ";
    std::cin>> nb2;
    std::cout<< "Le produit de : " << nb1 <<" par " << nb2 << " est : "<< nb1*nb2 << std::endl;

    return 0;
}
