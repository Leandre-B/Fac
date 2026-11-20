#pragma once
#include "entite.hh"

enum class bonus_type {
  amelioration_portee,
  amelioration_nombre,
  vie_supplementaire
};

class bonus : public entite {
public:
  bonus(identifiant id, position const &pos, bonus_type const &bonus)
      : entite(id, pos), _bonus_type(bonus) {};

  bonus_type const &type() const { return _bonus_type; };

  char symbole() const override {
    switch (_bonus_type) {
    case bonus_type::amelioration_portee:
      return 'P';
    case bonus_type::amelioration_nombre:
      return 'N';
    case bonus_type::vie_supplementaire:
      return 'V';
    }
    return ' '; // jamais atteind
  }

private:
  bonus_type _bonus_type;
};
