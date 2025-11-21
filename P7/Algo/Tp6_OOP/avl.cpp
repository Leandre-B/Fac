#include "avl.h"

#include <iostream>

/*
int hauteur(Arbre a){
    if(a==nullptr)
        return -1;
    else
        return a->hauteur;
}

// maj de la hauteur de l'arbre de racine a
// à partir de ses sous-arbres
int majHauteur(Arbre a){
    if(a==nullptr) return -1;
        a->hauteur = 1 + std::max(majHauteur(a->sag),majHauteur(a->sad));
    return a->hauteur;
}

void rotationDroite(Arbre & a){
    Noeud* b=a->sag;
    Noeud* c=b->sad;

    b->sad = a;
    a->sag = c;

    a=b;

}

void rotationGauche(Arbre & a){
    Noeud* b=a->sad;
    Noeud* c=b->sag;

    b->sag = a;
    a->sad = c;

    a=b;
}

void rotationGaucheDroite(Arbre & a){
    rotationGauche(a->sag);
    rotationDroite(a);
}

void rotationDroiteGauche(Arbre & a){
    rotationDroite(a->sad);
    rotationGauche(a);
}

//suppose que les sous arbres de a sont équilibrés
void reequilibre(Arbre & a){
    int fact_a = hauteur(a->sad) - hauteur(a->sag);
    if(fact_a==-2){
        int fact_sag = hauteur(a->sag->sad) - hauteur(a->sag->sag);
        if(fact_sag==-1   or fact_sag==0)
            rotationDroite(a);
        else if(fact_sag==1)
            rotationGaucheDroite(a);
        //majHauteur(a);

    }else if(fact_a==2){
        int fact_sad = hauteur(a->sad->sad) - hauteur(a->sad->sag);
        if(fact_sad==1 or fact_sad==0)
            rotationGauche(a);
        else if(fact_sad==-1)
            rotationDroiteGauche(a);
        //majHauteur(a);
    }
    majHauteur(a);
}



*/

void Avl::aff(NoeudAVL* n){
    if(n!=nullptr){
        aff(n->getSag());
        std::cout<<"Val : "<<n->getElem()<<" Hauteur : "<<n->getHauteur()<<"\n";
        aff(n->getSad());
    }
}

void Avl::aff(){
    aff(racine);
}

void Avl::genereAVL(Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouterAVL(t[i]);
        std::cout<<"Un avl a été généré\n";
    }
}


void Avl::ajouterAVL(Element e, NoeudAVL* n ){
    if(n==nullptr){
        n = new NoeudAVL(e);
    }
    else if(e<n->getElem())
            ajouterAVL(e,n->getSag());
    else
            ajouterAVL(e,n->getSag());
       
        //majHauteur(a);
        //reequilibre(a);

}

void Avl::ajouterAVL(Element e){
    ajouterAVL(e,this->racine);

}