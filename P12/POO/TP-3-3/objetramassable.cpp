#include "objetramassable.hpp"

objetramassable::  objetramassable(position_t const & position, taille_t const & taille, int points) :
                                                                                                     element(position, taille), _points(points)
{
}

int objetramassable::getPoints() const {
  return _points;
}

std::string objetramassable::tostring() const {
  return "obj rms " + element::tostring() + " " + std::to_string(_points) + "pts";
}
