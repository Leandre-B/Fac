#include <iostream>
#include <queue>

struct Noeud{
    int elem;
    Noeud* fils_aine;
    Noeud* frere_droit;
};

using Arbre = Noeud*;

Noeud* construireNoeud(int elem, Noeud* fils_aine, Noeud* frere_droit){
    Noeud* noeud = new Noeud;
    noeud->elem = elem;
    noeud->fils_aine = fils_aine;
    noeud->frere_droit = frere_droit;

    return noeud;
}

Arbre construireArbre(){
    Noeud* v = nullptr;
    Arbre L = construireNoeud(12,v,v);
    Arbre K = construireNoeud(11,v,L);
    Arbre J = construireNoeud(10,v,K);
    Arbre I = construireNoeud(9,v,J);
    Arbre G = construireNoeud(7,I,v);
    Arbre F = construireNoeud(6,v,v);
    Arbre H = construireNoeud(8,v,v);
    Arbre E = construireNoeud(5,H,F);
    Arbre D = construireNoeud(4,v,v);
    Arbre C = construireNoeud(3,G,D);
    Arbre B = construireNoeud(2,E,C);
    Arbre A = construireNoeud(1,B,v);

    return A;
}

//C'est le meme parcours prefixe OMG
void affPrefix(Arbre arb){
    if(arb!=nullptr){
        std::cout<<arb->elem<<" ";
        affPrefix(arb->fils_aine);
        affPrefix(arb->frere_droit);
    }
}

//Affichage postfixe arbre n aire = infixe arbre binaire OMG !!!!!
void affPostfix (Arbre arb){
    if(arb!=nullptr){
        affPostfix(arb->fils_aine);
        std::cout<<arb->elem<<" ";
        affPostfix(arb->frere_droit);
    }
}

//Pas vraiment de sens pour un arbre n aire
void affInfixe(Arbre arb){
    std::cout<<"Pas vraiment de sens pour un arbre n aire.";
}


//Parcours en largeur LETS GOOO
//========================
void affFreres(Arbre arb, std::queue<Arbre> & file){
    if(arb!=nullptr){
        std::cout<<arb->elem<<" ";
        if(arb->fils_aine!=nullptr) file.push(arb->fils_aine);
        affFreres(arb->frere_droit, file);
    }
}

void parcoursLargeur(Arbre arb){
    std::queue<Arbre> file;
    file.push(arb);
    while(!file.empty()){
        Arbre copie = file.front();
        file.pop();
        affFreres(copie, file);
    }
}
//========================


int main(){
    Arbre arb = construireArbre();
    std::cout<<"Prefixe arbre n aire : "; affPrefix(arb); std::cout<<"\n";
    std::cout<<"Postfixe arbre n aire : "; affPostfix(arb); std::cout<<"\n";
    std::cout<<"Infixe arbre n aire : "; affInfixe(arb); std::cout<<"\n";
    std::cout<<"Parcours largeur arbre n aire : "; parcoursLargeur(arb); std::cout<<"\n";

    return 0;
}