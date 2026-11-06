#pragma once
#include "figuregeometrique.hpp"

class segment : public figuregeometrique{
private:
  point _extremite;

public:
  segment();
  segment(figuregeometrique const & fig, point const & extremite);
  segment(segment const & s);
  ~segment();

  void afficher() const;
  void translation(point const & direction);
  std::string typefigure() const override { return "seg";}
};
