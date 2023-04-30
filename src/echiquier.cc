#include "../include/echiquier.hpp"
#include <iostream>
using namespace std;

// constructeur
Echiquier::Echiquier () 
{
    alloc_mem_echiquier();
    // allocation des pieces                  
    // Constructeur (Couleur, nom_affiché, id, case)
    
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
                    grille[i][j]->affiche();
                }
                cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
                cout << endl;
        }
}
// void Echiquier::placement_initial() const {
//     pieces[Blanc] = {
//         new Tour    (Blanc,"\u2656",  0, Square(0,0)),
//         new Cavalier(Blanc,"\u2658",  1, Square(0,1)),
//         new Fou     (Blanc,"\u2657",  2, Square(0,2)),
//         new Dame    (Blanc,"\u2655",  3, Square(0,3)),
//         new Roi     (Blanc,"\u2654",  4, Square(0,4)),
//         new Fou     (Blanc,"\u2657",  5, Square(0,5)),
//         new Cavalier(Blanc,"\u2658",  6, Square(0,6)),
//         new Tour    (Blanc,"\u2656",  7, Square(0,7)) 
//     };     
//     pieces[Noir] = {
//         new Tour    (Noir, "\u265C",  8, Square(7,0)),
//         new Cavalier(Noir, "\u265E",  9, Square(7,1)),
//         new Fou     (Noir, "\u265D", 10, Square(7,2)),
//         new Dame    (Noir, "\u265B", 11, Square(7,3)),
//         new Roi     (Noir, "\u265A", 12, Square(7,4)),
//         new Fou     (Noir, "\u265D", 13, Square(7,5)),
//         new Cavalier(Noir, "\u265E", 14, Square(7,6)),
//         new Tour    (Noir, "\u265C", 15, Square(7,7))
//     };
//     // alloc pawns
//     for (size_t i=0;i<8;i++) {
//         pieces[Blanc].push_back(new Pion(Blanc, "\u2659" + string(1,i), 16+i, Square(1,i)));
//         pieces[Noir].push_back(new Pion(Noir,   "\u265F" + string(1,i), 24+i, Square(6,i)));
//     }
//     // Pose des pieces en position initiale sur l'echiquier
//     for (auto p : pieces[Blanc])
//         pose_piece(p, p->get_pos());
//     for (auto p : pieces[Noir])
//         pose_piece(p, p->get_pos());
// }