#include "../include/piece.hpp"

Piece::Piece(couleur_t couleur, string icone, int id, Square *pos)
    : couleur(couleur), icone(icone), position(pos), etat(EnJeu), nbDeplacement(0) {}

Piece::~Piece() {}

void Piece::setSquare(Square *dest){
    this->position = dest;
}

Square* Piece::getSquare() const {
    return this->position;
}
couleur_t Piece::getCouleur() const{
    return this->couleur;
}

etat_t Piece::getEtat() const{
    return this->etat;
}

string Piece::getIcone() const {
    return this->icone;
}

int Piece::getId() const {
    return this->id;
}

size_t Piece::getNbDeplacement() const{
    return this->nbDeplacement;
}

void Piece::setNbDeplacement(size_t i){
    this->nbDeplacement = i;
}

void Piece::incr_nb_deplacement(){
    (this->nbDeplacement)++;
}
void Piece::affiche(){
    cout << this->icone;
}

void Piece::set_etat(etat_t etat) {
    this->etat = etat;
}

bool Piece::mouvement_legal(Square sqr, bool f) {return false; };
