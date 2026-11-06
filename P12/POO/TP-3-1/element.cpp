#include "element.hpp"

element::element(position_t const & position, taille_t const & taille) :
                                                         _position(position), _taille(taille)
{
}


std::string element::tostring() const {
  return _position.tostring() + _taille.tostring();
}

bool element::contientposition(position_t const & position) const{
  return (
      position.x() >= _position.x() && position.x() <= _position.x() + _taille.largeur() &&
      position.y() >= _position.y() && position.y() <= _position.y() + _taille.hauteur()
  );
}
