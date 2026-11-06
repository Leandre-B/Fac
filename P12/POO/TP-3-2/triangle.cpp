#include "triangle.hpp"
#include <iostream>

triangle::triangle() :
                       figuregeometrique(), _A(), _B() {
  std::cout<<"Triangle constructeur par défault\n";
}

triangle::triangle(figuregeometrique const & fig, point const & A, point const & B) :
                                                                         figuregeometrique(fig), _A(A), _B(B) {
  std::cout<<"Triangle constructeur avec parametres\n";
}

triangle::triangle(triangle const & s) :
                                     figuregeometrique(s), _A(s._A), _B(s._B){
  std::cout<<"Triangle constructeur par recopie\n";
}

triangle::~triangle(){
  std::cout<<"Triangle destructeur\n";
}

void triangle::afficher() const{
  figuregeometrique::afficher(); std::cout<<", ";
  _A.afficher(); std::cout<<", ";
  _B.afficher();
}

void triangle::translation(point const & direction) {
  figuregeometrique::translation(direction);
  _A.translation(direction);
  _B.translation(direction);
}
