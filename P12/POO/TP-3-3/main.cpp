#include "carte.hh"
#include <iostream>
int main() {

  carte c(taille_t(30,30));
  c.ajouter(objetramassable(position_t(0, 0), taille_t(10, 10), 10));

  personnage p(position_t(0,11), taille_t(2, 2), "Pascal");

  std::cout<<p.tostring()<<"\n";
  c.ramassertout(p);
  std::cout<<p.tostring()<<"\n";

  return 0;
}
