#include "segment.hpp"
#include <iostream>

segment::segment() :
                     figuregeometrique(), _extremite() {
  std::cout<<"Seg constructeur par défault\n";
}

segment::segment(figuregeometrique const & fig, point const & extremite) :
                                                                                   figuregeometrique(fig), _extremite(extremite) {
  std::cout<<"Seg constructeur avec parametres\n";
}
// Un peu étonnant que figuregeometrique(s) fonctionne non ... ? A voir plus en détail
segment::segment(segment const & s) :
                                     figuregeometrique(s), _extremite(s._extremite){
  std::cout<<"Seg constructeur par recopie\n";
}

segment::~segment(){
  std::cout<<"Seg destructeur\n";
}

void segment::afficher() const{
  figuregeometrique::afficher(); std::cout<<", ";
  _extremite.afficher();
}

void segment::translation(point const & direction) {
  figuregeometrique::translation(direction);
  _extremite.translation(direction);
}
