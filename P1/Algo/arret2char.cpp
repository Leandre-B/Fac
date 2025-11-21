#include <iostream>

int main(){

    char car,tempCar;

    std::cout<<"Entrer un caratère : ";
    std::cin>>car;

    do{
        tempCar=car;
        std::cout<<"Entrer un caratère : ";
        std::cin>>car;

    }while(tempCar!=car);

    std::cout<<"STOP - Vous avez saisie 2 fois le même caratère à la suite ! (le "<<car<<")."<<std::endl;

    return 0;
}
