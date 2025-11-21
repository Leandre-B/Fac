#pragma once
using Element = int;

class NoeudAVL{
    private:
    Element elem;
    NoeudAVL* sag;
    NoeudAVL* sad;
    int hauteur; //hauteur de l'arbre dont il est la racine

    public:
    NoeudAVL(Element e):elem(e), sag(nullptr), sad(nullptr), hauteur(0) {};
    Element getElem() {return elem;};
    NoeudAVL* getSag(){return sag;};
    NoeudAVL* getSad(){return sad;};
    int getHauteur() {return hauteur;};
};

using uint = unsigned int;

class Avl {

    private: 
        NoeudAVL* racine=nullptr;
        void aff(NoeudAVL *);
        void ajouterAVL(Element e);
    
    public:
        void aff();
        void genereAVL(Element* t, uint n);
        void ajouterAVL(Element e, NoeudAVL *);

};