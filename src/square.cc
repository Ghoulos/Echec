#include "../include/square.hpp"

Square::Square(int x, int y, Piece * piece)
    : Pos(x,y), piece(piece){}

Square::Square(string pos, Piece * piece)
    : Pos(pos), piece(piece){}

Square::~Square() {}

bool Square::est_vide() {return (piece == nullptr);}

void Square::affiche(){
    if (est_vide())
    {
        cout << "     ";
    }
    else {
        cout << "\u0020\u0020";
        this->piece->affiche();
        cout << "\u0020" << " ";
    }
    
}

void Square::setPiece(Piece * piece) { this->piece = piece; }

Piece* Square::getPiece() const { return this->piece; }