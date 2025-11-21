#include <iostream>
#include <cmath>

float racineDicho(float x, float e, float d, float f){
    float rac=((f+d)/2);//UNE MOYENNE C'EST +++++ !!!!!!!! PAS -----

    if(std::abs((rac*rac)-x)<e) return (rac);
    else if(rac*rac>x) return racineDicho(x,e,d,rac);
    else return racineDicho(x,e,rac,f);
}

float racineHeron(float x, float e,float u){
    if(std::abs((u*u)-x)<e) return u;
    else return(racineHeron(x,e,(1/2.0)*(u+(x/u))));
}

int main(){

        float e=0.01;
        float x;

        std::cout<<"Entrer le nombre dont vous-voulez trouver la racine carré : ";
        std::cin>>x;
        std::cout<<"Méthode dicho : Racine("<<x<<")="
                 <<racineDicho(x,e,0,x) //oblige d'aller de 0 à x  à cause de x=1;
                 <<std::endl;


        float u = x/2; //on essaye de prendre qlq proche de racine(x)
        std::cout<<"Méthode Heron : Racine("<<x<<")="
                 <<racineHeron(x,e,u)
                 <<std::endl;

    return 0;
}
