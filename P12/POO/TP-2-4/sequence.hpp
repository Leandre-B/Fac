#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>

enum class Couleur { Rouge, Bleu, Jaune, Vert, /*None*/ };
using Couleurs = std::vector<Couleur>;
using indicesequence = std::size_t;

class Sequence {
private :
  Couleurs _couleurs;

public:
  indicesequence taille();

  void ajouter(const Couleur & c);
  Couleur acces(indicesequence i) const;
  void afficher(const Couleur & c);
  void afficher(std::ostream & cout);
  void vider();
  bool comparer(const Sequence & s);
  void copier(const Sequence & s);
};
