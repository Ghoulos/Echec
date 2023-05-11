#ifndef REINE_H
#define REINE_H

#include "../piece.hpp"
#include "../square.hpp"

#include <iostream>

using namespace std;

class Reine : public Piece{
public:
    Reine(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );
};


#endif