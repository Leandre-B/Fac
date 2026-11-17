#pragma once

class taille {
private:
  unsigned int _w;
  unsigned int _h;

public:
  taille(unsigned int w, unsigned int h) : _w(w), _h(h) {};
  unsigned int w() const { return _w; };
  unsigned int h() const { return _h; };
  void setw(unsigned int w) { _w = w; };
};
