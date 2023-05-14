#include "../../include/pieces/reine.hpp"

Reine::Reine(couleur_t color,int id,Square *pos)
    : Piece(color,(color == Noir) ? "\u265B" : "\u2655",id,pos){}

bool Reine::mouvement_legal(Square dest, bool mouvementCapture){
    if (abs(dest.getY() - this->position->getY()) == abs(dest.getX() - this->position->getX())){
        return true;
    }
    if (dest.getY() == this->position->getY() || dest.getX() == this->position->getX()){
        return true;
    }

    return false;
}