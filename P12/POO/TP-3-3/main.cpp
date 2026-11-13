#include "carte.hpp"
#include <iostream>
int main() {

  carte c;
  c.ajouterElement(obstacle(position_t(0, 0), taille_t(10, 10)));
  c.ajouterElement(obstacle(position_t(11, 11), taille_t(5, 7)));

  std::cout << c.emplacementlibre(position_t(20, 20), taille_t(2, 2)) << "\n";

  return 0;
}
