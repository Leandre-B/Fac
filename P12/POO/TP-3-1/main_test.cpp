#include <catch2/catch_test_macros.hpp>
#include "personnage.hpp"
#include "objetramassable.hpp"
#include "obstacle.hpp"

TEST_CASE("Q1 - Constructeur et accesseurs", "[Q1]") {
  element e(position_t(4, 2), taille_t(5, 3));

  CHECK(e.accesposition().x() == 4);
  CHECK(e.accesposition().y() == 2);
  CHECK(e.accestaille().largeur() == 5);
  CHECK(e.accestaille().hauteur() == 3);
}

TEST_CASE("Q1 - les accesseurs fonctionnent sur un element constant", "[Q1]") {
  element const e(position_t(1, 2), taille_t(3, 4));

  CHECK(e.accesposition().x() == 1);
  CHECK(e.accesposition().y() == 2);
  CHECK(e.accestaille().largeur() == 3);
  CHECK(e.accestaille().hauteur() == 4);
}

TEST_CASE("Q2 - element::tostring", "[Q2]") {
  element e(position_t(4, 2), taille_t(5, 3));

  CHECK(e.tostring() == "(4,2)[5,3]");
}

TEST_CASE("Q3 - contientposition (point à l'interieur)", "[Q3]") {
  element e(position_t(10, 20), taille_t(5, 3));

  CHECK(e.contientposition(position_t(12, 21)));
  CHECK(e.contientposition(position_t(13, 22)));
}

TEST_CASE("Q3 - contientposition (point à l'extérieur)", "[Q3]") {
  element e(position_t(10, 20), taille_t(5, 3));

  CHECK_FALSE(e.contientposition(position_t(9, 21)));
  CHECK_FALSE(e.contientposition(position_t(0, 21)));

  CHECK_FALSE(e.contientposition(position_t(16, 21)));
  CHECK_FALSE(e.contientposition(position_t(1000, 21)));

  CHECK_FALSE(e.contientposition(position_t(12, 19)));
  CHECK_FALSE(e.contientposition(position_t(12, 0)));

  CHECK_FALSE(e.contientposition(position_t(12, 24)));
  CHECK_FALSE(e.contientposition(position_t(12, 1000)));

  CHECK_FALSE(e.contientposition(position_t(5, 10))); // haut gauche
  CHECK_FALSE(e.contientposition(position_t(20, 10))); // haut droite
  CHECK_FALSE(e.contientposition(position_t(5, 30))); // bas gauche
  CHECK_FALSE(e.contientposition(position_t(20, 30))); // bas droite

  CHECK_FALSE(e.contientposition(position_t(12, 5)));
  CHECK_FALSE(e.contientposition(position_t(2, 21)));
}


TEST_CASE("Q4/5 :  personnage") {
  personnage perso(position_t(5,5), taille_t(2,4), "Jean");
  CHECK(perso.tostring() == "(5,5)[2,4] 0pts Jean");
}

TEST_CASE("Q4/5 : Constructeur obj rammassable") {
  objetramassable obj(position_t(5,5), taille_t(2,4), 12);
  CHECK(obj.tostring() == "obj rms (5,5)[2,4] 12pts");
}

TEST_CASE("Q4/5 : Constructeur obstacle") {
  obstacle obs(position_t(5,5), taille_t(2,4));
  CHECK(obs.tostring() == "obs (5,5)[2,4]");
}

TEST_CASE("Q6 : Rammassage") {
  objetramassable obj(position_t(5,5), taille_t(2,4), 12);
  personnage perso(position_t(5,5), taille_t(2,4), "Jean");
  perso.rammaser(obj);
  CHECK(perso.tostring() == "(5,5)[2,4] 12pts Jean");
}
