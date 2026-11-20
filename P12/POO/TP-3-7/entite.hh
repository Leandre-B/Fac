#pragma once
#include "position.hh"

using identifiant = unsigned int;

class entite {
public:
  entite(identifiant id, position const &pos)
      : _identifiant(id), _position(pos) {};

  position const &pos() const { return _position; }
  identifiant id() const { return _identifiant; }

  virtual char symbole() const = 0;

  void sortie_flux(std::ostream &flux) const {
    flux << _identifiant << " " << symbole();
  }

private:
  identifiant _identifiant;
  position _position;
};
