#pragma once
#include "couleur.hpp"
#include "point.hpp"

class figuregeometrique
{
private:
    point _origine;
    couleur _couleur;
public:
    figuregeometrique();
    figuregeometrique(figuregeometrique const & fig);
    figuregeometrique(point const & origine, couleur const & c);
    ~figuregeometrique();
};
