#ifndef H_ECHIQUIER
#define H_ECHIQUIER

#include "../include/square.hpp"
#include "../include/piece.hpp"
#include "../include/pos.hpp"
#include <vector>

#define TAILLE_PLATEAU 8

class Echiquier
{
private:
    Square ***plateau;
    vector<Piece *> pieces[2];

public:
    Echiquier(bool);
    ~Echiquier();
    void affiche() const; 
    void deplace_piece(Square, Square );
    void deplace_piece(Pos, Pos );
    void alloc_mem_echiquier();
    void init_echiquier();
    void placement_initial();
    void pose_piece(Piece *piece, Square pos);
    void pose_piece(Piece *piece, Pos pos);
    void deplace_piece(const Square, const Square);
    void deplace_piece(Pos, Pos);
    Square getSquare(int,int);
    Square getSquare(Pos);
    Piece* getPiece(Pos);
};

#endif