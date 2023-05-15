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

    void setDernierMouv(string move);
    string getDernierMouv();
    couleur_t getJoueur();
    void setJoueur(couleur_t c);
  
    void affiche();
    bool coup();
    bool passage_possible(Pos start, Pos end);
    bool deplace_piece(Pos start, Pos end, bool isPassingThroughAllowed = false);
    void affichage_fin_jeu(string result);
    bool echec_au_roi(couleur_t c);
    bool est_capturable(Pos pos, couleur_t c);
    bool met_en_echec(Pos start, Pos end ,couleur_t c);
    bool prise_en_passant(Pos start, Pos end);

    bool petit_roque(couleur_t c);
    bool grand_roque(couleur_t c);
    bool promotion_possible();
};

#endif
