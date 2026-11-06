#include "rectangle.hpp"
#include <iostream>

/*
 * O ----- A
 * |       |
 * |       |
 * |       |
 * C-------B
 *
 */

rectangle::rectangle() :
                       figuregeometrique(), _A(), _B() {
  std::cout<<"rectangle constructeur par défault\n";
}

rectangle::rectangle(figuregeometrique const & fig, point const & A, point const & B, point const & C) :
                                                                                                     figuregeometrique(fig), _A(A), _B(B), _C(C) {
  std::cout<<"rectangle constructeur avec parametres\n";
}

rectangle::rectangle(rectangle const & s) :
                                        figuregeometrique(s), _A(s._A), _B(s._B), _C(s._C){
  std::cout<<"rectangle constructeur par recopie\n";
}

rectangle::~rectangle(){
  std::cout<<"rectangle destructeur\n";
}

void rectangle::afficher() const{
  figuregeometrique::afficher(); std::cout<<", ";
  _A.afficher(); std::cout<<", ";
  _B.afficher(); std::cout<<", ";
  _C.afficher();
}

void rectangle::translation(point const & direction) {
  figuregeometrique::translation(direction);
  _A.translation(direction);
  _B.translation(direction);
  _C.translation(direction);
}

bool rectangle::estcarre1() const{
  return (_B.getX() - _C.getX()) == (_B.getY() - _A.getY());
}

bool rectangle::estcarre2() const{
  return estcarre1();
}
