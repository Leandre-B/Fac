#pragma once

#include "carte.hh"
#include <SFML/Graphics.hpp>

class affichage_carte {
public:
	enum class action {
		nord,
		sud,
		est,
		ouest,
		ramasser,
		selectionner,
		rien
	};

	affichage_carte(unsigned int largeur, unsigned int hauteur, unsigned int zoom = 16);
	bool fenetre_ouverte() const;
	bool recuperer_action_joueur(action& aj, unsigned int& x, unsigned int& y);
	void affichage_commencer();
	void afficher(carte const& c, personnage const* selectionne = nullptr);
	void affichage_terminer();

private:
	float echelle(coordonnee valeur) const;
	sf::Vector2f position_pixel(::position_t const& p) const;
	sf::Vector2f taille_pixel(::taille_t const& t) const;

	unsigned int _zoom;
	sf::RenderWindow _fenetre;
};
