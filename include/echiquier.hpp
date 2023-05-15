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
    void alloc_mem_echiquier();
    void init_echiquier();
    void placement_initial();
    void pose_piece(Piece *, Square *pos);
    void pose_piece(Piece *, Pos pos);
    Piece* deplace_piece( Square*, Square*);
    Piece* deplace_piece(const Pos, const Pos);
    string pgnPieceName(const string , bool , bool ) const;
    string canonicalPosition() const;
    Square* position_roi(couleur_t) const;
    Square* getSquare(int,int) const;
    Square* getSquare(Pos) const;
    Piece* getPiece(Pos) const;
    void setPiece(Piece*, Square);
    void promotion(Piece *, const string);
};

#endif