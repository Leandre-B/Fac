#pragma once
#include "figuregeometrique.hpp"

class triangle : public figuregeometrique{
private:
  point _A;
  point _B;

public:
  triangle();
  triangle(figuregeometrique const & fig, point const & A, point const & B);
  triangle(triangle const & s);
  ~triangle();

  void afficher() const;
  void translation(point const & direction);
  std::string typefigure() const override { return "tri";}
};
