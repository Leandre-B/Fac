#pragma once
#include "couleur.hpp"
#include "point.hpp"
#include <string>

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

    void afficher() const;
    bool memeorigine(figuregeometrique const & f) const;
    void translation(point const & direction);
    bool estcarre2() const { return false;};
    virtual std::string typefigure() const { return "fig";};
};
