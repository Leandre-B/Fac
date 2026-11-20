#pragma once
#include "entite.hh"

class obstacle : public entite {
public:
  obstacle(identifiant id, position const &pos) : entite(id, pos) {};
  char symbole() const override { return '#'; }

private:
};
