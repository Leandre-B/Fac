#pragma once
#include "element.hh"

class objetramassable :public element {
private :
  int _points;
public:
  objetramassable(position_t const & position, taille_t const & taille, int points);
  int getPoints() const;
  std::string tostring() const;

};

