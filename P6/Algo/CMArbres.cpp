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


void affPile(std::stack<Arbre> pile){
    std::cout<<"Pile : \n";
    while(!pile.empty()){
        std::cout<<pile.top()->e;
        pile.pop();
    }
    std::cout<<"\n\n";
}


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
    if(arb!=nullptr){
        std::cout<<arb->e<<" ";
        prefixeRecur(arb->sag);
        prefixeRecur(arb->sad);
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
        postfixeRecur(arb->sad);
        std::cout<<arb->e<<" ";
    }
}
//jsp mdr
//
//void lageurRecur(Arbre arb){
//    if(arb!=nullptr){
//
//    }
//}
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

void infixeIte(Arbre arb){ //marche pas :(
    std::stack<Arbre> pile;
    pile.push(arb);
    while(!pile.empty()){
        if(pile.top()->sag!=nullptr)
        {
            pile.push(pile.top()->sag);
            //affPile(pile);
        }
        else
        {
            Arbre cur = pile.top();
            pile.pop();
            std::cout<<cur->e<<" ";
            if(cur->sad!=nullptr)
                pile.push(cur->sad);
        }
    }
}

void lageurIte(Arbre arb){
    //AVEC **QUEUE**
    std::queue<Arbre> file;
    file.push(arb);
    while(!file.empty()){
        if(file.front()->sag!=nullptr)
            file.push(file.front()->sag);
        if(file.front()->sad!=nullptr)
            file.push(file.front()->sad);
        std::cout<<file.front()->e<<" ";
        file.pop();
    }
}

//jsp test bête

//void prefixeRecur(Arbre arb){    
//    if(arb!=nullptr){             Ligne 1
//        std::cout<<arb->e<<" ";   Ligne 2
//        prefixeRecur(arb->sag);   Ligne 3 on push puis reviens ligne 1
//        prefixeRecur(arb->sad);   Ligne 4 on push puis reviens ligne 2
//    }                             Ligne 5 on pop, si l3->l2, si l4->l1  
//}
void ite(Arbre arb){ //marche pas :(
    int ligne=3;
    std::stack<Arbre> pile;
    pile.push(arb);

    while(!pile.empty()){
        if(pile.top()==nullptr){
            pile.pop();
            if(ligne==3) ++ligne;
            else if (ligne==4) ligne = 3;
        }
        else{
            std::cout<<pile.top()->e;
            if(ligne==3)
                pile.push(pile.top()->sag);
            else if(ligne==4)
                pile.push(pile.top()->sad);
            pile.pop();
        }
    }
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
    //affichage(lageurIte,arb, "Largeur Ite");
    //affichage(ite,arb,"Test ite");

    return  0;
}