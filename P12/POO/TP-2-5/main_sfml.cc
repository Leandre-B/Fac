#include "grille.hh"
#include "affichage_sfml.hh"
#include <math.h>

int main() {

  srand(time(nullptr));
  unsigned int largeur = 50;
  unsigned int hauteur = 50;

  bool pause = true;

  affichage_jeu_de_la_vie jdlv(largeur,hauteur,1);
  Grille g(largeur,hauteur);

  while(jdlv.fenetre_ouverte()) {
    affichage_jeu_de_la_vie::action aj; unsigned int x, y;
    while (jdlv.recuperer_action_joueur(aj, x, y)) {
      switch (aj) {
      case affichage_jeu_de_la_vie::action::inverser_cellule:
        if (g.vivante(x, y))
          g.tuer(x, y);
        else
          g.generer(x, y);
        break;

      case affichage_jeu_de_la_vie::action::ajouter_floraison :
        g.ajouterStructure(Structure::Floraison, x, y);
        break;

      case affichage_jeu_de_la_vie::action::ajouter_oscillateurligne :
        g.ajouterStructure(Structure::OscillateurLigne, x, y);
        break;

      case affichage_jeu_de_la_vie::action::ajouter_oscillateurcroix :
        g.ajouterStructure(Structure::OscillateurCroix, x, y);
        break;

      case affichage_jeu_de_la_vie::action::ajouter_planeur :
        g.ajouterStructure(Structure::Planeur, x, y);
        break;
      case affichage_jeu_de_la_vie::action::ajouter_random :
        g.vider();
        for (unsigned int i = 0; i < largeur; ++i)
          for (unsigned int j = 0; j < hauteur; ++j)
            if(rand()%2 == 0) g.generer(i, j);
        break;

      case affichage_jeu_de_la_vie::action::effacer :
        g.vider();
        break;

      case affichage_jeu_de_la_vie::action::pause_oui_non :
        pause = !pause;
        break;

      default : break;

      }
    }
    jdlv.affichage_commencer();
    jdlv.afficher_grille_vide();
    for (unsigned int i = 0; i < largeur; ++i)
      for (unsigned int j = 0; j < hauteur; ++j)
        if (g.vivante(i, j))
          jdlv.afficher_cellule_vivante(i, j);
    jdlv.affichage_terminer();

    if(!pause) {
      Grille resultat(largeur, hauteur);
      g.evolution(resultat);
      g = resultat;
    }

  }

  return 0;
}
