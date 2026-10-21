#include "grille.hpp"

#include <iostream>

Grille::Grille(Coordonee lon, Coordonee lar) :
  _grille(lar, t_colonne(lon, EtatCellule::Mort))
{
}

void Grille::vider() {
  _grille = t_grille(_grille.size(), t_colonne(_grille[0].size(), EtatCellule::Mort));
}

bool Grille::vivante(Coordonee x, Coordonee y) {
  return _grille[y][x] == EtatCellule::Vivant;
}
void Grille::generer(Coordonee x, Coordonee y) {
  _grille[y][x] = EtatCellule::Vivant;
}

void Grille::tuer(Coordonee x, Coordonee y) {
  _grille[y][x] = EtatCellule::Mort;
}

void Grille::afficher() {
  for(const auto & col : _grille) {
    for(const auto & cell : col) {
      if(cell == EtatCellule::Vivant)
        std::cout<<"*";
      else
        std::cout<<" ";
    }
    std::cout<<"\n";
  }
}
