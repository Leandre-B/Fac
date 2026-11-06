#include "figuregeometrique.hpp"
#include <iostream>

figuregeometrique::figuregeometrique():_origine(), _couleur()
{
    std::cout<<"figure constructeur par défault\n";
};

figuregeometrique::figuregeometrique(figuregeometrique const & fig) : _origine(fig._origine), _couleur(fig._couleur){
    std::cout<<"figure constructeur par copie\n";
};
figuregeometrique::figuregeometrique(point const & origine, couleur const & c) : _origine(origine), _couleur(c){
    std::cout<<"figure constructeur o c !!!\n";
};
figuregeometrique::~figuregeometrique() {
    std::cout<<"figure destruction !!!\n";
}

void figuregeometrique::afficher() const{
  std::cout<<typefigure()<<"("<<_couleur._rouge<<","<<_couleur._vert<<","<<_couleur._bleu<<"), ";
  _origine.afficher();
}

bool figuregeometrique::memeorigine(figuregeometrique const & f) const{
  return _origine.equals(f._origine);
}

void figuregeometrique::translation(point const & direction) {
  _origine.translation(direction);
}
