#include "obstacle.hpp"

obstacle::obstacle(position_t const & position, taille_t const & taille) :element(position, taille)
{}

std::string obstacle::tostring() const{
  return "obs " + element::tostring();
}
