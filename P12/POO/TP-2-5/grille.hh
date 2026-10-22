#pragma once

#include <vector>
#include <cstdlib>

enum class EtatCellule {
  Vivant, Mort
};

using t_colonne = std::vector<EtatCellule>;
using t_grille = std::vector<t_colonne>;
using Coordonnee = size_t;

enum class Structure {
  OscillateurLigne,
  Floraison,
  Planeur,
  OscillateurCroix
};

class Grille {
private:
  t_grille _grille;

public:
  Grille(Coordonnee lon, Coordonnee lar);

  void vider();
  bool vivante(Coordonnee x, Coordonnee y) const;
  void generer(Coordonnee x, Coordonnee y);
  void tuer(Coordonnee x, Coordonnee y);
  void afficher() const;

  bool dansGrille(Coordonnee x, Coordonnee y) const;

  void ajouterStructure(const Structure & s, Coordonnee x, Coordonnee y);
  int vivantes(Coordonnee x, Coordonnee y) const;
  void evolution(Grille & g);

};
