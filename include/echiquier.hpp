#ifndef H_ECHIQUIER
#define H_ECHIQUIER

#include "../include/square.hpp"
#include "../include/piece.hpp"
#include "../include/pos.hpp"
#include <vector>

#define TAILLE_PLATEAU 8

/**
 * @brief Classe représentant l'échiquier du jeu d'échecs.
 * 
 * La classe Echiquier est responsable de la gestion de l'échiquier et des
 *  pièces qui y sont placées.
 */
class Echiquier
{
private:
    Square ***plateau; /**< Matrice 2D de pointeurs vers les cases de l'échiquier. */
    vector<Piece *> pieces[2]; /**< Vecteur de pointeurs vers les pièces 
    présentes sur l'échiquier, triées par couleur (blanc ou noir). */

public:
    /**
     * @brief Constructeur de la classe Echiquier.
     * @param initialiser_pieces Indique si les pièces doivent être placées 
     * initialement sur l'échiquier (par défaut true).
     */
    Echiquier(bool initialiser_pieces = true);

    /**
     * @brief Destructeur de la classe Echiquier.
     */
    ~Echiquier();
    
    /**
     * @brief Obtient la case à partir de ses coordonnées x et y.
     * @param x Coordonnée X de la case.
     * @param y Coordonnée Y de la case.
     * @return Pointeur vers la case correspondante.
     */
    Square* getSquare(int x, int y) const;

    /**
     * @brief Obtient la case à partir d'un objet de type Pos.
     * @param pos Objet de type Pos représentant les coordonnées de la case.
     * @return Pointeur vers la case correspondante.
     */
    Square* getSquare(Pos pos) const;

    /**
     * @brief Obtient la pièce présente dans une case donnée.
     * @param pos Objet de type Pos représentant les coordonnées de la case.
     * @return Pointeur vers la pièce présente dans la case, ou nullptr si 
     * la case est vide.
     */
    Piece* getPiece(Pos pos) const;

    /**
     * @brief Obtient le vecteur piece associé a une couelur
     * (attribut pieces[couleur])
     * @param c couleur cible
     * @return une ref à ce vectuer
     */
    vector<Piece *> getPieces(couleur_t c) const;
    /**
     * @brief Place une pièce dans une case donnée.
     * @param piece Pointeur vers la pièce à placer.
     * @param square Pointeur vers la case dans laquelle placer la pièce.
     */
    void setPiece(Piece* piece, Square* square);

    /**
     * @brief Obtient la position du roi d'une couleur donnée.
     * @param couleur Couleur du roi (blanc ou noir).
     * @return Pointeur vers la case occupée par le roi de la couleur spécifiée.
     */
    Square* position_roi(couleur_t couleur) const;

    /**
     * @brief Obtient le nom PGN d'une pièce. (normalisme anglais)
     * @param piece Nom de la pièce (ex: "K" pour le roi).
     * @param view_pawnn Indique si on visualise les pions.
     * @param view_color Indique si on visualise les couleurs (par défaut true).
     * @return Le nom PGN de la pièce.
     */
    string pgnPieceName(const string piece, bool view_pawn,
                         bool view_color = true) const;

    /**
     * @brief Obtient la position canonique de l'échiquier.
     * @return Une chaîne de caractères représentant la position canonique de 
     * l'échiquier.
     */
    string canonicalPosition() const;

    /**
     * @brief Affiche l'échiquier.
     */
    void affiche() const; 

    /**
     * @brief Alloue la mémoire pour l'échiquier (matrice de cases).
     */
    void alloc_mem_echiquier();

    /**
     * @brief Initialise l'échiquier en plaçant les cases vides.
     */
    void init_echiquier();

    /**
     * @brief Place les pièces initiales sur l'échiquier.
     */
    void placement_initial();

    /**
     * @brief Place une pièce dans une case donnée.
     * @param piece Pointeur vers la pièce à placer.
     * @param caseCible Pointeur vers la case dans laquelle placer la pièce.
     */
    void pose_piece(Piece* piece, Square* caseCible);

    /**
     * @brief Déplace une pièce d'une case à une autre.
     * @param origine Pointeur vers la case d'origine de la pièce.
     * @param destination Pointeur vers la case de destination de la pièce.
     * @return Pointeur vers la pièce déplacée, ou nullptr si aucun déplacement
     *  n'a été effectué.
     */
    Piece* deplace_piece(Square* origine, Square* destination);

    /**
     * @brief Déplace une pièce d'une case à une autre.
     * @param origine Objet de type Pos représentant les coordonnées de la case
     *  d'origine de la pièce.
     * @param destination Objet de type Pos représentant les coordonnées de la 
     * case de destination de la pièce.
     * @return Pointeur vers la pièce déplacée, ou nullptr si aucun déplacement 
     * n'a été effectué.
     */
    Piece* deplace_piece(const Pos origine, const Pos destination);

    /**
     * @brief Effectue la promotion d'une pièce.
     * @param piece Pointeur vers la pièce à promouvoir.
     * @param promotion Chaîne de caractères représentant la pièce de promotion 
     * (ex: "Q" pour la reine).
     */
    void promotion(Piece* piece, const string promotion);

    
};

#endif
