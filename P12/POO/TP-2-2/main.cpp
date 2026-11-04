#include "sequence.hpp"
#include <iostream>

int main() {
  Sequence a;
  // a.afficher(a.acces(12)); //ERREUR !! Pas super robuste... >:(
  a.ajouter(Couleur::Rouge);
  a.ajouter(Couleur::Bleu);
  a.ajouter(Couleur::Rouge);
  a.ajouter(Couleur::Vert);
  Sequence b(a); // voir question 3
  a.afficher(a.acces(0)); std::cout << "\n";


  for (indicesequence i=0; i<a.taille(); ++i) {
    a.afficher(a.acces(i));
    std::cout << " ";
  }
  std::cout << "\n";
  a.vider();
  std::cout << "A: "; a.afficher(std::cout); std::cout << "\n"; // voir question 4
  std::cout << "B: "; b.afficher(std::cout); std::cout << "\n";
  std::cout << a.comparer(b) << "\n";
  a.copier(b); // voir question 5
  std::cout << a.comparer(b) << "\n";

  return 0;
}
