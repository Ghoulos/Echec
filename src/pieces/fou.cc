#include "../../include/pieces/fou.hpp"

Fou::Fou(couleur_t color,int id,Square *pos)
    : Piece(color,(color == Blanc) ? "\u265D" : "\u2657",id,pos){}

bool Fou::mouvement_legal(Square dest, bool mouvementCapture) {
    if (abs(dest.getY() - this->position->getY()) 
            != abs(dest.getX() - this->position->getX())){
        return false;
    }
    return true;
}