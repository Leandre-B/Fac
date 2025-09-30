#pragma once
#include <iostream>
#include <array>

#include <cstdlib>
#include <ctime>

using uint =  unsigned int;
const uint NBLIGNES = 40;
const uint NBCOL = 40;

using Labyrinthe = std::array<std::array<std::string, NBCOL>, NBLIGNES>;

Labyrinthe labyDessinConsole();