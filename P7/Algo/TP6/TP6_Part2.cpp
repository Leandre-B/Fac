#include <iostream>


using Element = int;

struct Noeud{
    Element elem;
    Noeud* sag;
    Noeud* sad;
    int hauteur; //hauteur de l'arbre dont il est la racine
};

using Arbre = Noeud*;

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


void ajouterAVL(Arbre & a, Element e){
    if(a==nullptr){
        a = new Noeud;
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


void aff(Arbre a){
    if(a!=nullptr){
        aff(a->sag);
        std::cout<<"Val : "<<a->elem<<" Hauteur : "<<a->hauteur<<"\n";
        aff(a->sad);
    }
}

void genereAVL(Arbre & a, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouterAVL(a,t[i]);
    }
}

int main(){
    Arbre a = nullptr;
    Element t1[] = {5 , 3 , 7 , 1 , 8 , 10 , 9};
    genereAVL(a, t1, 7);
    majHauteur(a);
    aff(a);
    std::cout<<"\n";

    return 0;   
}