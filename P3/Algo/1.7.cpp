#include <iostream>
#include <cmath>

float fct(float x){
    return 4*x*(4*x*(3*x-1)-8)-1;
}
float fct2(float x){
    return x*x+2*x-1;
}

float recherche0(float d, float f){
    float m=(d+f)/2;
    // std::cout<<"f("<<m<<")="<<fct(m)<<std::endl;
    if((fct(m))==0 or (f-d)<0.001) return m;
    else{
        if(fct(m)*fct(d)>0)return recherche0(d,m);
        else return recherche0(m,f);
    }
}

void dessinFct(){
    float pres=0.05;
    for(float i=6; i>=-5;i-=pres){
        for(float j=-1;j<=1.5;j+=0.01){
            if(std::abs(fct(j)-i)<0.1) std::cout<<'*';
            else if(std::abs(i)<0.02 or std::abs(j)<0.005)std::cout<<'*';
            else std::cout<<' ';
        }
        std::cout<<std::endl;
    }
}

int main(){

    float d = -10;
    float f=10;
    std::cout<<recherche0(d,f)<<std::endl;

    //marche po :(
    // d=-0.5;
    // f=0.8;
    // std::cout<<recherche0(d,f)<<std::endl;

    d=0.5;
    f=2;
    std::cout<<recherche0(d,f)<<std::endl;

    // dessinFct();

    return 0;
}
