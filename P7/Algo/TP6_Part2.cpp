#include <iostream>


using Element = int;

struct Noeud{
    Element elem;
    Noeud* sag;
    Noeud* sad;
    int hauteur;
};

using Arbre = Noeud*;

int hauteur(Arbre a){
    if(a==nullptr)
        return -1;
    else
        return a->hauteur;
}

//maj hauteur racine a à partir de ses sous-arbres
void majHauteur(Arbre a){
    if(a->sag !=nullptr and a->sad=!nullptr){
        if(a->sag->hauteur > a->sad->hauteur)
            a->hauteur = 1 + a->sag->hauteur;
        else
            a->hauteur = 1 + a->sad->hauteur;
    }
    else if(a->sag!=nullptr and a->sad==nullptr)
        a->hauteur = 1 + a->sag->hauteur;

    else if(a->sag==nullptr and a->sad!=nullptr)
        a->hauteur = 1 + a->sad->hauteur;

    else
        return 0;
}

void rotationDroite(Arbre & a){
    Noeud* b=a->sag;
    Noeud* c=b->sad;

    b->sad = a;
    a->sag = c;

    a=b;

}



int main(){


    return 0;
}