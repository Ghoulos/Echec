#ifndef H_PIECE
#define H_PIECE

#include <iostream>
#include "square.hpp"

typedef enum {Blanc=0, Noir=1} couleur_t;
typedef enum {EnJeu=0, PieceAJoue=1, Capture=2} etat_t;

using namespace std;
class Square;

class Piece
{
protected:
    couleur_t couleur;
    string icone;
    Square* position;
    etat_t etat;
    int id;
    size_t nbDeplacement;

public:
    Piece(couleur_t, string, int, Square*);
    virtual ~Piece();
    void affiche();
    void capture(bool);
    void setSquare(Square*);
    Square* getSquare() const;
    couleur_t getCouleur() const;
    string getIcone() const;
    int getId() const ;
    size_t getNbDeplacement() const;
    void setNbDeplacement(size_t);
    void incr_nb_deplacement();
    virtual bool mouvement_legal(Square, bool = false);
};

#endif
