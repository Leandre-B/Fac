#include "affichage_carte.hh"

#include <algorithm>

namespace {
const sf::Color couleur_fond(238, 242, 247);
const sf::Color couleur_grille(208, 216, 226);
const sf::Color couleur_obstacle(105, 113, 122);
const sf::Color couleur_objet(47, 166, 91);
const sf::Color couleur_personnage(55, 104, 180);
const sf::Color couleur_selection(245, 183, 66);
}

affichage_carte::affichage_carte(unsigned int largeur, unsigned int hauteur, unsigned int zoom)
	: _zoom(zoom)
	, _fenetre(sf::VideoMode(largeur * zoom, hauteur * zoom), "Carte") {
	_fenetre.setFramerateLimit(60);
}

bool affichage_carte::fenetre_ouverte() const {
	return _fenetre.isOpen();
}

bool affichage_carte::recuperer_action_joueur(action& aj, unsigned int& x, unsigned int& y) {
	aj = action::rien;
	sf::Event evenement;
	while (_fenetre.pollEvent(evenement) && aj == action::rien) {
		if (evenement.type == sf::Event::Closed
			|| (evenement.type == sf::Event::KeyPressed
				&& evenement.key.code == sf::Keyboard::Escape)) {
			_fenetre.close();
		} else if (evenement.type == sf::Event::KeyPressed) {
			switch (evenement.key.code) {
			case sf::Keyboard::Up:
				aj = action::nord;
				break;
			case sf::Keyboard::Down:
				aj = action::sud;
				break;
			case sf::Keyboard::Right:
				aj = action::est;
				break;
			case sf::Keyboard::Left:
				aj = action::ouest;
				break;
			case sf::Keyboard::R:
				aj = action::ramasser;
				break;
			default:
				break;
			}
		} else if (evenement.type == sf::Event::MouseButtonPressed
			&& evenement.mouseButton.button == sf::Mouse::Left) {
			x = static_cast<unsigned int>(evenement.mouseButton.x) / _zoom;
			y = static_cast<unsigned int>(evenement.mouseButton.y) / _zoom;
			aj = action::selectionner;
		}
	}
	return aj != action::rien;
}

void affichage_carte::affichage_commencer() {
	_fenetre.clear(couleur_fond);
}

void affichage_carte::afficher(carte const& c, personnage const* selectionne) {
	for (auto const& o : c.obstacles()) {
		sf::RectangleShape forme(taille_pixel(o.accestaille()));
		forme.setPosition(position_pixel(o.accesposition()));
		forme.setFillColor(couleur_obstacle);
		forme.setOutlineColor(sf::Color::Black);
		forme.setOutlineThickness(-1.f);
		_fenetre.draw(forme);
	}

	for (auto const& o : c.objets()) {
		auto const largeur = echelle(o.accestaille().largeur());
		auto const hauteur = echelle(o.accestaille().hauteur());
		sf::CircleShape forme(0.5f * std::min(largeur, hauteur));
		forme.setPosition(position_pixel(o.accesposition()));
		forme.setFillColor(couleur_objet);
		forme.setOutlineColor(sf::Color(20, 91, 48));
		forme.setOutlineThickness(-1.f);
		_fenetre.draw(forme);
	}

	for (auto const& p : c.personnages()) {
		auto const largeur = echelle(p.accestaille().largeur());
		auto const hauteur = echelle(p.accestaille().hauteur());
		bool est_selectionne = selectionne == &p;
		sf::RectangleShape corps(sf::Vector2f(largeur, 0.72f * hauteur));
		corps.setPosition(position_pixel(p.accesposition()) + sf::Vector2f(0, 0.28f * hauteur));
		corps.setFillColor(couleur_personnage);
		corps.setOutlineColor(est_selectionne ? couleur_selection : sf::Color::Black);
		corps.setOutlineThickness(est_selectionne ? -2.f : -1.f);
		_fenetre.draw(corps);

		sf::CircleShape tete(0.24f * std::min(largeur, hauteur));
		tete.setPosition(position_pixel(p.accesposition()) + sf::Vector2f(0.5f * largeur - 0.24f * std::min(largeur, hauteur), 0));
		tete.setFillColor(sf::Color(244, 198, 157));
		_fenetre.draw(tete);
	}
}

void affichage_carte::affichage_terminer() {
	_fenetre.display();
}

float affichage_carte::echelle(coordonnee valeur) const {
	return static_cast<float>(valeur * _zoom);
}

sf::Vector2f affichage_carte::position_pixel(::position_t const& p) const {
	return sf::Vector2f(echelle(p.x()), echelle(p.y()));
}

sf::Vector2f affichage_carte::taille_pixel(::taille_t const& t) const {
	return sf::Vector2f(echelle(t.largeur()), echelle(t.hauteur()));
}
