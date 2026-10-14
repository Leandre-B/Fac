#include <array>


using indicesequence = std::size_t;

enum class Couleur {
    Rouge,
    Bleu,
    Jaune,
    Vert
};

struct Sequence {
    std::array<Couleur, 100> tab;
    indicesequence taille;
};

void sc_initialiservide(Sequence & s);
void sc_ajouter(Sequence & s, const Couleur & c);

// Copie s2 dans s1
void sc_copier(Sequence & s1, const Sequence & s2);

Couleur sc_acces(const Sequence & s, indicesequence i);
void sc_afficher(const Couleur & c);
void sc_vider(Sequence & s);
void sc_afficher(const Sequence & s);
bool sc_comparer(const Sequence & s1, const Sequence & s2);
