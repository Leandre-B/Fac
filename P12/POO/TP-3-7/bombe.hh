#pragma once
#include "entite.hh"

class bombe : public entite {
public:
  enum class bombe_etat { decompte, explosion };

  bombe(identifiant id, position const &pos, coord largeur)
      : entite(id, pos), _bombe_etat(bombe_etat::decompte), _decompte(10),
        _largeur(largeur) {}

  bombe_etat const &etat() const { return _bombe_etat; }
  coord largeur() const { return _largeur; }
  coord decompte() const { return _decompte; }

  char symbole() const override {
    switch (_bombe_etat) {
    case bombe_etat::decompte:
      return 'B';
    case bombe_etat::explosion:
      return 'E';
    }
    return ' '; // JAMAIS ATTEIND
  }

  void sortie_flux(std::ostream &flux) const {
    entite::sortie_flux(flux);
    flux << " " << _largeur << " " << _decompte;
  }

  void exploser() {
    _bombe_etat = bombe_etat::explosion;
    _decompte = 2 * _largeur;
  }

  bool etat_suivant() {
    switch (_bombe_etat) {
    case bombe_etat::decompte:
      if (_decompte > 0)
        --_decompte;
      if (_decompte == 0)
        exploser();
      break;
    case bombe_etat::explosion:
      if (_decompte > 0)
        --_decompte;
      break;
    }
    return _decompte == 0;
  }

private:
  bombe_etat _bombe_etat;
  coord _decompte;
  coord _largeur;
};
