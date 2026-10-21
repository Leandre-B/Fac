#include "sequence.hpp"
#include <iostream>

Sequence::Sequence() :
                       _couleurs(nullptr), _taille(0){}

Sequence::Sequence(const Sequence & s):_taille(s._taille) {
  _couleurs = new Couleur[_taille];
  for(indicesequence i = 0; i < _taille; ++i) {
    _couleurs[i] = s._couleurs[i];
  }
}

Sequence::~Sequence() {
  if(_couleurs != nullptr)
    delete[] _couleurs;
}

indicesequence Sequence::taille() {return _taille;}

void Sequence::ajouter(const Couleur & c){
  Couleur* save = new Couleur[_taille];
  for(indicesequence i=0; i<_taille; ++i) {
    save[i] = _couleurs[i];
  }

  delete [] _couleurs;  _couleurs = nullptr;
  _taille++;
  _couleurs = new Couleur[_taille];

  for(indicesequence i=0; i<_taille - 1; ++i) {
    _couleurs[i] = save[i];
  }

  _couleurs[_taille -1] = c;
  delete [] save; save = nullptr;
}

Couleur Sequence::acces(indicesequence i) const{
  // if(i >= _taille)
  //  return Couleur::None;
  return _couleurs[i];
}


void Sequence::afficher(const Couleur & c){
  switch (c) {
    case Couleur::Bleu: std::cout<<"bleu"; break;
    case Couleur::Jaune: std::cout<<"jaune"; break;
    case Couleur::Rouge: std::cout<<"rouge"; break;
    case Couleur::Vert: std::cout<<"vert"; break;
    // case Couleur::None: std::cout<<""; break;
  }
}


void Sequence::afficher(std::ostream & sortie) {
  /* ? parce que sinon pas grand intéret.... Mais ça reste cool
    switch (c) {
      case Couleur::Bleu: sortie<<"bleu"; break;
      case Couleur::Jaune: sortie<<"jaune"; break;
      case Couleur::Rouge: sortie<<"rouge"; break;
      case Couleur::Vert: sortie<<"vert"; break;
    }
  */
  for(indicesequence i = 0; i<_taille; ++i){
    Sequence::afficher(_couleurs[i]);
    sortie<<" ";
  }
}

bool Sequence::comparer(const Sequence & s) {
  if(_taille != s._taille) return false;
  for(indicesequence i = 0; i < _taille; ++i) {
    if(acces(i) != s.acces(i))
      return false;
  }
  return true;
}

void Sequence::vider() {
  delete[] _couleurs;
  _couleurs = nullptr;
  _taille = 0;
}

void Sequence::copier(const Sequence & s){
  delete _couleurs;
  _taille = s._taille;
  _couleurs = new Couleur[_taille];
  for(indicesequence i = 0; i < _taille; ++i) {
    _couleurs[i] = s._couleurs[i];
  }
}



