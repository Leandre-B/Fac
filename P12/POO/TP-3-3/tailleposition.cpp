#include "tailleposition.hpp"

position_t::position_t(coordonnee x, coordonnee y) : _x(x), _y(y){}
position_t::position_t(const position_t & p) : _x(p._x), _y(p._y){}

coordonnee position_t::x() const {return _x;}
void position_t::setx(coordonnee x){_x=x;}

coordonnee position_t::y() const {return _y;}
void position_t::sety(coordonnee y){_y=y;}

bool position_t::comparaison (const position_t & pos) const{
  return _x == pos._x && _y == pos._y;
}

std::string position_t::tostring() const {
  return ("("+ std::to_string(_x) + "," + std::to_string(_y) + ")");
}




taille_t::taille_t(coordonnee l, coordonnee h) : _largeur(l), _hauteur(h){}

coordonnee taille_t::largeur() const {return _largeur;}
void taille_t::setlargeur(coordonnee l){_largeur = l;}

coordonnee taille_t::hauteur() const {return _hauteur;}
void taille_t::sethauteur(coordonnee h){_hauteur = h;}

bool taille_t::comparaison (const taille_t & pos) const {
  return _largeur == pos._largeur && _hauteur == pos._hauteur;
}

std::string taille_t::tostring() const {
  return ("[" + std::to_string(_largeur) + "," + std::to_string(_hauteur) + "]");
}

