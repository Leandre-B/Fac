#pragma once
#include <list>

#include "invader.hh"
#include "joueur.hh"
#include "projectile.hh"

class jeu {
private:
  std::list<invader> _invaders;
  std::list<projectile> _projectiles;
  joueur _joueur;

  void projectilecollision() {
    for (auto p = _projectiles.begin(); p != _projectiles.end();) {
      bool erase_p = false;
      for (auto i = _invaders.begin(); i != _invaders.end();) {
        if (i->contientposition(p->pos())) {
          p = _projectiles.erase(p);
          i = _invaders.erase(i);
          erase_p = true;
          break;
        } else
          ++i;
      }
      if (!erase_p)
        ++p;
    }
  }

public:
  jeu()
      : _joueur(position(144, 180), taille(9, 8), 10, 310,
                objetactif::direction_t::stop) {};

  bool ajouter(invader const &invader) {
    for (auto const &i : _invaders) {
      if (i.pos().eqale(invader.pos()))
        return false;
    }
    _invaders.push_front(invader);
    return true;
  };

  bool ajouter(projectile const &projectile) {
    for (auto const &p : _projectiles) {
      if (p.pos().eqale(projectile.pos()))
        return false;
    }
    _projectiles.push_front(projectile);
    return true;
  };

  joueur getjoueur() const { return _joueur; };

  std::list<invader> invaders() const { return _invaders; };
  std::list<projectile> projectiles() const { return _projectiles; };

  void tirjoueur() {
    _projectiles.push_front(projectile(position(
        _joueur.tai().w() / 2 + _joueur.pos().x(), _joueur.pos().y())));
  }

  void directionjoueur(objetactif::direction_t const &dir) {
    _joueur.setdir(dir);
  };

  void afficher(std::ostream &flux) const {
    _joueur.sortieflux(flux);
    for (auto const &i : _invaders)
      i.sortieflux(flux);
    for (auto const &p : _projectiles)
      p.sortieflux(flux);
  }

  void projectiledisparition() {
    for (auto it = _projectiles.begin(); it != _projectiles.end();) {
      if (it->pos().y() == 0)
        it = _projectiles.erase(it);
      else {
        ++it;
      }
    }
  }

  void tourdejeu() {
    // DEPLACEMENT
    _joueur.appliquerdeplacement();
    for (auto &i : _invaders)
      i.appliquerdeplacement();
    for (auto &p : _projectiles)
      p.appliquerdeplacement();

    projectiledisparition();
    projectilecollision();
  }
};
