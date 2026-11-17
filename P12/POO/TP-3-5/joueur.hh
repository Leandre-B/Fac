#pragma once
#include "objectactif.hh"

class joueur : public objetactif {
private:
public:
  joueur(position const &p, taille const &t, unsigned int xmin,
         unsigned int xmax, direction_t const &direction)
      : objetactif(p, t, xmin, xmax, direction) {}

  void malus() {
    unsigned int newTaille = tai().w() * 3;
    if (newTaille > 100)
      newTaille = 100;
    tai().setw(newTaille);
  };

  void bonus() {
    unsigned int newTaille = tai().w() / 2;
    if (newTaille < 3)
      newTaille = 3;
    tai().setw(newTaille);
  };

  char typeobjet() const override { return 'J'; };
};
