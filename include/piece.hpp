#ifndef H_PIECE
#define H_PIECE

typedef enum {Blanc=0, Noir=1} couleur_t;
typedef enum {EnJeu=0, PieceAJoue=1, Morte=2} etat_t;


class Piece
{
private:
    couleur_t couleur;
    etat_t etat;

public:
    Piece(/* args */);
    ~Piece();
    //bool est_mvmt_legal(Square org, Square dest);
    void affiche();
};



#endif