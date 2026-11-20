// #include "bomberman_v1.hh"
#include "plateau.hh"
#include <unistd.h>

int main() {
  const int L(25), H(17);
  plateau p(position(L, H));
  identifiant id(0);
  for (coord x = 0; x < L; ++x) {
    p.ajouter(obstacle(id++, position(x, 0)));
    p.ajouter(obstacle(id++, position(x, H - 1)));
  }
  for (coord y = 0; y < H; ++y) {
    p.ajouter(obstacle(id++, position(0, y)));
    p.ajouter(obstacle(id++, position(L - 1, y)));
  }
  p.ajouter(obstacle(id++, position(3, 8)));
  p.ajouter(bombe(id++, position(3, 6), 5));
  p.ajouter(bonus(id++, position(18, 12), bonus_type::vie_supplementaire));
  p.sortie_flux(std::cout);
  for (unsigned int i = 0; i < 45; ++i) {
    if (i == 10)
      p.ajouter(bombe(id++, position(8, 6), 8));
    else if (i == 15)
      p.ajouter(bombe(id++, position(8, 12), 10));
    // p.sortie_flux(std::cout);
    std::cout << i << "\n";
    std::list<position> expl;
    p.etat_suivant(expl);
    p.sortie_graphique(std::cout, expl);
    usleep(200000);
  }
  return 0;
}
