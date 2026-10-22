#include "grille.hh"

#include <iostream>

Grille::Grille(Coordonnee lon, Coordonnee lar) : _grille(lar, t_colonne(lon, EtatCellule::Mort))
{
}

void Grille::vider()
{
	_grille = t_grille(_grille.size(), t_colonne(_grille[0].size(), EtatCellule::Mort));
}

bool Grille::dansGrille(Coordonnee x, Coordonnee y) const
{
	return x >= 0 && x < _grille[0].size() && y >= 0 && y < _grille.size();
}

bool Grille::vivante(Coordonnee x, Coordonnee y) const
{
	if (dansGrille(x, y))
		return _grille[y][x] == EtatCellule::Vivant;
	return 0;
}
void Grille::generer(Coordonnee x, Coordonnee y)
{
	if (dansGrille(x, y))
		_grille[y][x] = EtatCellule::Vivant;
}

void Grille::tuer(Coordonnee x, Coordonnee y)
{
	_grille[y][x] = EtatCellule::Mort;
}

void Grille::afficher() const
{
	for (const auto& col : _grille)
	{
		for (const auto& cell : col)
		{
			if (cell == EtatCellule::Vivant)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
}

void Grille::ajouterStructure(const Structure& s, Coordonnee x, Coordonnee y)
{
	std::vector<std::vector<Coordonnee>> coords;
	switch (s)
	{
		case Structure::OscillateurLigne:
			coords = {{0, 0}, {1, 0}, {2, 0}};
			break;

		case Structure::Floraison:
			coords = {
				{1, 0}, {2, 0}, {3, 0}, {0, 1}, {2, 1}, {4, 1}, {1, 2}, {2, 2}, {3, 2}};
			break;

		case Structure::Planeur:
			coords = {
				{0, 0}, {1, 0}, {2, 0}, {2, 1}, {1, 2}};
			break;

		case Structure::OscillateurCroix:
			coords = {
				{1, 0},
				{0, 1},
				{1, 1},
				{2, 1},
				{1, 2}};
			break;
	}

	for (auto c : coords)
		generer(c[0] + x, c[1] + y);
}

int Grille::vivantes(Coordonnee x, Coordonnee y) const
{
	int tot = 0;
	for (Coordonnee i = x; i <= x + 2; ++i)
	{
		for (Coordonnee j = y; j <= y + 2; ++j)
		{
			if (!(i == x + 1 && j == y + 1) && j != 0 && i != 0)
			{
				tot += vivante(i - 1, j - 1);
			}
		}
	}
	return tot;
}

void Grille::evolution(Grille& g)
{
	for (Coordonnee y = 0; y < _grille.size(); ++y)
	{
		for (Coordonnee x = 0; x < _grille[y].size(); ++x)
		{
			int nbVoisins = vivantes(x, y);
			if (!vivante(x, y))
			{
				if (nbVoisins == 3)
					g.generer(x, y);
				else
					g.tuer(x, y);
			}
			else if (vivante(x, y))
			{
				if (nbVoisins <= 1 || nbVoisins >= 4)
					g.tuer(x, y);
				else
					g.generer(x, y);
			}
		}
	}
}
