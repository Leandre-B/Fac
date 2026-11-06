#pragma once
#include "element.hpp"


class obstacle : public element{
public:
  obstacle(position_t const & position, taille_t const & taille);
  std::string tostring() const;
};

