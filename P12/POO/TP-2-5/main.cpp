#include <iostream>
#include "grille.hpp"
using namespace std;

int main() {

  Grille grille(10, 15);
  grille.vider();
  std::cout<<grille.vivante(0,0)<<"\n";
  grille.generer(9,14);
  std::cout<<grille.vivante(0,0)<<"\n";

  grille.afficher();
  return 0;
}
