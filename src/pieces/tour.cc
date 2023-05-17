#include "../../include/pieces/tour.hpp"

Tour::Tour(couleur_t color, int id, Square* pos) :
Piece(color, (color == Blanc) ? "\u265C" : "\u2656", id, pos) {}

bool Tour::mouvement_legal(Square dest, bool mouvementCapture) {
    Square* caseInit = this->position;

    if (dest.getX() != caseInit->getX() && dest.getY() != caseInit->getY()){
        return false;
    }
    return true;
}