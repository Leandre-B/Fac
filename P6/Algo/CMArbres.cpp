#include <iostream>
#include <string>
#include <stack>
#include <queue>

using Element = char;

struct Noeud{
    Element e;
    Noeud* sag=nullptr;
    Noeud* sad=nullptr;
};

using Arbre =  Noeud*;


Arbre creeArbre (const Element & e, const Arbre & gauche, const Arbre & droit){
    Arbre A = new Noeud;
    A->e = e;
    A->sag = gauche;
    A->sad = droit;

    return A;
}


//====CREATION ARBRES====

//1ere façon

Arbre construireArbre1(){
    Arbre v = nullptr;

    Arbre N = creeArbre('N',v,v);

    Arbre L = creeArbre('L',v,v);
    Arbre M = creeArbre('M',v,v);

    Arbre J = creeArbre('J',v,v);
    Arbre K = creeArbre('K',v,v);

    Arbre H = creeArbre('H',v,v);
    Arbre I = creeArbre('I',v,v);

    Arbre F = creeArbre('F',L,M);
    Arbre G = creeArbre('G',N,v);

    Arbre D = creeArbre('D',H,I);
    Arbre E = creeArbre('E',J,K);

    Arbre C = creeArbre('C',F,G);
    Arbre B = creeArbre('B',D,E);
    Arbre A = creeArbre('A',B,C);
    
    return A;
}


//====FIN CREATINI ARBRES====

//====AFFICHAGE ARBRES====

//===Recursifs===
void prefixeRecur(Arbre arb){
    if(arb==nullptr)
        std::cout<<'v';
    else{
        std::cout<<'('<<arb->e<<",";
        prefixeRecur(arb->sag);
        std::cout<<',';
        prefixeRecur(arb->sad);
        std::cout<<')';
    }
}

void infixeRecur(Arbre arb){
    if(arb!=nullptr){
        infixeRecur(arb->sag);
        std::cout<<arb->e<<" ";
        infixeRecur(arb->sad);
    }
}

void postfixeRecur(Arbre arb){
    if(arb!=nullptr){
        postfixeRecur(arb->sag);
        std::cout<<arb->e<<" ";
        postfixeRecur(arb->sad);
    }
}
//===Fin Recursifs===


//===Itératif===

void prefixeIte(Arbre arb){
    std::stack<Arbre> pile;
    pile.push(arb);
    while(!pile.empty()){
        Arbre aux=pile.top();
        pile.pop();
        std::cout<<aux->e;
        if(aux->sad!=nullptr)
            pile.push(aux->sad);
        if(aux->sag!=nullptr)
            pile.push(aux->sag);
    }
}

void infixeIte(Arbre arb){
    std::stack<Arbre> pile;
    pile.push(arb);
    do{

        if(arb->sag!=nullptr)
            pile.push(arb->sag);

        std::cout<<pile.top()->e;
        pile.pop();

        if(arb->sad!=nullptr)
            pile.push(arb->sad);
    }while(!pile.empty());
}

//===Fin Itératif===

//====Fin Affichage====
void affichage(void(*funct)(Arbre), Arbre arb, std::string name){
    std::cout<<name<<" :\n";
    funct(arb);
    std::cout<<"\n\n";
}
//====FIN AFFICHAGE ARBRES====

int main(){

    Arbre arb = nullptr;
    arb = construireArbre1();

    //affichage(prefixeRecur,arb, "Préfixe");
    affichage(infixeRecur,arb, "Infixe");
    //affichage(postfixeRecur,arb, "Postfixe");
    //affichage(prefixeIte,arb,"Prefixe Ite");
    affichage(infixeIte,arb,"Infixe Ite");

    return  0;
}