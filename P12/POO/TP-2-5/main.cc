#include "grille.hh"
#include <iostream>
#include <string>

int main() {

  Grille grille(10, 10);
  grille.ajouterStructure(Structure::OscillateurCroix, 5, 5);
  grille.afficher();
  std::string s = "";
  while (s == "") {
    std::getline(std::cin, s);
    Grille resultat(10, 10);
    grille.evolution(resultat);
    grille = resultat;
    grille.afficher();
  }
  return 0;
}
