#pragma once
#include "figuregeometrique.hpp"

class rectangle : public figuregeometrique{
private:
  point _A;
  point _B;
  point _C;

public:
  rectangle();
  rectangle(figuregeometrique const & fig, point const & A, point const & B, point const & C);
  rectangle(rectangle const & s);
  ~rectangle();

  void afficher() const;
  void translation(point const & direction);
  bool estcarre1() const;
  bool estcarre2() const;
  std::string typefigure() const override { return "rec";}
};
