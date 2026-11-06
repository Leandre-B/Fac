#include "carte.hpp"
#include <iostream>

carte::carte() : _taille(0,0){}

void carte::afficherpersonnages() const {
  std::cout<<_taille.tostring()<<"\n";
  for(personnage const & p : _personnages) {
    std::cout<<p.tostring()<<"\n";
  }
}
