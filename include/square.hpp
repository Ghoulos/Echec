#ifndef H_SQUARE
#define H_SQUARE

#include "../include/pos.hpp"
#include "../include/piece.hpp"
#include <iostream>
#include <memory>

class Piece;

using namespace std;

class Square : public Pos {
  private:
    Piece* piece;

  public:
    Square(int, int, Piece* =nullptr);
    Square(string, Piece* =nullptr);
    ~Square();
    bool est_vide();
    void affiche();
    void setPiece(Piece* piece);
    Piece* getPiece() const;
};

#endif
