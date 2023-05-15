#include "../../include/pieces/pion.hpp"

Pion::Pion(couleur_t color, int id, Square *pos) :
        Piece(color, (color == Blanc) ? "\u265F" : "\u2659", id, pos) {}

bool Pion::mouvement_legal(Square dest, bool mouvementCapture) {
    if (mouvementCapture){
        if (this->getCouleur() == Blanc){
            if (// diagonale gauche
                (dest.getY() == this->position->getY() - 1
                && dest.getX() == this->position->getX() + 1)
                // diagonale droite
                || (dest.getY() == this->position->getY() + 1
                && dest.getX() == this->position->getX() + 1) 
                ){
                return true;
            }else{
                return false;
            }
        }else{
            if (// diagonale gauche
                (dest.getY() == this->position->getY() - 1
                 && dest.getX() == this->position->getX() - 1) 
                // diagonale droite
                || (dest.getY() == this->position->getY() + 1
                    && dest.getX() == this->position->getX() - 1) 
                ){
                return true;
            }else{
                return false;
            }
        }
    } else {
        if (this->getCouleur() == Blanc){
            // Ligne augmente
            if ((dest.getY() == this->position->getY() 
                 && dest.getX() == this->position->getX() + 1)
                ){
                return true;
            }else if (this->getNbDeplacement() == 0
                    // 1er deplacement donc 2 cases possibles
                      && dest.getY() == this->position->getY()
                      && dest.getX() == this->position->getX() + 2
                      ){
                return true;
            }else{
                return false;
            }
        }else{
            // Noir -> Ligne décroit
            if ((dest.getY() == this->position->getY()
                 && dest.getX() == this->position->getX() - 1)
                ){
                return true;
            }else if (this->getNbDeplacement() == 0
                    // 1er deplacement donc 2 cases possibles
                      && dest.getY() == this->position->getY()
                      && dest.getX() == this->position->getX() - 2
                    ){
                return true;
            }else{
                return false;
            }
        }
    }
}