#ifndef FOU_H
#define FOU_H

#include "../piece.hpp"
#include "../square.hpp"

class Fou : public Piece{
public:
    Fou(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );

};


#endif 