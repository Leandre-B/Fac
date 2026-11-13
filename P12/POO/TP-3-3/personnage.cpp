#include "personnage.hh"

personnage::personnage(position_t const & position, taille_t const & taille, std::string const & nom) :
                                                                                                     element(position, taille), _points(0), _nom(nom)
{

}

std::string personnage::tostring() const{
  return element::tostring() + " " + std::to_string(_points) + "pts " + _nom;
}

void personnage::ramasser(objetramassable const & obj) {
  _points += obj.getPoints();
}
