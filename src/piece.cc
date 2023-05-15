#include "../include/piece.hpp"

Piece::Piece(couleur_t couleur, string icone, int id, Square *pos)
    : couleur(couleur), icone(icone), position(pos), etat(EnJeu), nbDeplacement(0) {}

Piece::~Piece() {}

void Piece::capture(bool revient = false) {
    if (revient) {this->etat = EnJeu;}
    else {this->etat = Capture;}
}

void Piece::setSquare(Square *dest){
    this->position = dest;
}

Square* Piece::getSquare() const {
    return this->position;
}
couleur_t Piece::getCouleur() const{
    return this->couleur;
}

size_t Piece::getNbDeplacement() const{
    return this->nbDeplacement;
}
void Piece::setNbDeplacement(size_t i){
    this->nbDeplacement = i;
}
string Piece::getIcone() const {
    return this->icone;
}

int Piece::getId() const {
    return this->id;
}
bool Piece::mouvement_legal(Square sqr, bool f) {return false; };

void Piece::incr_nb_deplacement(){
    (this->nbDeplacement)++;
}
void Piece::affiche()
{
    // Code pour afficher la pièce
    cout << this->icone;
}
