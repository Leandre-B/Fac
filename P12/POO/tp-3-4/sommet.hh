#pragma once
#include <string>
#include <list>

using identifiant = unsigned int;

class sommet {
private:
  static identifiant _id_compteur;

  struct arcsortant { identifiant id; std::string etiquette;};


  identifiant _identifiant;
  std::string _etiquette;
  std::list<arcsortant> _arcsortants;

public:
  sommet(std::string const & etiquette);

  identifiant id() const {return _identifiant;};
  std::string etiquette() const {return _etiquette;};
  void ajoutearc(identifiant id, std::string const & etiquette);
  void supprimerarc(identifiant id, std::string const & etiquette);



};

