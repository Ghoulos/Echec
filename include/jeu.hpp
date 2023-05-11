#ifndef H_JEU
#define H_JEU

#include <iostream>
#include "../include/echiquier.hpp"
#include <memory>

class Jeu
{
  private:
    Echiquier *echiquier;
    string mouvement_en_cours;
    couleur_t couleur_joueur;

  public:
    Jeu();
    ~Jeu();
    void affiche();
    bool coup();
    bool est_coup_legal(Pos org, Pos );
    bool rien_ne_bloque(Pos org, Pos );
    bool coup();
    void setJoueur(couleur_t c);
    couleur_t getJoueur();
    bool isPathClear(Pos start, Pos end);
    bool deplace_piece(Pos start, Pos end, bool isPassingThroughAllowed = false);
    void displayEndGame(string result);
    bool echec_au_roi(couleur_t c);
    bool isCapturable(Pos pos, couleur_t c);
    bool isCheckMove(Pos start, Pos end ,couleur_t c);
    bool isTakingInPassing(Pos start, Pos end);
    void setLastMove(string move);
    string getLastMove();
    bool smallRookMove(couleur_t c);
    bool bigRookMove(couleur_t c);
    bool isPromotion();
};

#endif
