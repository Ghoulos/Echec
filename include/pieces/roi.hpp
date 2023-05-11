#ifndef ROI_H
#define ROI_H

#include "../piece.hpp"
#include "../square.hpp"

#include <iostream>

using namespace std;

class Roi : public Piece{
public:
    Roi(couleur_t c,int id,Square* pos);

    bool mouvement_legal(Square , bool );
};


#endif