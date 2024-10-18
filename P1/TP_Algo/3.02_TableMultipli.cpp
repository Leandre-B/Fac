#include <iostream>

int main(){

    float x;
    std::cout<<"Entrer un nombre : ";
    std::cin>>x;

    for (int i = 1;i<=10;++i){
        std::cout<<x<<"x"<<i<<"="<<x*i<<std::endl;
    }
    return 0;
}
