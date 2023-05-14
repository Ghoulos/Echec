#ifndef H_JEU
#define H_JEU

#include <iostream>
#include "../include/echiquier.hpp"
#include <memory>
#include <iostream>
#include <regex>

using namespace std;

class Jeu
{
  private:
    Echiquier *echiquier;
    string dernier_mouvement;
    couleur_t couleur_joueur;

  public:
    Jeu();
    ~Jeu();
    void affiche();
    bool coup();
    bool est_coup_legal(Pos, Pos );
    bool rien_ne_bloque(Pos, Pos );
    void setJoueur(couleur_t c);
    couleur_t getJoueur();
    bool passage_possible(Pos start, Pos end);
    bool deplace_piece(Pos start, Pos end, bool isPassingThroughAllowed = false);
    void displayEndGame(string result);
    bool echec_au_roi(couleur_t c);
    bool isCapturable(Pos pos, couleur_t c);
    bool met_en_echec(Pos start, Pos end ,couleur_t c);
    bool prise_en_passant(Pos start, Pos end);
    void setLastMove(string move);
    string getDernierMouv();
    bool smallRookMove(couleur_t c);
    bool bigRookMove(couleur_t c);
    bool isPromotion();
};

#endif
