#pragma once

using Coordonee = int;

class Position {
private:
  Coordonee x;
  Coordonee y;

public:
  Position(Coordonee x, Coordonee y);
  Position(const Position & p);

  Coordonee getX();
  void setX(Coordonee x);

  Coordonee getY();
  void setY(Coordonee y);

  bool equals(const Position & p);

};


class Taille {
private:
  Coordonee largeur;
  Coordonee hauteur;

public:
  Taille(Coordonee l, Coordonee h);

  Coordonee getHauteur();
  void setHauteur(Coordonee h);

  Coordonee getLargeur();
  void setLargeur(Coordonee l);

  bool equals(const Taille & t);
};
