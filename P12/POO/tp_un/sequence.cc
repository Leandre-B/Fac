#include "sequence.hh"
#include <iostream>

void sc_initialiservide(Sequence & s) {
    s.taille = 0;
}

void sc_ajouter(Sequence & s, const Couleur & c) {
    // Pas de teste de taille à faire
    s.tab[s.taille] = c;
    ++s.taille;
}

// Copie s2 dans s1
void sc_copier(Sequence & s1, const Sequence & s2) {
    for(indicesequence i = 0; i<s2.taille; ++i)
        s1.tab[i] = s2.tab[i];
    s1.taille = s2.taille;
}

Couleur sc_acces(const Sequence & s, indicesequence i) {
    return s.tab[i];
}

void sc_afficher(const Couleur & c) {
    switch(c){
    case Couleur::Rouge : std::cout<<"rouge"; break;
    case Couleur::Bleu : std::cout<<"bleu"; break;
    case Couleur::Jaune : std::cout<<"jaune"; break;
    case Couleur::Vert : std::cout<<"vert"; break;
    }
}

void sc_vider(Sequence & s){
    s.taille = 0;
}

void sc_afficher(const Sequence & s){
    for(indicesequence i = 0; i<s.taille; ++i) {
        sc_afficher(sc_acces(s, i)); std::cout<<" ";
    }
}

bool sc_comparer(const Sequence & s1, const Sequence & s2) {
    bool b = true;

    if(s1.taille != s2.taille)
        b = false;

    indicesequence i = 0;
    while(b && i<s1.taille) {
        if(sc_acces(s1, i) != sc_acces(s2, i))
            b = false;
        ++i;
    }
    return b;
}

