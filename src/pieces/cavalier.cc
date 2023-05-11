#include "../../include/pieces/cavalier.hpp"

Cavalier::Cavalier(couleur_t color,int id,Square* pos)
    : Piece(color,(color == Noir) ? "\u265E" : "\u2658",id,pos){}

bool Cavalier::mouvement_legal(Square dest, bool isCatch){
    if (((abs(dest.getX() - this->position->getX()) == 2) && (abs(dest.getY() - this->position->getY()) == 1))
        || ((abs(dest.getX() - this->position->getX()) == 1) && (abs(dest.getY() - this->position->getY()) == 2))){
        return true;
    }
    return false;
}