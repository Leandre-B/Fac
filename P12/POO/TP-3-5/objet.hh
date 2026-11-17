#pragma once

#include "position.hh"
#include "taille.hh"
#include <iostream>

class objet {
protected:
  position _position;
  taille _taille;

public:
  objet(position const &p, taille const &t) : _position(p), _taille(t) {};

  position pos() const { return _position; };
  void setpos(position const &p) {
    _position.setX(p.x());
    _position.setY(p.y());
  };

  taille tai() const { return _taille; };

  bool contientposition(position const &p) const {
    if (p.x() >= _position.x() && p.x() <= _position.x() + _taille.w() &&
        p.y() >= _position.y() && p.y() <= _position.y() + _taille.h())
      return true;
    return false;
  };

  virtual char typeobjet() const = 0;

  void sortieflux(std::ostream &flux) const {
    flux << typeobjet() << " " << _position.toString() << "\n";
  };

  virtual void appliquerdeplacement() = 0;
};
