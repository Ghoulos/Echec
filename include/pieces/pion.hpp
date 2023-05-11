#ifndef H_PION
#define H_PION

#include "../piece.hpp"
#include "../square.hpp"

class Pion : public Piece{
public:
    Pion(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );
};


#endif