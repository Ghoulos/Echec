#include "../../include/pieces/tour.hpp"

Tour::Tour(couleur_t color, int id, Square* pos) :
Piece(color, (color == Noir) ? "\u265C" : "\u2656", id, pos) {}

bool Tour::mouvement_legal(Square dest, bool mouvementCapture) {
    Square* start = this->position;

    if (dest.getX() != start->getX() && dest.getY() != start->getY()){
        return false;
    }

    return true;
}