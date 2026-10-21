#include "tailleposition.hpp"

Position::Position(int x, int y) :
  x(x), y(y) {};

Position::Position(const Position & p)
    :x(p.x), y(p.y){};


int Position::getX(){
  return x;
}

void Position::setX(int x) {
  this->x = x;
}

int Position::getY(){
  return y;
}

void Position::setY(int y) {
  this->y =y;
}

bool Position::equals(const Position & p) {
  return this->x == p.x && this->y == p.y;
}
