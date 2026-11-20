#include "affichage_sfml.h"
#include "grille.hh"
#include <vector>

int main() {
  const unsigned int largeur = 80;
  const unsigned int hauteur = 50;
  std::vector<grille> grilles(2, grille(largeur, hauteur));
  std::size_t grille_actuel(0);
  bool en_pause(false);

  affichage_jeu_de_la_vie affichage(largeur, hauteur, 1);
  while (affichage.fenetre_ouverte()) {
    affichage_jeu_de_la_vie::action aj;
    unsigned int x, y;
    while (affichage.recuperer_action_joueur(aj, x, y)) {
      switch (aj) {
      case affichage_jeu_de_la_vie::action::pause_oui_non:
        en_pause = !en_pause;
        break;
      case affichage_jeu_de_la_vie::action::inverser_cellule:
        if (grilles[grille_actuel].vivante(x, y))
          grilles[grille_actuel].tuer(x, y);
        else
          grilles[grille_actuel].generer(x, y);
        break;
      case affichage_jeu_de_la_vie::action::ajouter_oscillateurligne:
        grilles[grille_actuel].ajouterstructure(structure::oscillateurligne, x,
                                                y);
        break;
      case affichage_jeu_de_la_vie::action::ajouter_floraison:
        grilles[grille_actuel].ajouterstructure(structure::floraison, x, y);
        break;
      case affichage_jeu_de_la_vie::action::ajouter_planeur:
        grilles[grille_actuel].ajouterstructure(structure::planeur, x, y);
        break;
      case affichage_jeu_de_la_vie::action::ajouter_oscillateurcroix:
        grilles[grille_actuel].ajouterstructure(structure::oscillateurcroix, x,
                                                y);
        break;
      case affichage_jeu_de_la_vie::action::rien:
        break;
      }
    }
    if (!en_pause) {
      grilles[grille_actuel].evolution(grilles[1 - grille_actuel]);
      grille_actuel = 1 - grille_actuel;
    }
    affichage.affichage_commencer();
    affichage.afficher_grille_vide();
    for (unsigned int i = 0; i < largeur; ++i)
      for (unsigned int j = 0; j < hauteur; ++j)
        if (grilles[grille_actuel].vivante(i, j))
          affichage.afficher_cellule_vivante(i, j);
    affichage.affichage_terminer();
  }
  return 0;
}
