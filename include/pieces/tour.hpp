#ifndef H_TOUR
#define H_TOUR

#include "../piece.hpp"
#include "../square.hpp"

class Tour : public Piece{
public:
    Tour(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );
};


#endif