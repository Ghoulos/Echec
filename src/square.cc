#include "../include/square.hpp"

Square::Square(int x, int y, Piece * piece = nullptr)
    : Pos(x,y), piece(piece){}

Square::~Square() {}

bool Square::estVide() {return (this->piece == nullptr);}

void Square::affiche(){
    if (estVide())
    {
        cout << string(5,' ');
    }
    else {
        cout << "\u0020\u0020";
        piece->affiche();
        cout << "\u0020" << " ";
    }
    
}

void Square::setPiece(Piece * piece) { this->piece = piece; }

Piece* Square::getPiece() const { return this->piece; }