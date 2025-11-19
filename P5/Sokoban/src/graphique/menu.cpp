#include "menu.h"

const unsigned int LARGEUR_FENETRE = 1200;
const unsigned HAUTEUR_FENETRE = 900;

bool ouvre_menu(){
  
  // Création de la fenêtre
  sf::RenderWindow fenetre(sf::VideoMode({LARGEUR_FENETRE,HAUTEUR_FENETRE}), "Sokoban");
  fenetre.setFramerateLimit(30);


  //initialisation de la police d'écriture
  sf::Font font;
  if(!font.loadFromFile("../../assets/Jersey15-Regular.ttf")) {
      return false;
  }

  //ajout d'une texture pour le fond
  sf::Texture bg_texture;
  bg_texture.loadFromFile("../../assets/bg.png");
  sf::Sprite bg_sprite;
  bg_sprite.setTexture(bg_texture);


  //========texte "Menu Sokoban" =========
  sf::Text texte("Sokoban", font, 150);

    // On centre le texte
  texte.setPosition(LARGEUR_FENETRE/2 - texte.getGlobalBounds().width/2, HAUTEUR_FENETRE/2 - texte.getGlobalBounds().height/2 - 100);

  texte.setFillColor(sf::Color::Yellow);
  //===============================


  //===texte "Clique moi pour jouer"===
  sf::Text clique_moi_txt("Clique moi pour jouer", font, 70);

    // On centre le texte
  clique_moi_txt.setPosition(LARGEUR_FENETRE/2 - clique_moi_txt.getGlobalBounds().width/2, HAUTEUR_FENETRE/2 - clique_moi_txt.getGlobalBounds().height/2 +60);
  sf::FloatRect clique_moi_rect = clique_moi_txt.getGlobalBounds(); // On récupère le rectangle du texte

  clique_moi_txt.setFillColor(sf::Color::White);
  //==============================
  sf::View view;
  view.reset(sf::FloatRect(0, 0, 1200, 900));
  fenetre.setView(view);
  //===Premier dessin de la fenêtre===
  fenetre.clear(); // On efface tout
  fenetre.draw(bg_sprite);
  fenetre.draw(texte);

  fenetre.draw(clique_moi_txt);
   // On affiche la fenêtre
  //===================

  
  sf::Event event; //variable pour gérer les évents

  // initialiser avec une vue de base
  fenetre.display();
  bool update=false;
  while(fenetre.isOpen()){

    while(fenetre.pollEvent(event)) {  //boucle d'évenement

      if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            view = sf::View(visibleArea);
            //fenetre.setView(view);
            update = true;
      }

      //si on veux fermer la fenetre
      if(event.type == sf::Event::Closed) {
        fenetre.close();
      }
      
      //======commandes de menu =====
      else if (event.type == sf::Event::MouseButtonPressed){

        if (clique_moi_rect.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x,fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
        {
          fenetre.clear();
          if(!ouvre_selection(fenetre, event, view))
            return false;
          //fin fonction -> on quitte le jeu
          fenetre.clear();
          update = true;
        }
      }
      //==========================
    }

    if(update){
      fenetre.clear();
      fenetre.draw(bg_sprite);
      fenetre.draw(texte);
      fenetre.draw(clique_moi_txt);

      fenetre.display();

      update=false;
    }
  }

  return true;
}