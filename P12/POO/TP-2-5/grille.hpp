#pragma once

#include <vector>
#include <cstdlib>

enum class EtatCellule {
  Vivant, Mort
};

using t_colonne = std::vector<EtatCellule>;
using t_grille = std::vector<t_colonne>;
using Coordonee = size_t;

class Grille {
private:
  t_grille _grille;

public:
  Grille(Coordonee lon, Coordonee lar);

  void vider();
  bool vivante(Coordonee x, Coordonee y);
  void generer(Coordonee x, Coordonee y);
  void tuer(Coordonee x, Coordonee y);
  void afficher();
};
