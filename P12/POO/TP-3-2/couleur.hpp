#pragma once

class couleur {
private:
    short unsigned int _rouge;
    short unsigned int _vert;
    short unsigned int _bleu;
public :
    couleur(short unsigned int r, short unsigned int v, short unsigned int b ) : _rouge(r), _vert(v), _bleu(b){};
};
