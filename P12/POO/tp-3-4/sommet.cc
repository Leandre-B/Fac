#include "sommet.hh"

identifiant sommet::_id_compteur = 0;

sommet::sommet(std::string const & etiquette) : _identifiant(_id_compteur++), _etiquette(etiquette)
{
}


void sommet::ajoutearc(identifiant id, std::string const & etiquette) {
  for(arcsortant & a : _arcsortants) {
    if(a.id == id){
      a.etiquette = etiquette;
      return;
    }
  }
  // sinon l'arc n'existe pas
  _arcsortants.emplace_front(arcsortant{id, etiquette});
}

void sommet::supprimerarc(identifiant id, std::string const & etiquette) {
  for(auto it = _arcsortants.begin(); it != _arcsortants.end(); it++) {
    if(it->id == id)
      _arcsortants.erase(it);
    else
        ++it;
  }
}

