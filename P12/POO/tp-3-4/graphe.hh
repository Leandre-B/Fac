#pragma once
#include <list>
#include <ostream>
#include "sommet.hh"

class graphe {
    private:
        std::list<sommet> sommets;

    public:
        identifiant ajoutersommet(std::string const & etiquette);
        bool ajouterarc(identifiant id1, identifiant id2, std::string const & etiquette);
        void supprimersommet(identifiant id);
        void dot_sortie(std::ostream & flux) const;
};