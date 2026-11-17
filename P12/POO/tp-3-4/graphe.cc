#include "graphe.hh"
#include "sommet.hh"
#include <cstddef>


identifiant graphe::ajoutersommet(std::string const & etiquette) {
    sommets.push_front(sommet(etiquette));
    return sommets.front().id();
}

bool graphe::ajouterarc(identifiant id1, identifiant id2, std::string const & etiquette) {
    bool found = true;
    sommet* depart = nullptr;
    for(auto & s : sommets) {
        if(s.id() == id1) {
            found = !found;
            depart = &s;
        }else if(s.id()==id2) found = !found;
    }
    if(found) {
        depart->ajoutearc(id2, etiquette);
    }
    return found;
}

void graphe::supprimersommet(identifiant id) {
    for(auto it = sommets.begin(); it != sommets.end();) {
        if(it->id() == id) {
            it = sommets.erase(it);
        }else{
            it->supprimerarc(id);
            ++it;
        }
    }
}

void graphe::dot_sortie(std::ostream & flux) const{
    flux << "Digraph G {\n";
    for(auto const & s : sommets) {
        s.dot_etiquette(flux);flux<<"\n";
        s.dot_arcssortants(flux);flux<<"\n";
    }
    flux <<"}\n";
}