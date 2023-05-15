#include "../include/echiquier.hpp"
#include "../include/utilitaires.hpp"
#include "../include/pieces/roi.hpp"
#include "../include/pieces/dame.hpp"
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

Echiquier::Echiquier (bool placement_init = true) 
{
    alloc_mem_echiquier();

    init_echiquier();
    
    if (placement_init) placement_initial();
}

Echiquier::~Echiquier()
{
}

void Echiquier::pose_piece(Piece *p, Square *pos) {
    if(p != nullptr){
        p->setSquare(pos);
        pos->setPiece(p);
        
    }else{
        pos->setPiece(nullptr);
    }
}

Square* Echiquier::getSquare(int x, int y) const{
    if((0 <= x && x < TAILLE_PLATEAU)&&
        (0 <= y && y < TAILLE_PLATEAU)){
            return this->plateau[x][y];
        }
    else { return nullptr;}
}

Square* Echiquier::getSquare(Pos pos) const{
    int x = pos.getX();
    int y = pos.getY();
    if((0 <= x && x < TAILLE_PLATEAU)&&
        (0 <= y && y < TAILLE_PLATEAU)){
            return this->plateau[x][y];
        }
    else { return nullptr;}
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
        new Dame   (Blanc, 3, this->plateau[0][3]),
        new Roi     (Blanc, 4, this->plateau[0][4]),
        new Fou     (Blanc, 5, this->plateau[0][5]),
        new Cavalier(Blanc, 6, this->plateau[0][6]),
        new Tour    (Blanc, 7, this->plateau[0][7]) 
    };     
    pieces[Noir] = {
        new Tour    (Noir, 0, this->plateau[7][0]),
        new Cavalier(Noir, 1, this->plateau[7][1]),
        new Fou     (Noir, 2, this->plateau[7][2]),
        new Dame   (Noir, 3, this->plateau[7][3]),
        new Roi     (Noir, 4, this->plateau[7][4]),
        new Fou     (Noir, 5, this->plateau[7][5]),
        new Cavalier(Noir, 6, this->plateau[7][6]),
        new Tour    (Noir, 7, this->plateau[7][7])
    };
    // alloc pawns
    for (size_t i=0;i<8;i++) {
        pieces[Blanc].push_back(new Pion(Blanc, 8+i, this->plateau[1][i]));
        pieces[Noir].push_back(new Pion(Noir,  8+i, this->plateau[6][i]));
    }
    // Pose des pieces en position initiale sur l'echiquier
    for (auto p : pieces[Blanc])
        pose_piece(p, p->getSquare());
    for (auto p : pieces[Noir])
        pose_piece(p, p->getSquare());
}

Piece* Echiquier::getPiece(Pos pos) const{
    return getSquare(pos)->getPiece();
}

Piece* Echiquier::deplace_piece( Square* CaseDeb, Square* CaseFin) {
    cout << "entree deplacepiece echiquier" << endl;
    Piece *pieceSortante = CaseFin->getPiece();
    if (pieceSortante != nullptr){
        pieceSortante->capture(false);
    }
    this->pose_piece(CaseDeb->getPiece(), CaseFin);
    this->pose_piece(nullptr, CaseDeb);
    cout << pgnPieceName(CaseFin->getPiece()->getIcone(), 1, 1)<< endl ;
    return pieceSortante;
}

Piece* Echiquier::deplace_piece(const Pos posDebut, const Pos posFin){
    Square* deb = getSquare(posDebut);
    Square* fin = getSquare(posFin);
    return deplace_piece(deb, fin);
}

string Echiquier::pgnPieceName(string const icone, bool view_pawn, bool view_color) const {
    //Modification du code originale pour la couleur
    string psymb;
    if      (icone=="\u2656") psymb="R";  // Tour W
    else if (icone=="\u2658") psymb="N";  // Cavalier W
    else if (icone=="\u2657") psymb="B";  // Fou W
    else if (icone=="\u2655") psymb="Q";  // Dame W
    else if (icone=="\u2654") psymb="K";  // Roi W
    else if (icone.rfind("\u2659",0)==0 && view_pawn) psymb= "P"; // Pawn W
    if (psymb.size()>0) { // one of the BLACK piece has been found
        if (view_color)
            return "b"+psymb;
        else
            return psymb;
    }
    if      (icone=="\u265C") psymb= "R";  // Tour B
    else if (icone=="\u265E") psymb= "N";  // Cavalier B
    else if (icone=="\u265D") psymb= "B";  // Fou B
    else if (icone=="\u265B") psymb= "Q";  // Dame B
    else if (icone=="\u265A") psymb= "K";  // Roi B
    else if (icone.rfind("\u265F",0)==0 && view_pawn) psymb= "P"; // Pawn B
    if (psymb.size()>0) { // one of the White piece has been found
        if (view_color)
            return "w"+psymb;
        else
            return psymb;
    }
    else return "";
}

string Echiquier::canonicalPosition() const{
    string output;
    for (size_t i = 0; i<TAILLE_PLATEAU; i++){
        for (int j =0;j < TAILLE_PLATEAU;j++) {
            Pos pos_i = Pos(i, j);
            if (this->getPiece(pos_i) != nullptr)
                // get pieces with theit PGN names,
                // true -> with P for pawns, true -> w/b for colors.
                output += pgnPieceName(getPiece(pos_i)->getIcone(),true,true);
            output += ",";
        }
    }
    return output;
}

Square* Echiquier::position_roi(couleur_t const color) const{
    for (auto p : this->pieces[color])
        if (p->getIcone() == "\u2654" || p->getIcone() == "\u265A")
            return p->getSquare();
    return nullptr;
}

void Echiquier::setPiece(Piece *p, Square caseCible){
    caseCible.setPiece(p);
}


void Echiquier::promotion(Piece *piece, const string type){
    int indice = piece->getId();
    couleur_t couleur = piece->getCouleur();
    Piece *nouvellePiece;
    if(promotion_dame(type)){
        nouvellePiece = (new Dame(couleur, indice, piece->getSquare()));

    } else if(promotion_tour(type)){
        nouvellePiece = (new Tour(couleur, indice, piece->getSquare()));

    } else if(promotion_fou(type)){
        nouvellePiece = (new Fou(couleur, indice, piece->getSquare()));

    } else{
        nouvellePiece = (new Cavalier(couleur, indice, piece->getSquare()));
    }             

    nouvellePiece->setNbDeplacement(piece->getNbDeplacement());
    nouvellePiece->capture(true);

    pieces[couleur][indice]= nouvellePiece;

    this->pose_piece(nouvellePiece, nouvellePiece->getSquare());
    //delete piece ?
}