#include "jeu.h"


struct Textures{
  std::string skin; //nom du dossier du skin
  sf::Texture texture;
};

//initialise les textures (skins + confettis)
bool init_texture(Textures* & textures,std::string skin,sf::Texture* &confettis_Texture){

  //textures[0] = bg;
  //textures[1] = caisse;
  //textures[2] = caisse_on_spot;
  //textures[3] = spot;
  //textures[4] = wall;
  //textures[5] = perso;
  //textures[6] = exterieur;

  textures[0].skin=skin;
  if(!textures[0].texture.loadFromFile("../../skins/"+textures[0].skin+"/bg.png")) {
    //si on a pas réussi à charger la texture du skin on charge celle par defaut
    textures[0].skin="default";

    if(!textures[0].texture.loadFromFile("../../skins/"+textures[0].skin+"/bg.png"))
      return false;
  }

  textures[1].skin=skin;
  if(!textures[1].texture.loadFromFile("../../skins/"+textures[1].skin+"/caisse.png")) {
    textures[1].skin="default";

    if(!textures[1].texture.loadFromFile("../../skins/"+textures[1].skin+"/caisse.png"))
      return false;
  }

  textures[2].skin=skin;
  if(!textures[2].texture.loadFromFile("../../skins/"+textures[2].skin+"/caisse_on_spot.png")) {
    textures[2].skin="default";

    if(!textures[2].texture.loadFromFile("../../skins/"+textures[2].skin+"/caisse_on_spot.png"))
      return false;
  }

  textures[3].skin=skin;
  if(!textures[3].texture.loadFromFile("../../skins/"+textures[3].skin+"/spot.png")) {
    textures[3].skin="default";

    if(!textures[3].texture.loadFromFile("../../skins/"+textures[3].skin+"/spot.png"))
      return false;
  }

  textures[4].skin=skin;
  if(!textures[4].texture.loadFromFile("../../skins/"+textures[4].skin+"/wall.png")) {
    textures[4].skin="default";

    if(!textures[4].texture.loadFromFile("../../skins/"+textures[4].skin+"/wall.png"))
      return false;
  }

  textures[5].skin=skin;
  if(!textures[5].texture.loadFromFile("../../skins/"+textures[5].skin+"/perso.png")) {
    textures[5].skin="default";

    if(!textures[5].texture.loadFromFile("../../skins/"+textures[5].skin+"/perso.png"))
      return false;
  }

  textures[6].skin=skin;
  if(!textures[6].texture.loadFromFile("../../skins/"+textures[6].skin+"/exterieur.png")) {
    textures[6].skin="default";

    if(!textures[6].texture.loadFromFile("../../skins/"+textures[6].skin+"/exterieur.png"))
      return false;
  }

  //=====ajout des confettis=======
  std::string path_to_confettis;
  confettis_Texture=new sf::Texture[100];//initie le tableau des textures de confettis
  for(int i=0;i<100;++i)
  {
    path_to_confettis =std::string("../../assets/confettis/confetti-")+std::to_string(i)+std::string(".png");
    if(!confettis_Texture[i].loadFromFile(path_to_confettis))
      return false;
  }
  //==============================
  return true;
}

//initialise un tableau 2D de sprites correspondant au plateau de jeu
void init_sprites(sf::Sprite** & sprites,Plateau plateau,Textures* textures){
  for(int i = 0;i<plateau.hauteur;++i){
    for(int j = 0;j<plateau.longueur;++j){
      sprites[i][j].setPosition(LARGEUR_FENETRE/2 -plateau.longueur*32/2 + j*32,
                                HAUTEUR_FENETRE/2 -plateau.hauteur*32/2 + i*32); //les textures sont en 32px


      switch (plateau.grille[i][j]){
        case ' ':
          sprites[i][j].setTexture(textures[0].texture);
          break;

        case '$':
          sprites[i][j].setTexture(textures[1].texture);
          break;

        case '*':
          sprites[i][j].setTexture(textures[2].texture);
          break;

        case '.':
          sprites[i][j].setTexture(textures[3].texture);
          break;

        case '#':
          sprites[i][j].setTexture(textures[4].texture);
          break;

        case '@':
          sprites[i][j].setTexture(textures[5].texture);
          break;

        case '+':
          sprites[i][j].setTexture(textures[5].texture);
          break;

        case '0':
          sprites[i][j].setTexture(textures[6].texture);
          break;
      }
    }
  }
}


