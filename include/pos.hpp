#ifndef H_POS
#define H_POS

#include <iostream>
#include <memory>

using namespace std;

/**
 * @brief Classe représentant une position dans un espace bidimensionnel.
 */
class Pos
{
private:
    int x; /**< Coordonnée X de la position */
    int y; /**< Coordonnée Y de la position */

public:
    /**
     * @brief Constructeur de la classe Pos.
     * @param x Coordonnée X de la position.
     * @param y Coordonnée Y de la position.
     */
    Pos(int x, int y);

    /**
     * @brief Constructeur de la classe Pos prenant une chaîne de caractères pour initialiser les coordonnées.
     * @param str Chaîne de caractères représentant la position au format d'une pièce d'échiquier.
     */
    Pos(string str);

    /**
     * @brief Destructeur de la classe Pos.
     */
    ~Pos();

    /**
     * @brief Obtient la coordonnée X de la position.
     * @return La coordonnée X.
     */
    int getX() const;

    /**
     * @brief Obtient la coordonnée Y de la position.
     * @return La coordonnée Y.
     */
    int getY() const;

    /**
     * @brief Modifie la coordonnée X de la position.
     * @param x Nouvelle coordonnée X.
     */
    void setX(int x);

    /**
     * @brief Modifie la coordonnée Y de la position.
     * @param y Nouvelle coordonnée Y.
     */
    void setY(int y);

    /**
     * @brief Affiche les coordonnées X et Y de la position.
     */
    void affiche_xy() const;

    /**
     * @brief Surcharge de l'opérateur d'égalité pour comparer deux positions.
     * @param other L'autre position à comparer.
     * @return true si les positions sont égales, false sinon.
     */
    bool operator==(const Pos &other) const;
};

#endif
