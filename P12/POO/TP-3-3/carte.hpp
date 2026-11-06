#pragma once
#include "tailleposition.hpp"
#include <list>
#include "personnage.hpp"
#include "objetramassable.hpp"
#include "obstacle.hpp"

class carte {

private:
  taille_t _taille;
  std::list<personnage> _personnages;
  std::list<objetramassable> _objetramassables;
  std::list<obstacle> _obstacles;

public:
  carte();

  taille_t const & accestaille() const {return _taille;}
  std::list<objetramassable> const & objets() const {return _objetramassables;}
  std::list<personnage> const & personnages() const {return _personnages;}
  std::list<obstacle> const & obstacles() const {return _obstacles;}

  void ajouterElement(personnage const & elem) {
    _personnages.push_back(elem);
  }
  void ajouterElement(objetramassable const & elem) {
    _objetramassables.push_back(elem);
  }
  void ajouterElement(obstacle const & elem) {
    _obstacles.push_back(elem);
  }

  void afficherpersonnages() const;

  bool intersectionelements(element const & elem1, element const & elem2) const {
    return elem1.contientposition(elem2.accesposition());
  }

};