bool fenetre_jeu(sf::RenderWindow & fenetre,sf::Event & event, sf::View & view, Plateau plateau, bool & end, std::string skin){
  //initialisation font
  sf::Font font;
  if(!font.loadFromFile("../../assets/Jersey15-Regular.ttf")) {
      return false;
  }

  //===== background ======
  sf::Texture bg_texture;
  if(!bg_texture.loadFromFile("../../skins/"+skin+"/full_bg.png")){
    if(!bg_texture.loadFromFile("../../skins/default/full_bg.png"))
      return false;
  }
    
  sf::Sprite bg_sprite;
  bg_sprite.setTexture(bg_texture);
  //====================


  //=====texte <plateau.nom>======
  sf::Text nom_text(plateau.nom, font, 40);

  nom_text.setPosition(LARGEUR_FENETRE/2 - nom_text.getGlobalBounds().width/2, 20);

  nom_text.setFillColor(sf::Color::White);
  //==============================



  //=====texte "Résoudre"======
  sf::Text resoudre_txt("Resoudre", font, 40);

  resoudre_txt.setPosition(LARGEUR_FENETRE - resoudre_txt.getGlobalBounds().width - 30, HAUTEUR_FENETRE - resoudre_txt.getGlobalBounds().height -30);
  sf::FloatRect resoudre_rect = resoudre_txt.getGlobalBounds(); // On récupère le rectangle du texte

  resoudre_txt.setFillColor(sf::Color::White);
  //==============================


  //===== Textures ======
  Textures* textures = new Textures[7];
  sf::Texture* confettis_Texture;

  //Initialisation des textures
  if(!init_texture(textures,skin,confettis_Texture)){
    std::cout<<"Erreur lors de l'initialisation des textures."<<std::endl;
    return false;
  }
  //=================


  //Creation d'un tableau de sprite correspondant au plateau
  sf::Sprite** sprites = new sf::Sprite*[plateau.hauteur];
  for(int i = 0 ;i<plateau.hauteur;++i)
    sprites[i]=new sf::Sprite [plateau.longueur];


  //Ajout les bons sprites aux textures suivant le plateau
  init_sprites(sprites,plateau,textures);


  // ==== Premier dessin de la fenêtre ====
  fenetre.clear(); // On efface tout
  fenetre.draw(bg_sprite);
  fenetre.draw(nom_text);
  fenetre.draw(resoudre_txt);

  //affichage des textures du plateau
  for(int i = 0;i<plateau.hauteur;++i){
    for(int j = 0;j<plateau.longueur;++j){
      fenetre.draw(sprites[i][j]);
    }
  }
          
  fenetre.display(); // On affiche la fenetre
  //=======================================

  //pour gèrer l'animation de victoire
  sf::Sprite confettis_image;
  sf::Clock animation_clock;
  int texture_clock=0;

  std::string mouvement_ia=""; //contient mouvement h,b,g,d

  bool quitter=false;
  bool update=false;
  bool resoudre = false;
  bool victoire=false;

  while(!quitter){

    while(fenetre.pollEvent(event) and !quitter) {  //boucle d'evenement

      //si on resize la fentre, on update la view
      if (event.type == sf::Event::Resized) {
          sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
          view = sf::View(visibleArea);
          //fenetre.setView(view);
          update = true;
      }

      //si on veux fermer la fenetre
      if(event.type == sf::Event::Closed) {
        quitter = true;
        end = true; //important pour arrêter l'exécution du programme dans les autres fonctione (menu et selection)
        fenetre.close();
      }

      //pour retourner au menu précédent
      else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Escape){
				  quitter = true;
        }
      }

  
      else if (event.type == sf::Event::MouseButtonPressed and !resoudre){
        //bouton pour resoudre le jeu (appel IA)
        if (resoudre_rect.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x,fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
          {

            mouvement_ia=resoudre_plt(plateau);

            resoudre = true;
          }

        // calcule la position de la souris sur la plateau pour déplacer le perso où on clique
        else if ((fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x<static_cast<int>(LARGEUR_FENETRE/2+(plateau.longueur/2)*32)) and 
            (fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x>static_cast<int>(LARGEUR_FENETRE/2-(plateau.longueur/2)*32)) and 
            (fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y<static_cast<int>(HAUTEUR_FENETRE/2+(plateau.hauteur/2)*32)) and 
            (fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y>static_cast<int>(HAUTEUR_FENETRE/2-(plateau.hauteur/2)*32)))
          {

            float fx=(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x - static_cast<float>(LARGEUR_FENETRE)/2+static_cast<float>(plateau.longueur)*16 )/32;
            float fy=(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y - static_cast<float>(HAUTEUR_FENETRE)/2+static_cast<float>(plateau.hauteur)*16)/32;
            int x_souris = static_cast<int>(fx);
            int y_souris = static_cast<int>(fy);

            mouvement_ia=a_star(plateau,plateau.x,x_souris,plateau.y,y_souris,false);

            resoudre=true;
          }
            
      }

      //=========commandes de jeu ============
      else if(!resoudre and !plateau.bloque and !victoire){
        if (event.type == sf::Event::KeyPressed){

          if (event.key.code == sf::Keyboard::Z or event.key.code == sf::Keyboard::Up){
            if(deplacement('h',plateau))
              update=true;
          }

          else if (event.key.code == sf::Keyboard::S or event.key.code == sf::Keyboard::Down){
            if(deplacement('b',plateau))
              update=true;
          }

          else if (event.key.code == sf::Keyboard::Q or event.key.code == sf::Keyboard::Left){
            if(deplacement('g',plateau))
              update=true;
          }

          else if (event.key.code == sf::Keyboard::D or event.key.code == sf::Keyboard::Right){
            if(deplacement('d',plateau))
              update=true;
          }
          
          
        }
      }
      //==========fin commandes de jeu =========
    }

    //si on a appuyé sur le bouton résoudre
    if(resoudre){
      if (mouvement_ia!="o"){ //si une solution a été trouvée
        
        //on applique chaque déplacement
        for (unsigned int i=0;i<mouvement_ia.length();++i) {
          deplacement(mouvement_ia[i],plateau);

          //on redessine la fenetre
          fenetre.clear();
          fenetre.draw(bg_sprite);
          fenetre.draw(resoudre_txt);
          fenetre.draw(nom_text);
          
          init_sprites(sprites,plateau,textures);

          //affichage des textures
          for(int i = 0;i<plateau.hauteur;++i){
            for(int j = 0;j<plateau.longueur;++j){
              fenetre.draw(sprites[i][j]);
            }
          }
          fenetre.display();
          
          //sleep pour visualiser les mouvements
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
      }
      resoudre=false;
      update = true; //pour ensuite vérifier si on a gagné
    }
  

    //si je leu à été update (un déplacement a été éffectué)
    if(update and !quitter){
      update = false;

      //==== on redessine la fenetre ====
      fenetre.clear();
      fenetre.draw(bg_sprite);
      fenetre.draw(nom_text);
      fenetre.draw(resoudre_txt);

      init_sprites(sprites,plateau,textures);

      //affichage des textures
      for(int i = 0;i<plateau.hauteur;++i){
        for(int j = 0;j<plateau.longueur;++j){
          fenetre.draw(sprites[i][j]);
        }
      }
      //==============
      

      if (plateau.score==plateau.nb_caisse)
        victoire=true;

      else if(plateau.bloque){

        sf::Text perdu_txt("Game Over :(", font, 100);
        perdu_txt.setPosition(LARGEUR_FENETRE/2 - perdu_txt.getGlobalBounds().width/2, HAUTEUR_FENETRE/2 - perdu_txt.getGlobalBounds().height/2);
        perdu_txt.setFillColor(sf::Color::Red);
        fenetre.draw(perdu_txt);

      }
      if(victoire){
          
        //affiche un confetti et passe au suivant
        //vérifie que 100ms soit passer avant d'afficher le confetti suivant
        if (animation_clock.getElapsedTime().asMilliseconds() > 100) {
            
          animation_clock.restart();
          confettis_image.setScale(5.f,3.f);
          confettis_image.setTexture(confettis_Texture[texture_clock]);
          confettis_image.setPosition(1200/2 - confettis_image.getGlobalBounds().width/2,0);//set la position des confettis en haut de la fenetre au milieu
          texture_clock = (texture_clock + 1) % 100;
            
        }
        update=true;
        fenetre.draw(confettis_image);

      }
      fenetre.display(); //update la fenetre
    }

    if(quitter){
      delete [] plateau.grille;
      delete [] confettis_Texture;
      delete [] textures;
      delete [] sprites;
      fenetre.clear();
    }
  }
  return true;
}
  
