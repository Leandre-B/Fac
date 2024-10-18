#include <iostream>
#include<cmath>

int main(){

    float a,b,c,delta,x1,x2;

    std::cout<<"Donner coef a, b et c : ";
    std::cin>>a>>b>>c;

    delta=(b*b -4 *a*c);
    if(delta>0){
        std::cout << "L equation a deux racine reels :"
        <<"x1="<<((-b +sqrt(delta))/(2*a))<<std::endl
        <<"x2="<<(-b -sqrt(delta))/(2*a)<<std::endl;;
    }
    if(delta>0){
        std::cout << "L equation a deux racine complexes :" << std::endl
        <<"x1="<<((-b)/(2*a)) <<" + i("<<((-sqrt(delta))/(2*a))<<")"<<std::endl
        <<"x2="<<((-b)/(2*a)) <<" + i("<<((sqrt(delta))/(2*a))<<")"<<std::endl;;
    }else{
        std::cout << "L equation a une racine reel :"
        <<"x1="<<((-b)/(2*a))<<std::endl;;
    }


    return  0;
}