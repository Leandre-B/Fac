#include <iostream>
#include "sequence.hh"

int main() {
    Sequence a, b;

    sc_initialiservide(a); // 3
    sc_initialiservide(b);

    sc_ajouter(a, Couleur::Rouge); // 4
    sc_ajouter(a, Couleur::Bleu);
    sc_ajouter(a, Couleur::Rouge);
    sc_ajouter(a, Couleur::Vert);
    sc_copier(b, a); // Copie a dans b // 5
    sc_afficher(sc_acces(a, 0)); std::cout << "\n"; // 6 et 7
    for (indicesequence i=0; i<a.taille; ++i) {
        sc_afficher(sc_acces(a,i));
        std::cout << " ";
    }

    std::cout << "\n";
    sc_vider(a); // 8
    std::cout << "A: "; sc_afficher(a); std::cout << "\n"; // 9
    std::cout << "B: "; sc_afficher(b); std::cout << "\n";
    std::cout << sc_comparer(a,b) << "\n"; // 0
    sc_copier(a,b);
    std::cout << sc_comparer(a,b) << "\n";

    return 0;
}
