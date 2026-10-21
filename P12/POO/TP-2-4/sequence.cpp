#include "sequence.hpp"
#include <iostream>


indicesequence Sequence::taille() {return _couleurs.size();}

void Sequence::ajouter(const Couleur & c){
  _couleurs.push_back(c);
}

Couleur Sequence::acces(indicesequence i) const{
  return _couleurs.at(i);
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
  for(const auto & c : _couleurs){
    afficher(c);
    sortie<<" ";
  }
}

bool Sequence::comparer(const Sequence & s) {
  return _couleurs == s._couleurs;
}

void Sequence::vider() {
  _couleurs.clear();
}

void Sequence::copier(const Sequence & s){
  _couleurs = s._couleurs;
}



