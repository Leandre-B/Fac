#include <iostream>


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

int main(){
    Arbre arb = construireArbre();
    affPrefix(arb);te

    return 0;
}