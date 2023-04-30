#ifndef H_ECHIQUIER
#define H_ECHIQUIER

#include "../include/piece.hpp"
#include "../include/square.hpp"
#include "../include/pos.hpp"

class Echiquier
{
private:
    Square * grille[8][8];
    Piece * pieces[2][16];

public:
    Echiquier(/* args */);
    ~Echiquier();
    void affiche() const; 
    void deplace_piece(Square org, Square dest);
    void alloc_mem_echiquier();
    void placement_initial();
    void pose_piece(Piece piece, Pos pos);
};

#endif