#pragma once
#include "element.hpp"
#include "objetramassable.hpp"

class personnage : public element{
private :
  int _points;
  std::string _nom;

public:
  personnage(position_t const & position, taille_t const & taille, std::string const & nom);
  std::string tostring() const;
  void rammaser(objetramassable const & obj);
};

