#pragma once

#include <iostream>
#include <string>
using coord = unsigned int;

class position {
private:
  coord _x;
  coord _y;

public:
  position(coord x, coord y) : _x(x), _y(y) {};

  coord x() const { return _x; };
  coord y() const { return _y; };

  void setX(coord x) { _x = x; };
  void setY(coord y) { _y = y; };

  std::string toString() const {
    return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
  };

  bool eqale(position const &p) const { return p._x == _x && p._y == _y; };
  bool differente(position const &p) const { return !eqale(p); };
};
