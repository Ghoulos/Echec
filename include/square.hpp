#ifndef H_SQUARE
#define H_SQUARE

#include "../include/piece.hpp"
#include "../include/pos.hpp"
#include <iostream>
#include <memory>

using namespace std;

class Square : public Pos {
  private:
    Piece* piece;

  public:
    Square(int, int, Piece*);
    ~Square();
    bool estVide();
    void affiche();
    void setPiece(Piece* piece);
    Piece* getPiece() const;
};

#endif
