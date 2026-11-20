#pragma once

using coord = short int;
#include <iostream>

class position {
private:
  coord _x;
  coord _y;

public:
  position(coord x, coord y) : _x(x), _y(y) {};
  position(position const &pos) : _x(pos._x), _y(pos._y) {};

  coord x() const { return _x; }
  coord y() const { return _y; }

  bool egale(position const &p) const { return (p._x == _x && p._y == _y); }
  void sortie_flux(std::ostream &flux) const {
    flux << "(" << _x << "," << _y << ")";
  }
};
