#pragma once
#include "tailleposition.hpp"
#include <string>

/*
 * Represent un element rectangulaire
 */
class element {
private :
  // point en haut a gauche
  position_t _position;

  taille_t _taille;

public:
  element(position_t const & position, taille_t const & taille);

  position_t accesposition() const {return _position;}
  taille_t accestaille() const {return _taille;}
  std::string tostring() const;
  bool contientposition(position_t const & position) const;
};
