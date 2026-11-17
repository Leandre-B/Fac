#include "carte.hh"
#include <iostream>

carte::carte() : _taille(0,0){}
carte::carte(taille_t const & taille) : _taille(taille){}

void carte::afficherpersonnages() const {
  std::cout<<_taille.tostring()<<"\n";
  for(personnage const & p : _personnages) {
    std::cout<<p.tostring()<<"\n";
  }
}


bool carte::intersectionelements(coordonnee a1, coordonnee a2, coordonnee b1, coordonnee b2) const {
  return !( b2 <= a1 ||  a2 <= b1);
}

bool carte::intersectionelements(element const & elem1, element const & elem2) const {
  int y1 = elem1.accesposition().y();
  int y1_ex = elem1.accesposition().y() + elem1.accestaille().hauteur();
  int y2 = elem2.accesposition().y();
  int y2_ex = elem2.accesposition().y() + elem2.accestaille().hauteur();

  int x1 = elem1.accesposition().x();
  int x1_ex = elem1.accesposition().x() + elem1.accestaille().largeur();
  int x2 = elem2.accesposition().x();
  int x2_ex = elem2.accesposition().x() + elem2.accestaille().largeur();

  return intersectionelements(y1, y1_ex, y2, y2_ex) && intersectionelements(x1, x1_ex, x2, x2_ex);
}

bool carte::emplacementlibre(position_t const &position,
                             taille_t const &taille) const {
  element elem(position, taille);
  if (position.x() < 0 or position.y() < 0 or
      position.x() + taille.largeur() > _taille.largeur() or
      position.y() + taille.hauteur() > _taille.hauteur())
    return false;

  /*
  for (auto const &p : _personnages) {
    if (intersectionelements(p, elem)) return false;
  }
*/

  for (auto const &obs : _obstacles) {
    if (intersectionelements(obs, elem))
      return false;
  }
  for (auto const &obj : _objetramassables) {
    if (intersectionelements(obj, elem))
      return false;
  }
  return true;
}


bool carte::deplacementpossible(personnage const & perso, direction const & dpl) const {
  switch(dpl) {
  case direction::nord :
    return emplacementlibre(position_t(perso.accesposition().x(), perso.accesposition().y()-1), perso.accestaille());
  case direction::sud :
    return emplacementlibre(position_t(perso.accesposition().x(), perso.accesposition().y()+1), perso.accestaille());
  case direction::est :
    return emplacementlibre(position_t(perso.accesposition().x()+1, perso.accesposition().y()), perso.accestaille());
  case direction::ouest :
    return emplacementlibre(position_t(perso.accesposition().x()-1, perso.accesposition().y()), perso.accestaille());
  }
  // Jamais atteint
  return false;
}

void carte::deplacement(personnage & perso, direction const & dpl) {
  switch(dpl) {
  case direction::nord :
    if(deplacementpossible(perso, direction::nord))
      perso.deplacer(position_t(perso.accesposition().x(), perso.accesposition().y() -1));
    break;

  case direction::sud :
    if(deplacementpossible(perso, direction::sud))
      perso.deplacer(position_t(perso.accesposition().x(), perso.accesposition().y() +1));
    break;

  case direction::est :
    if(deplacementpossible(perso, direction::est))
      perso.deplacer(position_t(perso.accesposition().x() +1, perso.accesposition().y()));
    break;

  case direction::ouest :
    if(deplacementpossible(perso, direction::ouest))
      perso.deplacer(position_t(perso.accesposition().x() -1, perso.accesposition().y()));
    break;
  }
}


bool carte::ramassagepossible(personnage const & perso, objetramassable const & obj) const {
  objetramassable obj_copie(
      position_t(obj.accesposition().x()-1, obj.accesposition().y()-1),
      taille_t(obj.accestaille().largeur()+2, obj.accestaille().hauteur()+2),
      obj.getPoints()
  );
  return intersectionelements(perso, obj_copie);
}

void carte::ramassertout(personnage & perso) {
  for(std::list<objetramassable>::iterator it = _objetramassables.begin(); it != _objetramassables.end();) {
    if(ramassagepossible(perso, *it)){
      //std::cout<<it->tostring()<<"\n";
      perso.ramasser(*it);
      it = _objetramassables.erase(it);
    }
    else
      it++;
  }
}
