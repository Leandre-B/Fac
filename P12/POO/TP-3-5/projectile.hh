#pragma once
#include "objet.hh"

class projectile : public objet {
private:
public:
  projectile(position const &p) : objet(p, taille(1, 1)) {};

  char typeobjet() const override { return 'P'; };

  void appliquerdeplacement() override {
    if (pos().y() > 0)
      _position.setY(_position.y() - 1);
  }
};
