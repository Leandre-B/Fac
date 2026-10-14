#include "sequence.hh"
#include <iostream>

void sc_initialiservide(Sequence & s) {
    s.couleurs = nullptr;
    s.taille = 0;
}

void sc_ajouter(Sequence& s, const Couleur & c){
    Couleur* save = new Couleur[s.taille];
    for(int i=0; i<s.taille; ++i) {
        save[i] = s.couleurs[i];
    }

    delete [] s.couleurs;  s.couleurs = nullptr;
    s.taille++;
    s.couleurs = new Couleur[s.taille];

    for(int i=0; i<s.taille - 1; ++i) {
        s.couleurs[i] = save[i];
    }

    s.couleurs[s.taille -1] = c;
    delete [] save; save = nullptr;
}

void sc_copier(Sequence & s1, const Sequence & s2) {
    delete [] s1.couleurs; s1.couleurs = nullptr;
    s1.couleurs = new Couleur[s2.taille];
    s1.taille = s2.taille;
    for(int i=0; i<s1.taille; ++i) {
        s1.couleurs[i] = s2.couleurs[i];
    }

}

Couleur sc_acces(const Sequence & s, indicesequence i){
    return s.couleurs[i];
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
        sc_afficher(s.couleurs[i]);
        std::cout<<" ";
    }
}

void sc_vider(Sequence & s) {
    s.taille = 0;
    delete [] s.couleurs;
    s.couleurs = nullptr;
}

bool sc_comparer(const Sequence & s1, const Sequence & s2) {
    if(s1.taille != s2.taille) return false;
    for(indicesequence i = 0; i < s1.taille; ++i) {
        if(sc_acces(s1, i) != sc_acces(s2, i))
            return false;
    }
    return true;
}
