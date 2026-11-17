#include <iostream>
#include "graphe.hh"
#include "sommet.hh"


int main() {

  graphe g;
  auto paris(g.ajoutersommet("Paris"));
  auto angers(g.ajoutersommet("Angers"));
  auto nantes(g.ajoutersommet("Nantes"));

  g.ajouterarc(angers, nantes, "Bus");
  g.ajouterarc(nantes, angers, "Bus");
  g.ajouterarc(angers, paris, "Train");
  g.ajouterarc(paris, nantes, "Avion");

  g.dot_sortie(std::cout);

  
  //sauvergraphe(g, "tout.dot");
  g.supprimersommet(angers);
  //sauvergraphe(g, "sansangers.dot");
  return 0;

  return 0;
}
