#pragma once

#include "objet.hh"
class objetactif : public objet {

public:
  struct amplitude_t {
    unsigned int xmin;
    unsigned int xmax;
  };

  enum class direction_t { stop, droite, gauche };

  objetactif(position const &p, taille const &t, unsigned int xmin,
             unsigned int xmax, direction_t const &direction)
      : objet(p, t), _amplitude({xmin, xmax}), _direction(direction) {};

  unsigned int xmin() const { return _amplitude.xmin; };
  unsigned int xmax() const { return _amplitude.xmax; };

  direction_t dir() const { return _direction; };
  void setdir(direction_t const &d) { _direction = d; };

  void appliquerdeplacement() override {
    switch (_direction) {
    case direction_t::droite:
      if (_position.x() < _amplitude.xmax)
        _position.setX(_position.x() + 1);
      break;

    case direction_t::gauche:
      if (_position.x() > _amplitude.xmin)
        _position.setX(_position.x() - 1);
      break;

    case direction_t::stop:
      break;
    }
  }

private:
  amplitude_t _amplitude;
  direction_t _direction;
};
