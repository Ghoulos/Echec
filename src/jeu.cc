#include "../include/jeu.hpp"
#include "../include/utilitaires.hpp"


Jeu::Jeu ()
    : echiquier(new Echiquier(true)), couleur_joueur(Blanc)  {
        cout << "La Partie a été créée !" << endl;
    }

Jeu::~Jeu () {
        cout << "La Partie est finie !" << endl;
    }
void Jeu::affiche() {echiquier->affiche();}

bool Jeu::coup() {
    string input;
    bool stop = false;

    cout << "C'est au joueur " << 
            ((couleur_joueur == Blanc) ? "blanc " : "noir ") 
            << "de jouer" << endl;

    do {
        do {
            if (echec_au_roi(this->couleur_joueur)){
                cout << "Le roi est en échec" << endl;
            }
            cout << "Attente du coup :  ";
            getline(cin, input);

            while (!entree_valide(input)) {
                cout << "L'entrée n'est pas valide !" << endl;
                cout << "Attente du coup :  ";
                getline(cin, input);
            }

            if (entree_sortie(input)){
                cout << "quit" << endl;
                this->affichage_fin_jeu("?-?");
                return false;

            } else if (entree_egalite(input)){
                cout << "draw" << endl;
                this->affichage_fin_jeu("1/2-1/2");
                return false;

            } else if (entree_abandon(input)) {
                cout << "resign" << endl;
                if (this->getJoueur() == Blanc){
                    this->affichage_fin_jeu("0-1");
                }else{
                    this->affichage_fin_jeu("1-0");
                }
                return false;

            }else if (entree_petit_rock(input)){
                cout << "petit roque" << endl;
                stop = this->petit_roque(this->couleur_joueur);

            }else if (entree_grand_rock(input)){
                cout << "grand roque" << endl;
                stop = this->grand_roque(this->couleur_joueur);

            }else{
                cout << "mouvement classique" << endl;
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

bool Jeu::passage_possible(Pos start, Pos end){
    int x0 = start.getX();
    int y0 = start.getY();
    int xFinal = end.getX();
    int yFinal = end.getY();

    // horizontale
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

    // verticale
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

    // diagonale
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

bool Jeu::deplace_piece(Pos start, Pos end, bool PasseAuTravers) {

    Piece *pieceEnDeplacement = echiquier->getPiece(start);
    Piece *pieceADestination = echiquier->getPiece(end);

    if (pieceEnDeplacement == nullptr){
        cout << "Il n'y a pas de piece a cette position !" << endl;
        return false;
    }

    if (pieceEnDeplacement->getCouleur() != couleur_joueur){
        cout << "Pièce de la mauvaise couleur !" << endl;
        return false;
    }

    // Cas spécial : prise en passant
    const char *NomDeClasse = typeid(*pieceEnDeplacement).name() + 1;
    if (strcmp(NomDeClasse, "Pion") == 0){
        if (this->prise_en_passant(start, end)){
            cout << "Prise en passant" << endl;
            this->echiquier->pose_piece(nullptr, Pos(getDernierMouv().substr(2,2)));
            this->echiquier->deplace_piece(start, end);
            pieceEnDeplacement->incr_nb_deplacement();
            return true;
        }
    }

    if(!(strcmp(NomDeClasse, "Roi") == 0 && PasseAuTravers)){
        if (pieceADestination != nullptr){
            if (pieceADestination->getCouleur() != pieceEnDeplacement->getCouleur()){
                if (strcmp(NomDeClasse, "Pion") == 0){
                    if (!pieceEnDeplacement->mouvement_legal(*echiquier->getSquare(end), true)) {
                        cout << "Mouvement invalide !" << endl;
                        return false;
                    }
                }else{
                    if (!pieceEnDeplacement->mouvement_legal(*echiquier->getSquare(end))) {
                        cout << "Mouvement invalide !" << endl;
                        return false;
                    }
                }
            } else{
                cout << "La case de destination est dejà occupée par une de vos pièce !" << endl;
                return false;
            }
        }else{
            if (!pieceEnDeplacement->mouvement_legal(*echiquier->getSquare(end))) {
                cout << "Mouvement invalide !" << endl;
                return false;
            }
        }
    }

    /*===== Vérification si le chemin est libre ======*/

    if (strcmp(NomDeClasse, "Pion") == 0
        || strcmp(NomDeClasse, "Roi") == 0
        || strcmp(NomDeClasse, "Dame") == 0
        || strcmp(NomDeClasse, "Fou") == 0
        || strcmp(NomDeClasse, "Tour") == 0){
        if (!this->passage_possible(start, end) && !PasseAuTravers){
            cout << "Passage impossible !" << endl;
            return false;
        }
    }

    /*===== Vérification si le joueur se place en echec ======*/

    if (this->met_en_echec(start, end ,this->getJoueur())){
        cout << "Ce coup vous met en échec !" << endl;
        return false;
    }

    this->echiquier->deplace_piece(start, end);
    pieceEnDeplacement->incr_nb_deplacement();

    /*===== Vérification si il y a une promotion ======*/

    if (this->promotion_possible()){
        cout << "[Promotion] choisir sa promotion (Q R B K) :" << endl;

        string promotion;
        Piece *promotion_piece = this->echiquier->getPiece(end);

        getline(cin, promotion);

        while (!promotion_valide(promotion)){
            cout << "L'input n'est pas valide" << endl;
            cout << "Promotion ? (eg Q) " << endl;
            getline(cin, promotion);
        }

        this->echiquier->promotion(promotion_piece, promotion);

    }

    return true;
}

void Jeu::affichage_fin_jeu(string resultat) {
    cout << this->echiquier->canonicalPosition() << " " << resultat << endl;
}

bool Jeu::echec_au_roi(couleur_t c){
    Square* posRoi = this->echiquier->position_roi(c);
    if (posRoi == nullptr){
        cerr << "Le roi n'a pas ete trouve" << endl;
        exit(1);
    }

    return this->isCapturable(*posRoi, c);
}

bool Jeu::isCapturable(Pos pos, couleur_t c){
    Square dest = *this->echiquier->getSquare(pos);
    for (int i = 0 ; i < TAILLE_PLATEAU ; ++i){
        for (int j = 0 ; j < TAILLE_PLATEAU ; ++j){
            Pos position_actuelle(i, j);
            Piece *piece = this->echiquier->getPiece(position_actuelle);
            if (piece != nullptr && piece->getCouleur() != c){
                if (strcmp(typeid(*piece).name() + 1, "Cavalier") == 0){
                    if (piece->mouvement_legal(dest)){
                        return true;
                    }
                }else{
                    if (piece->mouvement_legal(dest, true)
                        && this->passage_possible(position_actuelle, dest)
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

bool Jeu::met_en_echec(Pos start, Pos end ,couleur_t c){
    Piece *pieceDepart = echiquier->getPiece(start);
    Piece *pieceFin = echiquier->getPiece(end);

    echiquier->deplace_piece(start, end);

    if(echec_au_roi(c)){
        echiquier->pose_piece(pieceDepart, start);
        echiquier->pose_piece(pieceFin, end);
        if (pieceDepart != nullptr){
            pieceDepart->setSquare(echiquier->getSquare(start));
        }
        if (pieceFin != nullptr){
            pieceFin->setSquare(echiquier->getSquare(end));
        }
        return true;
    }else{
        echiquier->pose_piece(pieceDepart, start);
        echiquier->pose_piece(pieceFin, end);
        if (pieceDepart != nullptr){
            pieceDepart->setSquare(echiquier->getSquare(start));
        }
        if (pieceFin != nullptr){
            pieceFin->setSquare(echiquier->getSquare(end));
        }
        return false;
    }
}

bool Jeu::prise_en_passant(Pos start, Pos end){
    if (getDernierMouv().empty() || getDernierMouv().size() < 4){
        return false;
    }
    Pos debutDernierMouv = Pos(getDernierMouv().substr(0,2));
    Pos finDernierMouv = Pos(getDernierMouv().substr(2,2));
    Piece *dernierePieceJouee = echiquier->getPiece(finDernierMouv);

    if (dernierePieceJouee != nullptr && strcmp(typeid(*dernierePieceJouee).name() + 1, "Pion") == 0){
        if (dernierePieceJouee->getNbDeplacement() == 1){
            if (debutDernierMouv.getX() == finDernierMouv.getX() + 2
                || debutDernierMouv.getX() == finDernierMouv.getX() - 2){
                if (dernierePieceJouee->getSquare()->getY() == end.getY()
                    && abs(start.getX() - end.getX()) == abs(start.getY() - end.getY())
                    && abs(finDernierMouv.getX() - end.getX()) != 0
                    ){
                    return true;
                }
            }
        }
    }

    return false;
}

void Jeu::setLastMove(string move){
    this->dernier_mouvement = move;
}

string Jeu::getDernierMouv() {
    return this->dernier_mouvement;
}

bool Jeu::petit_roque(couleur_t c) {
    if (c == Blanc){
        if(this->passage_possible(Pos("e1"), Pos("h1" ))
            && this->echiquier->getPiece(Pos("e1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("h1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("e1")) != nullptr
            && this->echiquier->getPiece(Pos("h1")) != nullptr){
            if(!this->deplace_piece(Pos("e1"), Pos("g1"), true)){
                cout << "Movement du roi impossible" << endl;
                return false;
            }
            this->deplace_piece(Pos("h1"), Pos("f1"), true);
            return true;
        }
    }else{
        if(this->passage_possible(Pos("e8"), Pos("h8" ))
            && this->echiquier->getPiece(Pos("e8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("h8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("e8")) != nullptr
            && this->echiquier->getPiece(Pos("h8")) != nullptr){
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

bool Jeu::grand_roque(couleur_t c) {
    if (c == Blanc){
        if(this->passage_possible(Pos("e1"), Pos("a1" ))
            && this->echiquier->getPiece(Pos("e1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("a1"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("e1")) != nullptr
            && this->echiquier->getPiece(Pos("a1")) != nullptr){
            if(!this->deplace_piece(Pos("e1"), Pos("c1"), true)){
                cout << "Mouvement du roi impossible !" << endl;
                return false;
            }
            this->deplace_piece(Pos("a1"), Pos("d1"), true);
            return true;
        }
    }else{
        if(this->passage_possible(Pos("e8"), Pos("a8" ))
            && this->echiquier->getPiece(Pos("e8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("a8"))->getNbDeplacement() == 0
            && this->echiquier->getPiece(Pos("e8")) != nullptr
            && this->echiquier->getPiece(Pos("a8")) != nullptr){
            if(!this->deplace_piece(Pos("e8"), Pos("c8"), true)){
                cout << "Mouvement du roi impossible !" << endl;
                return false;
            }
            this->deplace_piece(Pos("a8"), Pos("d8"), true);
            return true;
        }
    }

    cout << "Grand roque impossible" << endl;
    return false;
}

bool Jeu::promotion_possible(){
    for (int i = 0; i < 8; i++){
        Piece *piece1 = this->echiquier->getPiece(Pos(0, i));

        if (piece1 != nullptr){
            const char *NomDeClasse1 = typeid(*piece1).name() + 1;
            if (strcmp(NomDeClasse1, "Pion") == 0){
                return true;
            }
        }

        Piece *piece2 = this->echiquier->getPiece(Pos(7, i));

        if (piece2 != nullptr){
            const char *NomDeClasse2 = typeid(*piece2).name() + 1;
            if (strcmp(NomDeClasse2, "Pion") == 0){
                return true;
            }
        }
    }
    return false;
}
