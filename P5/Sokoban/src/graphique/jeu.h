#pragma once

#include "menu.h"
#include "../plateau/deplacement.h"
#include "../IA/a_star.h"
#include "../IA/ia.h"


//pour sleep
#include <chrono>
#include <thread>

bool fenetre_jeu(sf::RenderWindow & fenetre,sf::Event & event, sf::View & view, Plateau plateau, bool & end,std::string skin);
