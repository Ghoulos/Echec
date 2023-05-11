#ifndef CAVALIER_H
#define CAVALIER_H

#include "../piece.hpp"
#include "../square.hpp"

class Cavalier : public Piece{
public:
    Cavalier(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );
};


#endif