#include "affichage_carte.hh"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace {
position_t position_aleatoire(carte const& c, taille_t const& tai) {
	coordonnee largeur = c.accestaille().largeur() - tai.largeur() + 1;
	coordonnee hauteur = c.accestaille().hauteur() - tai.hauteur() + 1;
	return position_t(static_cast<coordonnee>(std::rand()) % largeur,
		static_cast<coordonnee>(std::rand()) % hauteur);
}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	carte c(taille_t(64, 40));

	// 30 obstacles de taille minimum 2x1
	for (unsigned int i = 0; i < 30; ++i) {
		taille_t tai(2 + std::rand() % 5, 1 + std::rand() % 3);
		for (unsigned int tentative = 0; tentative < 1000; ++tentative) {
			position_t pos = position_aleatoire(c, tai);
			if (c.emplacementlibre(pos, tai)) {
				c.ajouter(obstacle(pos, tai));
				break;
			}
		}
	}

	// 12 objets ramassables de taille minimum 1x1
	for (unsigned int i = 0; i < 12; ++i) {
		for (unsigned int tentative = 0; tentative < 1000; ++tentative) {
			taille_t tai(1 + rand() % 2, 1 + rand() % 2);
			position_t pos = position_aleatoire(c, tai);
			if (c.emplacementlibre(pos, tai)) {
				c.ajouter(objetramassable(pos, tai, 5 + std::rand() % 20));
				break;
			}
		}
	}

	// 3 personnages de taille minimum 2x2
	std::vector<personnage*> personnages;
	for (unsigned int i = 0; i < 3; ++i) {
		for (unsigned int tentative = 0; tentative < 1000; ++tentative) {
			taille_t tai(2 + rand() % 2, 2 + rand() % 2);

			position_t pos = position_aleatoire(c, tai);
			if (c.emplacementlibre(pos, tai)) {
				personnages.push_back(c.ajouter(
					personnage(pos, tai, "Joueur" + std::to_string(i + 1))));
				break;
			}
		}
	}

	personnage* selectionne = personnages.empty() ? nullptr : personnages.front();
	affichage_carte affichage(c.accestaille().largeur(), c.accestaille().hauteur());
	while (affichage.fenetre_ouverte()) {
		affichage_carte::action action;
		unsigned int x = 0;
		unsigned int y = 0;
		while (affichage.recuperer_action_joueur(action, x, y)) {
			if (action == affichage_carte::action::selectionner) {
				position_t clic(x, y);
				for (auto* p : personnages)
					if (p->contientposition(clic))
						selectionne = p;
			} else if (selectionne != nullptr) {
				switch (action) {
				case affichage_carte::action::nord:
					c.deplacement(selectionne, direction::nord);
					break;
				case affichage_carte::action::sud:
					c.deplacement(selectionne, direction::sud);
					break;
				case affichage_carte::action::est:
					c.deplacement(selectionne, direction::est);
					break;
				case affichage_carte::action::ouest:
					c.deplacement(selectionne, direction::ouest);
					break;
				case affichage_carte::action::ramasser:
					c.ramassertout(*selectionne);
					break;
				case affichage_carte::action::selectionner:
				case affichage_carte::action::rien:
					break;
				}
			}
		}

		affichage.affichage_commencer();
		affichage.afficher(c, selectionne);
		affichage.affichage_terminer();
	}

	if (selectionne != nullptr)
		std::cout << selectionne->nom() << " : " << selectionne->nbpoints() << " points\n";
}
