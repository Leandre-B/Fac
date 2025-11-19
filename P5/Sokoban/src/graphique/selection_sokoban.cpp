#include "selection_sokoban.h"

struct Plateau_selection{
    std::string chemin;
    std::string extension_fichier;
    sf::Text sfml_text;
    sf::FloatRect rect_slct_plt;
};


struct Skin_selection{
    std::string chemin;
    sf::Text sfml_text;
    sf::FloatRect rect_slct_skn;
};


bool get_plt_name(Plateau_selection* & plt_select, int & nb_plateau,sf::RenderWindow & fenetre){

    //on initialise la police d'écriture
    sf::Font font;
    if(!font.loadFromFile("../../assets/Jersey15-Regular.ttf")) {
        std::cout<<"erreur de l'obtention de la police"<<std::endl;
        return false;
    }

    //récupére le nombre de plateau
    nb_plateau=0;
    std::string path = "../../plateau";
    for (std::filesystem::directory_iterator i(path), end; i!=end; ++i) {
        ++nb_plateau;
    }

    //créer un tableau de selection de plateau (chemin, extension de fichier, text et rect de selection)
    plt_select = new Plateau_selection [nb_plateau];

    int i = 0;
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path)) {
        
        //on récupere le chemin du plateau
        plt_select[i].chemin=entry.path().string();

        std::string nom = plt_select[i].chemin;
        nom = nom.erase(0,14); //retire les 14 1er char (../../plateau/)
        plt_select[i].extension_fichier=nom.substr(nom.rfind('.'));

        //traite le nom en fonction de l'extension
        if(plt_select[i].extension_fichier==".xsb")
            nom.erase(nom.size()-4,4); //retire les 4 derniers (.xsb)

        else if(plt_select[i].extension_fichier==".json") //si c'est un fichier en .json
            nom.erase(nom.size()-5,5); //retire les 5 derniers (.json)
        
        else{
            std::cout<<"Extension du fichier non valide : "<<plt_select[i].extension_fichier<<std::endl;
            return false;
        }

        //=====Initialisation sfml_text========
        plt_select[i].sfml_text.setString(nom);
        plt_select[i].sfml_text.setFont(font);
        plt_select[i].sfml_text.setCharacterSize (40);
       

        plt_select[i].rect_slct_plt = plt_select[i].sfml_text.getGlobalBounds(); //pour centrer le texte
        plt_select[i].sfml_text.setPosition(LARGEUR_FENETRE/2 - plt_select[i].rect_slct_plt.width/2,
                                            plt_select[i].rect_slct_plt.height/2 + 60*i);
        //==================

        
        //le texte a bougé, on doit re-recuperer les bounds
        plt_select[i].rect_slct_plt = plt_select[i].sfml_text.getGlobalBounds();

        //si la souris est sur le texte, on le colorie en jaune, sinon en blanc
        if(plt_select[i].rect_slct_plt.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x,fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
            plt_select[i].sfml_text.setFillColor(sf::Color::Yellow);
        else
            plt_select[i].sfml_text.setFillColor(sf::Color::White);
        fenetre.draw(plt_select[i].sfml_text);

        ++i;
    }

    return true;
}
bool get_skins(Skin_selection* & skn_select, int & nb_skin,sf::RenderWindow & fenetre,int selected)
{
    //on initialise la police d'écriture
    sf::Font font;
    if(!font.loadFromFile("../../assets/Jersey15-Regular.ttf")) {
        std::cout<<"erreur de l'obtention de la police"<<std::endl;
        return false;
    }

    //récupére le nombre de skins
    nb_skin=0;
    std::string path = "../../skins";
    for (std::filesystem::directory_iterator i(path), end; i!=end; ++i) {
        ++nb_skin;
    }

    //créer un tableau de skin (chemin, text et rect de selection)
    skn_select = new Skin_selection [nb_skin];

    int i = 0;
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path)) {

        //on récupere le chemin du skin
        skn_select[i].chemin=entry.path().string();
        std::string nom = skn_select[i].chemin;

        nom = nom.erase(0,12); //retire les 12 1er char (../../skins/)

        //=====Initialisation sfml_text========
        skn_select[i].sfml_text.setString(nom);
        skn_select[i].sfml_text.setFont(font);
        skn_select[i].sfml_text.setCharacterSize (40);        
        skn_select[i].sfml_text.setPosition(30, 60*i);
        //==============================
        
        skn_select[i].rect_slct_skn = skn_select[i].sfml_text.getGlobalBounds();

        //si la souris est sur le texte, on le colorie en jaune, sinon en blanc
        if(skn_select[i].rect_slct_skn.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x,fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
            skn_select[i].sfml_text.setFillColor(sf::Color::Yellow);
        else
            skn_select[i].sfml_text.setFillColor(sf::Color::White);

        //si c'est le skin choisi, on le colorie en jaune
        if (selected==i){
            skn_select[i].sfml_text.setCharacterSize (45);
            skn_select[i].sfml_text.setFillColor(sf::Color::Yellow);
        }

        fenetre.draw(skn_select[i].sfml_text);

        ++i;
    }
    return true;
}
bool ouvre_selection(sf::RenderWindow & fenetre,sf::Event & event, sf::View & view){

    //===== initialise le background ======
    sf::Texture bg_texture;
    bg_texture.loadFromFile("../../assets/bg_clean.png");
    sf::Sprite bg_sprite;
    bg_sprite.setTexture(bg_texture);
    //====================

    //on dessine le background
    fenetre.draw(bg_sprite);

    //==== Construit les textes de selection des plateaux=====
    Plateau_selection* plt_select;
    int nb_plateau;
    
    //on initialise puis dessine les skins
    if(!get_plt_name(plt_select, nb_plateau,fenetre)){
        std::cout<<"Probleme lors de l'obtention des plateaux"<<std::endl;
        return false;
    }
    //====================


    //====== Construit les textes de selection des skins ======

    std::string skin="default"; //par défault, le skin par défault est sélectionné
    Skin_selection* skn_select; //(contient chemin, text, rectangle de selection)
    int nb_skin;
    int selected=0;
    std::string path = "../../skins";
    
    //recherche la position du skin "default" dans le dossier
    int pos_default=-1;
    for (std::filesystem::directory_iterator i(path), end; i!=end; ++i, ++selected) {
        if (i->path().string().erase(0,12)=="default"){
            pos_default=selected;
            break;
        }
    }

    //si pas de skin par défault, on prend le premier
    if(pos_default==-1)
        pos_default=0;
        
    //on initialise puis dessine la selection de skins
    if(!get_skins(skn_select, nb_skin,fenetre,selected)){
        std::cout<<"Probleme lors de l'obtention des skins"<<std::endl;
        return false;
    }
    //====== Fin construction skins =====


    fenetre.display();
    
    //=== variables utiles ===
    sf::Clock hover_clock; //pour gérer la coloration des textes
    bool update =false;
    bool end  = false; 
    //========

    while(!end){
        while(fenetre.pollEvent(event)) { //fenêtre d'évenement

            //si on resize la fentre, on update la view
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                view = sf::View(visibleArea);
                //fenetre.setView(view);
                update = true;
            }

            //si on veux fermer la fenetre
            if(event.type == sf::Event::Closed) {
                fenetre.close();
                return true;
            }

            //retourne à la fenêtre précédente
            else if (event.key.code == sf::Keyboard::Escape and event.type == sf::Event::KeyPressed){
                fenetre.clear();
                end = true;
            }
            
            //gère les actions à faire si on clique avec la souris
            else if (event.type == sf::Event::MouseButtonPressed){
                update=true;

                //vérifie si on a cliqué sur un skin et prend sa position si c'est le cas
                for(int i = 0;i<nb_skin;++i){
                    if (skn_select[i].rect_slct_skn.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x, fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
                    {
                        skin=skn_select[i].sfml_text.getString();
                        selected=i;
                    }
                }

                
                //vérifie si on a cliqué sur un plateau et prend le lance si c'est la cas
                bool choisie_plt  = false;
                int i = 0;
                while(i<nb_plateau and !choisie_plt){
                    
                    if (plt_select[i].rect_slct_plt.contains(fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).x,fenetre.mapPixelToCoords(sf::Mouse::getPosition(fenetre)).y))
                    {
                        Plateau plateau;
                        plateau.chemin=plt_select[i].chemin;
                        
                        if (plt_select[i].extension_fichier==".json")
                        {
                            if(!get_plateau_json(plateau))
                                return false;
                        }
                        else if (plt_select[i].extension_fichier==".xsb")
                        {
                            if(!get_plateau(plateau))
                                return false;
                        }
                        else{
                            std::cout<<"Mauvaise extension de fichier."<<std::endl;
                            return false;
                        }
                        
                        if(!fenetre_jeu(fenetre,event,view, plateau, end,skin))
                            return false;
                        else
                            choisie_plt = true;
                        
                        //on sort du jeu, on doit update la fenetre
                        update = true;
                    }
                    ++i;
                }
            }

            if(event.type == sf::Event::MouseMoved or update) 
            {
                update=false;

                fenetre.clear();

                fenetre.draw(bg_sprite);

                //on doit mettre un délai minimum pour éviter les ralentissement et bugs d'affichage SFML
                //car sinon update à chaque mouvement de souris

                if (hover_clock.getElapsedTime().asMilliseconds() > 50) { 
                    hover_clock.restart();

                    if(!get_plt_name(plt_select, nb_plateau,fenetre)){
                        std::cout<<"Probleme lors de l'obtention des plateaux"<<std::endl;
                        return false;
                    }
                    
                    if(!get_skins(skn_select, nb_skin,fenetre,selected)){
                        std::cout<<"Probleme lors de l'obtention des skins"<<std::endl;
                        return false;
                    }

                    fenetre.display();
                }
            }
        }
    }
    return true;
}
