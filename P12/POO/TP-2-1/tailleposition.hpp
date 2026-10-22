#pragma once

using coordonnee = int;

class position_t {

private:
  coordonnee _x;
  coordonnee _y;
public:
  position_t(coordonnee x, coordonnee y);
  position_t(const position_t & p);

  coordonnee x();
  void setx(coordonnee x);

  coordonnee y();
  void sety(coordonnee y);

  bool comparaison (const position_t & pos);
};


class taille_t {
private:
  coordonnee _largeur;
  coordonnee _hauteur;

public:
  taille_t(coordonnee l, coordonnee h);

  coordonnee largeur();
  void setlargeur(coordonnee l);

  coordonnee hauteur();
  void sethauteur(coordonnee h);

  bool comparaison (const taille_t & pos);

};
