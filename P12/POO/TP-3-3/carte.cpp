#include "carte.hpp"
#include <iostream>

carte::carte() : _taille(0,0){}

void carte::afficherpersonnages() const {
  std::cout<<_taille.tostring()<<"\n";
  for(personnage const & p : _personnages) {
    std::cout<<p.tostring()<<"\n";
  }
}

bool carte::emplacementlibre(position_t const &position,
                             taille_t const &taille) const {
  element elem(position, taille);
  if (position.x() < 0 or position.y() < 0 or
      position.x() + taille.largeur() > _taille.largeur() or
      position.y() + taille.hauteur() > _taille.hauteur())
    return false;

  for (auto const &p : _personnages) {
    if (intersectionelements(p, elem))
      return false;
  }
  for (auto const &obs : _obstacles) {
    if (intersectionelements(obs, elem))
      return false;
  }
  for (auto const &obj : _objetramassables) {
    if (intersectionelements(obj, elem))
      return false;
  }
  return true;
}
