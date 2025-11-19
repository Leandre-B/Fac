#pragma once

#include "get_plateau_xsb.h" //nécéssaire pour avoir la structure Plateau

bool deplacement(char direction,Plateau & plateau);
bool bloque(Plateau & plateau, int x, int y);