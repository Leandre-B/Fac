#include "sommet.hh"

identifiant sommet::_id_compteur = 0;

sommet::sommet(std::string const & etiquette) : _identifiant(++_id_compteur), _etiquette(etiquette)
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

void sommet::supprimerarc(identifiant id) {
  for(auto it = _arcsortants.begin(); it != _arcsortants.end();) {
    if(it->id == id)
      it = _arcsortants.erase(it);
    else
      ++it;
  }
}

void sommet::supprimertousarc() {
  _arcsortants.clear();
}

void sommet::dot_etiquette(std::ostream & flux) const{
  flux << "c"<<_identifiant << " [label=\""<<_etiquette<<"\"] ;";
}

void sommet::dot_arcssortants(std::ostream & flux) const{
  for(auto const & arc : _arcsortants) {
    if(arc.etiquette == "")
      flux << "c"<<_identifiant <<" -> c"<<arc.id<<"; ";
    else
      flux << "c"<<_identifiant <<" -> c"<<arc.id<<" [label=\""<<arc.etiquette<<"\"] ;";
  }
}