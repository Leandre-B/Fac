#pragma once
#include <cstddef>

enum class Couleur { Rouge, Bleu, Jaune, Vert };

using indicesequence = std::size_t;

struct Sequence {
    Couleur * couleurs;
    indicesequence taille;
};

void sc_initialiservide(Sequence & s);
void sc_ajouter(Sequence& s, const Couleur & c);
void sc_copier(Sequence & s1, const Sequence & s2);
Couleur sc_acces(const Sequence & s, indicesequence i);
void sc_afficher(const Couleur & c);
void sc_afficher(const Sequence & s );
void sc_vider(Sequence & s);
bool sc_comparer(const Sequence & s1, const Sequence & s2);