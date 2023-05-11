#include "../include/piece.hpp"

Piece::Piece(couleur_t couleur, string icone, int id, Square *pos, etat_t etat)
    : couleur(couleur), icone(icone), position(pos), etat(etat) {}

Piece::~Piece() {}

void Piece::capture(bool revient = false) {
    if (revient) {this->etat = EnJeu;}
    else {this->etat = Capture;}
}

void Piece::setSquare(Square dest){
    this->position = &dest;
}

Square Piece::getSquare() {
    return *this->position;
}
couleur_t Piece::getCouleur(){
    return this->couleur;
}

size_t Piece::getNbDeplacement(){
    return this->nb_deplacement;
}
void Piece::incr_nb_deplacement(){
    (this->nb_deplacement)++;
}
void Piece::affiche()
{
    // Code pour afficher la pièce
    cout << this->icone;
}