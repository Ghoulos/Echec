#ifndef H_JEU
#define H_JEU

#include "../include/piece.hpp"
#include <iostream>
#include "../include/echiquier.hpp"
#include <memory>

class Jeu
{
  private:
    Echiquier echiquier;

  public:
    Jeu();
    ~Jeu();
    void affiche() const {};
    bool coup();
    bool est_coup_legal(Square org, Square dest);
    bool rien_ne_bloque(Square org, Square dest);
};

#endif
