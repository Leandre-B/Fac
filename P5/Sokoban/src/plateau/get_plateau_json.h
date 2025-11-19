#pragma once

#include<fstream>
#include <string>
#include <iostream>
#include "get_plateau_xsb.h"

//extern Plateau plateau;

bool get_plateau_json(Plateau & plateau);
void remplie_plateau(char** & grille, int y,int x);