#include "TPLaby.hh"
#include <SFML/Graphics.hpp>

int main(){
    Labyrinthe laby = labyDessinConsole();

    sf::RenderWindow fenetre(sf::VideoMode({1500, 1000}), "Labyrinthe");
    sf::Event event;

    // Declare and load a texture
    sf::Texture mouse_txt, chees_txt, top_left_txt, top_right_txt,
        bottom_left_txt, bottom_right_txt, straight_txt, side_txt;
    mouse_txt.loadFromFile("../assets/mouse.png");
    top_left_txt.loadFromFile("../assets/top_left_turn.png");
    top_right_txt.loadFromFile("../assets/top_right_turn.png");
    bottom_left_txt.loadFromFile("../assets/left_turn.png");
    bottom_right_txt.loadFromFile("../assets/right_turn.png");
    straight_txt.loadFromFile("../assets/top.png");
    side_txt.loadFromFile("../assets/side.png");
    chees_txt.loadFromFile("../assets/cheese.png");
    
    // Create a sprite
    sf::Sprite souris,cheese,top_right, top_left, 
        bottom_right, bottom_left, straight, side;
    souris.setTexture(mouse_txt);
    cheese.setTexture(chees_txt);
    top_left.setTexture(top_left_txt);
    top_right.setTexture(top_right_txt);
    bottom_left.setTexture(bottom_left_txt);
    bottom_right.setTexture(bottom_right_txt);
    straight.setTexture(straight_txt);
    side.setTexture(side_txt);


    sf::RectangleShape wall;
    wall.setSize(sf::Vector2f(20,20));

    wall.setFillColor(sf::Color::Black);

    while(fenetre.isOpen()) {
        while(fenetre.pollEvent(event)) { // boucle des événements

            //event pour pouvoir fermer la fenetre
            if(event.type == sf::Event::Closed) {
                fenetre.close();
            }
        }

        fenetre.clear(sf::Color::White);

        //dessine les Wall
        for (uint i = 0; i < NBLIGNES; ++i) {
            for (uint j = 0; j < NBCOL; ++j) {
                if (laby[i][j]=="*") {
                    wall.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(wall);
                }else if (laby[i][j]=="S") {
                    souris.setPosition(50 + j * 20, 50 + i * 20);
                    fenetre.draw(souris);
                }
                else if (laby[i][j]=="|") {
                    straight.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(straight);
                }
                else if (laby[i][j]=="┌") {
                    bottom_right.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(bottom_right);
                }
                else if (laby[i][j]=="└") {
                    top_right.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(top_right);
                }
                else if (laby[i][j]=="┘") {
                    top_left.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(top_left);
                }
                else if (laby[i][j]=="┐") {
                    bottom_left.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(bottom_left);
                }
                else if (laby[i][j]=="─") {
                    side.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(side);
                }
                else if (laby[i][j]=="F") {
                    cheese.setPosition(sf::Vector2f(50 + j * 20, 50 + i * 20));
                    fenetre.draw(cheese);
                }
            }
        }

        fenetre.display();
    }


    return 0;
}