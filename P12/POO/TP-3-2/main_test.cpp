#include "figuregeometrique.hpp"
#include <iostream>
#include "segment.hpp"
#include "rectangle.hpp"

int main() {
/*
  std::cout<<"fig1\n";
  figuregeometrique fig1;

  std::cout<<"\nfig2\n";
  figuregeometrique fig2(point(3,3), couleur{255,0,255});
  */
  std::cout<<"\nfig3\n";
  figuregeometrique fig3(point(3,3), couleur{255,0,255});
  fig3.afficher();

  std::cout<<"\nseg1\n";
  segment s1;

  std::cout<<"\nseg2\n";
  segment s2(figuregeometrique(point(3,3), couleur{255,0,255}), point(4,4));

  std::cout<<"\nseg3\n";
  segment s3(s2);

  std::cout<<"\nrectangle1\n";
  rectangle rectangle1(figuregeometrique(point(3,3), couleur{255,0,255}), point(5,3), point(5,5), point(3,5));
  rectangle1.afficher();
  std::cout<<rectangle1.estcarre2()<<"\n";
  std::cout<<s3.estcarre2()<<"\n";

  std::cout<<"\nfin du programme ! \n";

  return 0;
}
