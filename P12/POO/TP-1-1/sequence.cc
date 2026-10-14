#include "sequence.hh"
#include <iostream>

void sc_initialiservide(Sequence & s) {
    s.taille = 0;
}

void sc_ajouter(Sequence& s, const Couleur & c){
    s.tab[s.taille] = c;
    s.taille++;
}

void sc_copier(Sequence & s1, const Sequence & s2) {
    s1 = s2;
}

Couleur sc_acces(const Sequence & s, indicesequence i){
    return s.tab[i];
}

void sc_afficher(const Couleur & c){
    switch (c) {
        case Couleur::Bleu: std::cout<<"bleu"; break;
        case Couleur::Jaune: std::cout<<"jaune"; break;
        case Couleur::Rouge: std::cout<<"rouge"; break;
        case Couleur::Vert: std::cout<<"vert"; break;
    }
}

void sc_afficher(const Sequence & s ) {
    for(indicesequence i = 0; i<s.taille; ++i){
        sc_afficher(s.tab[i]);
        std::cout<<" ";
    }
}

void sc_vider(Sequence & s) {
    s.taille = 0;
}

bool sc_comparer(const Sequence & s1, const Sequence & s2) {
    if(s1.taille != s2.taille) return false;
    for(indicesequence i = 0; i < s1.taille; ++i) {
        if(sc_acces(s1, i) != sc_acces(s2, i))
            return false;
    }
    return true;
}
