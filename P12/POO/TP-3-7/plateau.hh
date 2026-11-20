#pragma once

#include "bombe.hh"
#include "bonus.hh"
#include "entite.hh"
#include "obstacle.hh"

#include <list>
#include <vector>

class plateau {
public:
  plateau(position const &taille) : _taille(taille) {};

  bool ajouter(bombe const &b) {
    // Verfification de la position
    // if (!positioncorrecte(b))
    //   return false;

    // for (auto const &bombe : _bombes) {
    //   if (bombe.pos().egale(b.pos()))
    //     return false;
    // }

    _bombes.push_back(b);
    return true;
  }

  bool ajouter(bonus const &b) {
    // Verfification de la position
    if (!positioncorrecte(b))
      return false;

    for (auto const &bonus : _bonus) {
      if (bonus.pos().egale(b.pos()))
        return false;
    }

    _bonus.push_back(b);
    return true;
  }

  bool ajouter(obstacle const &o) {
    // Verfification de la position
    if (!positioncorrecte(o))
      return false;

    for (auto const &obstacles : _obstacles) {
      if (obstacles.pos().egale(o.pos()))
        return false;
    }

    _obstacles.push_back(o);
    return true;
  }

  void sortie_flux(std::ostream &flux) const {
    for (auto const &obstacles : _obstacles) {
      obstacles.sortie_flux(flux);
      flux << "\n";
    }
    for (auto const &bonus : _bonus) {
      bonus.sortie_flux(flux);
      flux << "\n";
    }
    for (auto const &bombes : _bombes) {
      bombes.sortie_flux(flux);
      flux << "\n";
    }
  }

  void sortie_graphique(std::ostream &flux,
                        std::list<position> const &expl) const {
    for (int y = 0; y < _taille.y(); ++y) {
      for (int x = 0; x < _taille.x(); ++x) {
        bool vide = true;
        for (auto const &obstacles : _obstacles) {
          if (obstacles.pos().egale(position(x, y))) {
            std::cout << obstacles.symbole();
            vide = false;
          }
        }
        for (auto const &bonus : _bonus) {
          if (bonus.pos().egale(position(x, y))) {
            std::cout << bonus.symbole();
            vide = false;
          }
        }
        for (auto const &bombes : _bombes) {
          if (bombes.pos().egale(position(x, y))) {
            std::cout << bombes.symbole();
            vide = false;
          }
        }
        for (auto const &ex : expl) {
          if (ex.egale(position(x, y))) {
            std::cout << "*";
            vide = false;
          }
        }
        if (vide)
          std::cout << " ";
      }
      std::cout << "\n";
    }
  }

  void etat_suivant(std::list<position> &expl) {
    for (auto bombe = _bombes.begin(); bombe != _bombes.end();) {
      if (bombe->etat_suivant()) {
        bombe = _bombes.erase(bombe);
      } else {
        if (bombe->etat() == bombe::bombe_etat::explosion) {

          std::vector<std::vector<coord>> vect = {
              {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
          for (auto const &v : vect) {
            bool obs = false;
            for (coord rayon = 1;
                 rayon < 2 * bombe->largeur() - bombe->decompte(); ++rayon) {
              coord x = bombe->pos().x() + rayon * v[0];
              coord y = bombe->pos().y() + rayon * v[1];

              for (auto const &obstacles : _obstacles) {
                if (obstacles.pos().egale(position(x, y))) {
                  obs = true;
                }
              }
              if (!obs)
                expl.push_back(position(x, y));
            }
          }
        }
        ++bombe;
      }
    }
  }

private:
  position _taille;
  std::list<obstacle> _obstacles;
  std::list<bombe> _bombes;
  std::list<bonus> _bonus;

  bool positioncorrecte(entite const &e) {
    return (e.pos().x() >= 0 && e.pos().x() <= _taille.x() &&
            e.pos().y() >= 0 && e.pos().y() <= _taille.y());
  }
};
