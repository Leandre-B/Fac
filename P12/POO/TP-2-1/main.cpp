#include <iostream>
#include "tailleposition.hpp"

int main() {
  position_t p1(1,4);
  position_t p2(p1);

  std::cout<<p1.comparaison(p2)<<"\n";
  std::cout<<p1.x()<<" "<<p1.y()<<"\n";

  p1.sety(1);
  std::cout<<p1.comparaison(p2)<<"\n";
  std::cout<<p1.x()<<" "<<p1.y()<<"\n";


  taille_t t1(4,5);
  taille_t t2(4,1);

  std::cout<<t1.comparaison(t2)<<"\n";
  std::cout<<t1.hauteur()<<" "<<t1.largeur()<<"\n";

  t2.sethauteur(5);
  std::cout<<t1.comparaison(t2)<<"\n";
  std::cout<<t2.hauteur()<<" "<<t2.largeur()<<"\n";

  return 0;
}
