#pragma once

#include<fstream>
#include <string>
#include <iostream>

struct Plateau{
    std::string nom;
    std::string chemin;
    std::string niveau;
    char** grille;
    int longueur;
    int hauteur;
    int x,y; //position personnage
    int nb_caisse;
    int score;
    bool bloque;
};

bool get_plateau(Plateau & plateau);

void affiche_plateau(Plateau plateau);

