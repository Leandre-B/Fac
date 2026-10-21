#pragma once
#include <cstdlib>
#include <iostream>

enum class Couleur { Rouge, Bleu, Jaune, Vert, /*None*/ };
using indicesequence = std::size_t;


class Sequence {
private :
  Couleur* _couleurs;
  indicesequence _taille;

public:
  Sequence();
  Sequence(const Sequence & s);
  ~Sequence();

  indicesequence taille();

  void ajouter(const Couleur & c);
  Couleur acces(indicesequence i) const;
  void afficher(const Couleur & c);
  void afficher(std::ostream & cout);
  void vider();
  bool comparer(const Sequence & s);
  void copier(const Sequence & s);
};
