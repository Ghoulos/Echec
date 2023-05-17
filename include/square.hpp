#ifndef H_SQUARE
#define H_SQUARE

#include "../include/pos.hpp"
#include "../include/piece.hpp"
#include <iostream>
#include <memory>

class Piece;

/**
 * @brief Classe représentant une case d'un plateau de jeu.
 * 
 * La classe Square hérite de la classe Pos pour représenter les coordonnées de la case
 */
class Square : public Pos {
  private:
    Piece* piece; /**< Pointeur vers la pièce présente dans la case */

  public:
    /**
     * @brief Constructeur de la classe Square.
     * @param x Coordonnée X de la case.
     * @param y Coordonnée Y de la case.
     * @param piece Pointeur vers la pièce à placer dans la case (par défaut nullptr si la case est vide).
     */
    Square(int x, int y, Piece* piece = nullptr);

    /**
     * @brief Constructeur de la classe Square prenant une chaîne de caractères pour initialiser les coordonnées.
     * @param str Chaîne de caractères représentant la position de la case au format d'un échiquier
     * @param piece Pointeur vers la pièce à placer dans la case (par défaut nullptr si la case est vide).
     */
    Square(string str, Piece* piece = nullptr);

    /**
     * @brief Destructeur de la classe Square.
     */
    ~Square();

    /**
     * @brief Modifie la pièce présente dans la case.
     * @param piece Pointeur vers la nouvelle pièce à placer dans la case.
     */
    void setPiece(Piece* piece);

    /**
     * @brief Obtient la pièce présente dans la case.
     * @return Pointeur vers la pièce présente dans la case.
     */
    Piece* getPiece() const;
    
    /**
     * @brief Vérifie si la case est vide (c'est-à-dire si le pointeur est null).
     * @return true si la case est vide, false sinon.
     */
    bool est_vide();

    /**
     * @brief Affiche la pièce de la case si elle existe, 5 espaces sinon
     */
    void affiche();
};

#endif
