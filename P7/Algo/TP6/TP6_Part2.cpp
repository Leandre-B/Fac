#include <iostream>
#include <ctime>
#include <cmath>

using Element = int;

struct NoeudAvl{
    Element elem;
    NoeudAvl* sag;
    NoeudAvl* sad;
    int hauteur; //hauteur de l'arbre dont il est la racine
};

using Avl = NoeudAvl*;

/*
 i *nt hauteur(Arbre a){
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
 */

int hauteur(Arbre a){
    if(a==nullptr)
        return -1;
    return a->hauteur;
}

void majHauteur(Arbre a){
    if(a!=nullptr)
        a->hauteur = 1 + std::max(hauteur(a->sag), hauteur(a->sad));
}

void rotationDroite(Avl & a){
    NoeudAvl* b=a->sag;
    NoeudAvl* c=b->sad;

    b->sad = a;
    a->sag = c;

    majHauteur(a);
    majHauteur(b);

    a=b;
}

void rotationGauche(Avl & a){
    NoeudAvl* b=a->sad;
    NoeudAvl* c=b->sag;

    b->sag = a;
    a->sad = c;

    majHauteur(a);
    majHauteur(b);

    a=b;
}

void rotationGaucheDroite(Avl & a){
    rotationGauche(a->sag);
    rotationDroite(a);
}

void rotationDroiteGauche(Avl & a){
    rotationDroite(a->sad);
    rotationGauche(a);
}

//suppose que les sous arbres de a sont équilibrés
void reequilibre(Avl & a){
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


void ajouterAVL(Avl & a, Element e){
    if(a==nullptr){
        a = new NoeudAvl;
        a->elem = e;
        a->sag=nullptr;
        a->sad=nullptr;
        a->hauteur = 0;
    }else{
        if(e<a->elem)
            ajouterAVL(a->sag, e);
        else if(e>a->elem)
            ajouterAVL(a->sad, e);
        else
            return;
        //majHauteur(a);
        reequilibre(a);
    }
}


void aff(Avl a){
    if(a!=nullptr){
        aff(a->sag);
        std::cout<<"Val : "<<a->elem<<" Hauteur : "<<a->hauteur<<"\n";
        aff(a->sad);
    }
}

void genereAVL(Avl & a, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouterAVL(a,t[i]);
    }
}

int main(){
    srand(time(nullptr));
    int n = 100000;
    int* t =new int[n];
    for(int i=0; i<n; ++n){
        t[i] = rand()%10000000;
    }

    return 0;
}