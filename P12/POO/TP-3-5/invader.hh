#pragma once
#include "objectactif.hh"

class invader : public objetactif {
private:
public:
  invader(position const &p, unsigned int xmin, unsigned int xmax,
          direction_t const &direction)
      : objetactif(p, taille(11, 8), xmin, xmax, direction) {}

  char typeobjet() const override { return 'I'; };

  void appliquerdeplacement() override {
    switch (dir()) {
    case direction_t::droite:
      if (_position.x() < xmax())
        _position.setX(_position.x() + 1);
      if (_position.x() == xmax()) {
        _position.setY(_position.y() + 1);
        setdir(direction_t::gauche);
      }
      break;

    case direction_t::gauche:
      if (_position.x() > xmin())
        _position.setX(_position.x() - 1);
      if (_position.x() == xmin()) {
        _position.setY(_position.y() + 1);
        setdir(direction_t::droite);
      }
      break;

    case direction_t::stop:
      break;
    }
  }
};
