#include "point.hpp"
#include <iostream>

point::point() : _x(0), _y(0){
    std::cout<<"point constructeur par défault\n";
}
point::point(coordonee x, coordonee y) :_x(x), _y(y) {
    std::cout<<"point constructeur x y\n";
}
point::point(point const & p) : _x(p._x), _y(p._y) {
    std::cout<<"point constructeur par recopie\n";
}
point::~point(){
    std::cout<<"point destructeur\n";
}


void point::afficher() const {
  std::cout<<"("<< _x <<","<< _y <<")";
}

bool point::equals(point const & p) const {
  return _x == p._x && _y == p._y;
}

void point::translation(point const & direction) {
  _x += direction._x;
  _y += direction._y;
}
