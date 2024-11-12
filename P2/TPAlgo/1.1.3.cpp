#include <iostream>

const int pres = 100;

float expo (float x){
    //initialisation à k=0
    double num = 1; //quand float a la place de double, renvoie "inf" -> parce que pres trop grande
    double deno = 1; //a l'air de fonctinner mais pas accurate
    float somme = 1 //=num/deno; //float et double semble bien fonctionner

    for(int k = 1;k<=pres;++k){
        num = num *x;
        // std::cout<<"num "<<num<<std::endl;
        deno = deno*k;
        // std::cout<<"deno "<<deno<<std::endl;
        somme = somme + (num/deno);
        // std::cout<<"somme "<<somme<<std::endl;
    }
    return somme;
}

float ln(float x){
    float fractPuiss = (x-1.0)/(x+1.0);
    float somme = fractPuiss;
    for(unsigned int k=1;k<=pres;++k){
        fractPuiss=fractPuiss *((x-1.0)/(x+1.0))*((x-1.0)/(x+1.0));
        // std::cout<<"fractPuiss (k = "<<k<<") = "<<fractPuiss<<std::endl;
        somme += (1.0/(2.0*k +1.0))* fractPuiss; //fractPuiss/(2.0*k +1.0)
        // std::cout<<"somme (k = "<<k<<") = "<<somme<<std::endl;
    }
    return (2*somme);
}

int main(){
    float expoX;
    float lnX;
    std::cin>>expoX;
    std::cout<<"exp("<<expoX<<")="<<expo(expoX)<<std::endl;

    std::cin>>lnX;
    std::cout<<"ln("<<lnX<<")="<<ln(lnX)<<std::endl;
}
