#pragma once
#include "tailleposition.hh"
#include <list>
#include "personnage.hh"
#include "objetramassable.hh"
#include "obstacle.hh"

enum class direction {
  nord, sud, est, ouest
};

class carte {

private:
  taille_t _taille;
  std::list<personnage> _personnages;
  std::list<objetramassable> _objetramassables;
  std::list<obstacle> _obstacles;

  bool intersectionelements(coordonnee a1, coordonnee a2, coordonnee b1, coordonnee b2) const;

public:
  carte();
  carte(taille_t const & taille);


  taille_t const & accestaille() const {return _taille;}
  std::list<objetramassable> const & objets() const {return _objetramassables;}
  std::list<personnage> const & personnages() const {return _personnages;}
  std::list<obstacle> const & obstacles() const {return _obstacles;}

  personnage* ajouter(personnage const & elem) {
    _personnages.push_back(elem);
    return &_personnages.back();
  }
  void ajouter(objetramassable const & elem) {
    _objetramassables.push_back(elem);
  }
  void ajouter(obstacle const & elem) {
    _obstacles.push_back(elem);
  }

  void afficherpersonnages() const;

  bool intersectionelements(element const & elem1, element const & elem2) const;

  bool emplacementlibre(position_t const &position,
                        taille_t const &taille) const;
  bool deplacementpossible(personnage const & perso, direction const & dpl) const;

  void deplacement(personnage & perso, direction const & dpl);

  bool ramassagepossible(personnage const & perso, objetramassable const & obj) const;
  void ramassertout(personnage & perso);
};
