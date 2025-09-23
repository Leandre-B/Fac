#include <iostream>
#include <string>
#include <array>

#include<cmath> //sqrt pow
//============== DEF PILE =================
struct Pile{
    float* p;
    uint taille=0;
    uint tMax=0;
};



void init_pile(Pile & p, const uint & t){
    p.p = new float [t];
    p.tMax=t;
}

void empiler(Pile & p, const float & n){
    if(p.tMax!=p.taille){
        ++p.taille;
        p.p[p.taille-1]=n;
    }else
        std::cout<<"Pile Pleine\n";
}

void depiler(Pile & p){
    if(p.taille>0) {
        --p.taille;
    }else
        std::cout<<"La pile est déjà vide\n";
}

float lireSommet(Pile & p){
    if(p.taille>0)
        return p.p[p.taille-1];
    else{
        std::cout<<"Pile vide, '0' est retourné\n";
        return 0;
    }
}
//============== FIN DEF PILE =================


struct tabString{
    std::array<std::string, 100> t;
    uint taille=0;
};

void entrerExpression(tabString & expression){
    std::cout<<"Entrer l'expression element par element (entre chaine vide pour arreter): \n";
    std::string elem;
    do{

        std::getline (std::cin,elem);
        if(elem!=""){
            ++expression.taille;
            if(elem=="PI")
                expression.t[expression.taille-1]="3.14159";
            else
                expression.t[expression.taille-1]=elem;
        }

    }while(elem!="");
}

void afficherExpression(const tabString & expression){
    for(uint i=0; i<expression.taille; ++i){
        std::cout<<expression.t[i]<<" ";
    }
    std::cout<<"\n";
}

bool estSymbole(std::string s){
    return(s=="+" or s=="-" or s=="*" or s=="/" or s=="^" or s=="RAC");
}

float calcul_binaire (float elem2, float elem1, std::string symb){
    float result;
        if(symb== "+"){
            result = elem2+elem1;
        }else if(symb== "-"){
            result = elem2-elem1;
        }
        else if(symb== "*"){
            result = elem2*elem1;
        }
        else if(symb== "/"){
            result = elem2/elem1;
        }
        else if(symb== "^"){
            result = std::pow(elem2,elem1);
        }
        else{
            std::cout<<"Mavaise expression \""<<elem2<<" "<<symb<<" "<<elem1<<"\"\n";
            result = 0;
        }
    return result;
}

float calcul_unaire(float elem, std::string symb){
    float result;
    if(symb== "RAC"){
            result = std::sqrt(elem);
        }
        else{
            std::cout<<"Mavaise expression \""<<elem<<" "<<symb<<"\"\n";
            result = 0;
        }
    return result;
}
bool estOpeUnaire(std::string s){
    return (s=="RAC");
}

float evaluation(tabString expression){
    Pile p;
    init_pile(p,100);


    for(uint i=0; i<expression.taille; ++i){
        if(!estSymbole(expression.t[i])){
            empiler(p,std::stof(expression.t[i]));
        }else{
            float elem1 = lireSommet(p);
            depiler(p);
            if(!estOpeUnaire(expression.t[i])){
                float elem2 = lireSommet(p);
                depiler(p);
                empiler(p,calcul_binaire(elem2, elem1, expression.t[i]));
            }else{
                empiler(p,calcul_unaire(elem1, expression.t[i]));
            }

        }
    }
    float result = lireSommet(p);
    depiler(p);
    return result;
}

int main(){

    tabString expression;
    entrerExpression(expression);
    afficherExpression(expression);
    std::cout<<evaluation(expression)<<std::endl;


    return 0;
}