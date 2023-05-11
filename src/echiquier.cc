#include "../include/echiquier.hpp"
#include "../include/pieces/roi.hpp"
#include "../include/pieces/reine.hpp"
#include "../include/pieces/cavalier.hpp"
#include "../include/pieces/fou.hpp"
#include "../include/pieces/tour.hpp"
#include "../include/pieces/pion.hpp"

#include <iostream>
using namespace std;

// constructeur


void Echiquier::alloc_mem_echiquier(){
    this->plateau = new Square**[TAILLE_PLATEAU];
    for (int i = 0; i < TAILLE_PLATEAU; ++i) {
        this->plateau[i] = new Square*[TAILLE_PLATEAU];
    }
}

void Echiquier::init_echiquier(){
    for (int i = 0; i < TAILLE_PLATEAU; ++i) {
        for (int j = 0; j < TAILLE_PLATEAU; ++j) {
            this->plateau[i][j] = new Square(i,j, nullptr);
        }
    }
}

void Echiquier::pose_piece(Piece *p, Square pos) {
    if(p != nullptr){
        Piece *p2 = plateau[pos.getX()][pos.getY()]->getPiece();
        if (p2 != nullptr) {
            p2->capture(true);
        }
        p->setSquare(pos);
        pos.setPiece(p);
        
    }else{
        pos.setPiece(nullptr);
    }
}

void Echiquier::pose_piece(Piece *p, Pos pos) {
    this->pose_piece(p,getSquare(pos));
}

Square Echiquier::getSquare(int x, int y){
    if((0 <= x && x < TAILLE_PLATEAU)&&
        (0 <= y && y < TAILLE_PLATEAU)){
            return *this->plateau[x][y];
        }
    else { return (Square(-1, -1, nullptr));}
}

Square Echiquier::getSquare(Pos pos){
    int x = pos.getX();
    int y = pos.getY();
    if((0 <= x && x < TAILLE_PLATEAU)&&
        (0 <= y && y < TAILLE_PLATEAU)){
            return *this->plateau[x][y];
        }
    else { return (Square(-1, -1, nullptr));}
}

Echiquier::Echiquier (bool placement_init = true) 
{
    alloc_mem_echiquier();

    init_echiquier();
    
    if (placement_init) placement_initial();

    
}

Echiquier::~Echiquier()
{
}

void Echiquier::affiche () const {

        string space5 = string(5,' ');
        cout << endl;
        cout << "     a     b     c     d     e     f     g     h    "<< endl;
        cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
        for (int i(7);i>=0;i--) {
                cout << i+1 << " "; // numérotation ligne dans affichage
                for (int j(0);j<8;j++) {
                    cout << "|";
                    plateau[i][j]->affiche();
                }
                cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
                cout << endl;
        }
}
void Echiquier::placement_initial() {
    pieces[Blanc] = {
        new Tour    (Blanc, 0, this->plateau[0][0]),
        new Cavalier(Blanc, 1, this->plateau[0][1]),
        new Fou     (Blanc, 2, this->plateau[0][2]),
        new Reine   (Blanc, 3, this->plateau[0][3]),
        new Roi     (Blanc, 4, this->plateau[0][4]),
        new Fou     (Blanc, 5, this->plateau[0][5]),
        new Cavalier(Blanc, 6, this->plateau[0][6]),
        new Tour    (Blanc, 7, this->plateau[0][7]) 
    };     
    pieces[Noir] = {
        new Tour    (Noir,  8, this->plateau[7][0]),
        new Cavalier(Noir,  9, this->plateau[7][1]),
        new Fou     (Noir, 10, this->plateau[7][2]),
        new Reine   (Noir, 11, this->plateau[7][3]),
        new Roi     (Noir, 12, this->plateau[7][4]),
        new Fou     (Noir, 13, this->plateau[7][5]),
        new Cavalier(Noir, 14, this->plateau[7][6]),
        new Tour    (Noir, 15, this->plateau[7][7])
    };
    // alloc pawns
    for (size_t i=0;i<8;i++) {
        pieces[Blanc].push_back(new Pion(Blanc,16+i, this->plateau[1][i]));
        pieces[Noir].push_back(new Pion(Noir,  24+i, this->plateau[6][i]));
    }
    // Pose des pieces en position initiale sur l'echiquier
    for (auto p : pieces[Blanc])
        pose_piece(p, p->getSquare());
    for (auto p : pieces[Noir])
        pose_piece(p, p->getSquare());
}

Piece* Echiquier::getPiece(Pos pos){
    return getSquare(pos.getX(), pos.getY()).getPiece();
}

void Echiquier::deplace_piece(const Square& posDebut, const Square& posFin) {
    Piece *end_piece = this->getPiece(posFin);
    if (end_piece != nullptr){
        end_piece->setCatch(true);
    }
    this->pose_piece(this->getPiece(posDebut), posFin);
    this->pose_piece(nullptr, posDebut);
}