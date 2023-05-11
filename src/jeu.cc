#include "../include/jeu.hpp"
#include <iostream>
#include <regex>

using namespace std;

Jeu::Jeu ()
    : echiquier(&Echiquier(true)), couleur_joueur(Blanc)  {
        cout << "La Partie a été créée !" << endl;
    }

Jeu::~Jeu () {
        cout << "La Partie est finie !" << endl;
    }
bool Jeu::coup() {return true;}

void Jeu::affiche() {this->echiquier.affiche();}

bool entree_mouvement(string const & input){
    regex pattern("^ *[a-h][1-8][a-h][1-8] *$|^ */(quit|draw|resign) *$");
    return regex_match(input, pattern);
}

bool entree_petit_rock(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool entree_grand_rock(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool entree_sortie(string const & input){
    regex pattern("/quit\\s*");
    return regex_match(input,pattern);
}

bool entree_egalite(string const & input){
    regex pattern("/draw\\s*");
    return regex_match(input,pattern);
}

bool entree_abandon(string const & input){
    regex pattern("/resign\\s*");
    return regex_match(input,pattern);
}

bool entree_valide(string const & input){
    return (entree_mouvement(input)
        || entree_petit_rock(input)
        || entree_grand_rock(input)
        || entree_sortie(input)
        || entree_egalite(input)
        || entree_abandon(input));
}

bool promotion_valide(string const & input){
    return promotion_reine(input)
        || isValidRookPromotion(input)
        || isValidBishopPromotion(input)
        || isValidKnightPromotion(input);
}

bool Jeu::coup() {
    string input;
    bool stop = false;

    cout << "C'est au joueur " << 
            ((couleur_joueur == Blanc) ? "blanc" : "noir") << " de jouer" << endl;

    do {
        do {
            if (this->echec_au_roi(this->couleur_joueur)){
                cout << "Le roi est en échec" << endl;
            }
            getline(cin, input);

            while (!entree_valide(input)) {
                cout << "L'input n'est pas valide" << endl;
                cout << "Coup ? (eg a2a3) " << endl;
                getline(cin, input);
            }

            if (entree_sortie(input)){
                cout << "quit" << endl;
                this->displayEndGame("?-?");
                return false;
            } else if (entree_egalite(input)){
                cout << "draw" << endl;
                this->displayEndGame("1/2-1/2");
                return false;
            } else if (entree_abandon(input)) {
                cout << "resign" << endl;
                if (this->getJoueur() == Blanc){
                    this->displayEndGame("0-1");
                }else{
                    this->displayEndGame("1-0");
                }
                return false;
            }else if (entree_petit_rock(input)){
                cout << "small rook move" << endl;
                stop = this->smallRookMove(this->couleur_joueur);
            }else if (entree_grand_rock(input)){
                cout << "big rook move" << endl;
                stop = this->bigRookMove(this->couleur_joueur);
            }else{
                cout << "move" << endl;
                stop = this->deplace_piece((Pos(input.substr(0,2))),
                                       Pos(input.substr(2,2))
                );
            }

        }while(this->echec_au_roi(this->couleur_joueur));

    } while (!stop);

    this->setLastMove(input);

    this->couleur_joueur = (this->couleur_joueur == Blanc) ? Noir : Blanc;

    return true;
}

bool Jeu::isPathClear(Pos start, Pos end){
    int x0 = start.getX();
    int y0 = start.getY();
    int xFinal = end.getX();
    int yFinal = end.getY();

    // si le chemin est horizontale
    if (x0 == xFinal){
        int x = x0;
        if (y0 < yFinal){
            for (int i = y0 + 1 ; i < yFinal ; ++i) {
                if (this->echiquier->getPiece(Pos(x, i)) != nullptr){
                    return false;
                }
            }
        }else{
            for (int i = yFinal + 1 ; i < y0 ; ++i) {
                if (this->echiquier->getPiece(Pos(x, i)) != nullptr){
                    return false;
                }
            }
        }
    }

    // si le chemin est verticale
    if (y0 == yFinal){
        int y = y0;
        if (x0 < xFinal){
            for (int i = x0 + 1 ; i < xFinal ; ++i) {
                if (this->echiquier->getPiece(Pos(i, y)) != nullptr){
                    return false;
                }
            }
        }else{
            for (int i = xFinal + 1 ; i < x0 ; ++i) {
                if (this->echiquier->getPiece(Pos(i, y)) != nullptr){
                    return false;
                }
            }
        }
    }

    // si le chemin est diagonal
    if (abs(x0 - xFinal) == abs(y0 - yFinal)){
        int x = x0;
        int y = y0;
        if (x0 < xFinal){
            if (y0 < yFinal){
                for (int i = x0 + 1 ; i < xFinal ; ++i) {
                    ++x;
                    ++y;
                    if (this->echiquier->getPiece(Pos(x, y)) != nullptr){
                        return false;
                    }
                }
            }else{
                for (int i = x0 + 1 ; i < xFinal ; ++i) {
                    ++x;
                    --y;
                    if (this->echiquier->getPiece(Pos(x, y)) != nullptr){
                        return false;
                    }
                }
            }
        }else{
            if (y0 < yFinal){
                for (int i = xFinal + 1 ; i < x0 ; ++i) {
                    --x;
                    ++y;
                    if (this->echiquier->getPiece(Pos(x, y)) != nullptr){
                        return false;
                    }
                }
            }else{
                for (int i = xFinal + 1 ; i < x0 ; ++i) {
                    --x;
                    --y;
                    if (this->echiquier->getPiece(Pos(x, y)) != nullptr){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Jeu::deplace_piece(Pos start, Pos end, bool isPassingThroughAllowed) {

    Piece *moving_piece = echiquier.getPiece(start);
    Piece *destination_piece = echiquier.getPiece(end);

    /*===== Vérification si la piece existe ======*/
    if (moving_piece == nullptr){
        cout << "Il n'y a pas de piece a cette position" << endl;
        return false;
    }

    if (moving_piece->getCouleur() != couleur_joueur){
        cout << "Ce n'est pas votre piece !" << endl;
        return false;
    }

    const char *class_name = typeid(*moving_piece).name() + 1;

    /*===== Vérification si c'est une prise en passant ======*/

    if (strcmp(class_name, "Pion") == 0){
        if (this->isTakingInPassing(start, end)){
            cout << "Prise en passant" << endl;
            this->echiquier->pose_piece(nullptr, Pos(this->getLastMove().substr(2,2)));
            this->echiquier->deplace_piece(start, end);
            moving_piece->incr_nb_deplacement();
            return true;
        }
    }


    /*===== Vérification de la validité des coups ======*/

    if(!(strcmp(class_name, "King") == 0 && isPassingThroughAllowed)){
        if (destination_piece != nullptr){
            if (destination_piece->getCouleur() != moving_piece->getCouleur()){
                if (strcmp(class_name, "Pion") == 0){
                    if (!moving_piece->mouvement_legal(end, true)) {
                        cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                        return false;
                    }
                }else{
                    if (!moving_piece->mouvement_legal(end)) {
                        cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                        return false;
                    }
                }
            } else{
                cout << "Il y a deja une piece de la meme couleur a cette position" << endl;
                return false;
            }
        }else{
            if (!moving_piece->mouvement_legal(end)) {
                cout << "Le coup n'est pas valide : mouvement non valide" << endl;
                return false;
            }
        }
    }

    /*===== Vérification si le chemin est libre ======*/

    if (strcmp(class_name, "Pion") == 0
        || strcmp(class_name, "King") == 0
        || strcmp(class_name, "Queen") == 0
        || strcmp(class_name, "Bishop") == 0
        || strcmp(class_name, "Rook") == 0){
        if (!this->isPathClear(start, end) && !isPassingThroughAllowed){
            cout << "Le chemin n'est pas libre" << endl;
            return false;
        }
    }

    /*===== Vérification si le joueur se place en echec ======*/

    if (this->isCheckMove(start, end ,this->getJoueur())){
        cout << "Le coup n'est pas valide vous etes en echec" << endl;
        return false;
    }

    this->echiquier->deplace_piece(start, end);
    moving_piece->incr_nb_deplacement();

    /*===== Vérification si il y a une promotion ======*/

    if (this->isPromotion()){
        cout << "[Promotion] choisir sa promotion (Q R B K) :" << endl;

        string promotion;
        Piece *promotion_piece = this->echiquier->getPiece(end);

        getline(cin, promotion);

        while (!promotion_valide(promotion)){
            cout << "L'input n'est pas valide" << endl;
            cout << "Promotion ? (eg Q) " << endl;
            getline(cin, promotion);
        }

        this->echiquier->promote(promotion_piece, promotion);

    }

    return true;
}

void Jeu::displayEndGame(string result) {
    cout << this->echiquier->canonicalPosition() << " " << result << endl;
}

bool Jeu::echec_au_roi(couleur_t c){
    Pos king_Pos = this->echiquier->getKingPos(c);
    if (king_Pos == Pos(-1, -1)){
        cerr << "Le roi n'a pas ete trouve" << endl;
        exit(1);
    }

    return this->isCapturable(king_Pos, c);
}

bool Jeu::isCapturable(Pos pos, couleur_t c){
    for (int i = 0 ; i < TAILLE_PLATEAU ; ++i){
        for (int j = 0 ; j < TAILLE_PLATEAU ; ++j){
            pos position_actuelle(i, j);
            Piece *piece = this->echiquier->getPiece(position_actuelle);
            if (piece != nullptr && piece->getCouleur() != c){
                if (strcmp(typeid(*piece).name() + 1, "Knight") == 0){
                    if (piece->mouvement_legal(pos)){
                        return true;
                    }
                }else{
                    if (piece->mouvement_legal(pos, true)
                        && this->isPathClear(position_actuelle, pos)
                    ){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void Jeu::setJoueur(couleur_t c){
    this->couleur_joueur = c;
}

couleur_t Jeu::getJoueur(){
    return this->couleur_joueur;
}

bool Jeu::isCheckMove(Pos start, Pos end ,couleur_t c){
    Piece *start_piece = this->echiquier->getPiece(start);
    Piece *end_piece = this->echiquier->getPiece(end);

    this->echiquier->deplace_piece(start, end);

    if(this->echec_au_roi(c)){
        this->echiquier->pose_piece(start_piece, start);
        this->echiquier->pose_piece(end_piece, end);
        if (start_piece != nullptr){
            start_piece->setPos(start);
        }
        if (end_piece != nullptr){
            end_piece->setPos(end);
        }
        return true;
    }else{
        this->echiquier->pose_piece(start_piece, start);
        this->echiquier->pose_piece(end_piece, end);
        if (start_piece != nullptr){
            start_piece->setPos(start);
        }
        if (end_piece != nullptr){
            end_piece->setPos(end);
        }
        return false;
    }
}

bool Jeu::isTakingInPassing(Pos start, Pos end){
    if (this->getLastMove().empty() || this->getLastMove().size() < 4){
        return false;
    }
    Pos last_move_start = this->getLastMove().substr(0,2);
    Pos last_move_end = this->getLastMove().substr(2,2);

    Piece *last_move_piece = this->echiquier->getPiece(last_move_end);

    if (last_move_piece != nullptr && strcmp(typeid(*last_move_piece).name() + 1, "Pion") == 0){
        if (last_move_piece->getNbDeplacement() == 1){
            if (last_move_start.getX() == last_move_end.getX() + 2
                || last_move_start.getX() == last_move_end.getX() - 2){
                if (last_move_piece->getPos().getY() == end.getY()
                    && abs(start.getX() - end.getX()) == abs(start.getY() - end.getY()) // si le pion se deplace en diagonale
                    && abs(last_move_end.getX() - end.getX()) != 0 // si le pion ne se retouve par sur la meme ligne que le pion qui a bouge
                    ){
                    return true;
                }
            }
        }
    }

    return false;
}

void Jeu::setLastMove(string move){
    this->last_move = move;
}

string Jeu::getLastMove() {
    return this->last_move;
}

bool Jeu::smallRookMove(couleur_t c) {
    if (c == Blanc){
        if(this->isPathClear(Pos("e1"), Pos("h1" ))
            && this->echiquier->getPiece(Pos("e1")) != nullptr
            && this->echiquier->getPiece(Pos("h1")) != nullptr
            && this->echiquier->getPiece(Pos("e1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("h1"))->getNbDeplacement() == 0){
            if(!this->deplace_piece(Pos("e1"), Pos("g1"), true)){
                cout << "Movement du roi impossible" << endl;
                return false;
            }
            this->deplace_piece(Pos("h1"), Pos("f1"), true);
            return true;
        }
    }else{
        if(this->isPathClear(Pos("e8"), Pos("h8" ))
            && this->echiquier->getPiece(Pos("e8")) != nullptr
            && this->echiquier->getPiece(Pos("h8")) != nullptr
            && this->echiquier->getPiece(Pos("e8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("h8"))->getNbDeplacement() == 0){
            if(!this->deplace_piece(Pos("e8"), Pos("g8"), true)){
                cout << "Mouvement du roi impossible" << endl;
                return false;
            }
            this->deplace_piece(Pos("h8"), Pos("f8"), true);
            return true;
        }
    }

    cout << "Petit roque impossible" << endl;
    return false;
}

bool Jeu::bigRookMove(couleur_t c) {
    if (c == Blanc){
        if(this->isPathClear(Pos("e1"), Pos("a1" ))
            && this->echiquier->getPiece(Pos("e1")) != nullptr
            && this->echiquier->getPiece(Pos("a1")) != nullptr
            && this->echiquier->getPiece(Pos("e1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("a1"))->getNbDeplacement() == 0){
            if(!this->deplace_piece(Pos("e1"), Pos("c1"), true)){
                cout << "Mouvement du roi impossible" << endl;
                return false;
            }
            this->deplace_piece(Pos("a1"), Pos("d1"), true);
            return true;
        }
    }else{
        if(this->isPathClear(Pos("e8"), Pos("a8" ))
            && this->echiquier->getPiece(Pos("e8")) != nullptr
            && this->echiquier->getPiece(Pos("a8")) != nullptr
            && this->echiquier->getPiece(Pos("e8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("a8"))->getNbDeplacement() == 0){
            if(!this->deplace_piece(Pos("e8"), Pos("c8"), true)){
                cout << "Mouvement du roi impossible" << endl;
                return false;
            }
            this->deplace_piece(Pos("a8"), Pos("d8"), true);
            return true;
        }
    }

    cout << "Grand roque impossible" << endl;
    return false;
}

bool Jeu::isPromotion(){
    for (int i = 0; i < 8; i++){
        Piece *piece1 = this->echiquier->getPiece(Pos(0, i));

        if (piece1 != nullptr){
            const char *class_name1 = typeid(*piece1).name() + 1;
            if (strcmp(class_name1, "Pion") == 0){
                return true;
            }
        }

        Piece *piece2 = this->echiquier->getPiece(Pos(7, i));

        if (piece2 != nullptr){
            const char *class_name2 = typeid(*piece2).name() + 1;
            if (strcmp(class_name2, "Pion") == 0){
                return true;
            }
        }
    }
    return false;
}
