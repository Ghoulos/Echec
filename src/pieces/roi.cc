#include "../../include/pieces/roi.hpp"

Roi::Roi(couleur_t color,int id,Square *pos)
    : Piece(color,(color == Noir) ? "\u265A" : "\u2654",id,pos){
}

bool Roi::mouvement_legal(Square dest, bool isCatch){
    if ((abs(dest.getY() - this->position->getY()) > 1)
        || (abs(dest.getX() - this->position->getX()) > 1)){
        return false;
    }
    return true;
}