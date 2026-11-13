#pragma once
#include "element.hh"
#include "objetramassable.hh"

class personnage : public element{
private :
  int _points;
  std::string _nom;

public:
  personnage(position_t const & position, taille_t const & taille, std::string const & nom);
  std::string tostring() const;
  void ramasser(objetramassable const & obj);

  void deplacer(position_t const & pos) {
    _position.setx(pos.x());
    _position.sety(pos.y());
  }
};

