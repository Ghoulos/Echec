#ifndef H_PIECE
#define H_PIECE

#include <iostream>
#include "square.hpp"

typedef enum {Blanc = 0, Noir = 1} couleur_t;
typedef enum {EnJeu = 0, Promue = 1, Capture = 2} etat_t;

using namespace std;

class Square;

/**
 * @brief Classe abstraite représentant une pièce du jeu d'échecs.
 * 
 * La classe Piece est la classe de base pour toutes les pièces du jeu d'échecs, elle est abstraite et contient
 * des méthodes virtuelles pour définir les comportements des différentes pièces.
 */
class Piece {
protected:
    couleur_t couleur; /**< Couleur de la pièce (blanc ou noir). */
    string icone; /**< Icône de la pièce (caractère unicode correspondant). */
    Square* position; /**< Pointeur vers la case occupée par la pièce. */
    etat_t etat; /**< État de la pièce (en jeu, pièce jouée ou capturée). */
    int id; /**< Identifiant unique de la pièce. */
    size_t nbDeplacement; /**< Nombre de déplacements effectués par la pièce. */

public:
    /**
     * @brief Constructeur de la classe Piece.
     * @param couleur Couleur de la pièce (blanc ou noir).
     * @param icone Icône de la pièce (caractère unicode correspondant).
     * @param id Identifiant unique de la pièce.
     * @param position Pointeur vers la case occupée par la pièce.
     */
    Piece(couleur_t couleur, string icone, int id, Square* position);

    /**
     * @brief Destructeur de la classe Piece.
     */
    virtual ~Piece();

    /**
     * @brief Modifie la case occupée par la pièce.
     * @param position Pointeur vers la nouvelle case occupée par la pièce.
     */
    void setSquare(Square* position);

    /**
     * @brief Obtient la case occupée par la pièce.
     * @return Pointeur vers la case occupée par la pièce.
     */
    Square* getSquare() const;

    /**
     * @brief Obtient la couleur de la pièce.
     * @return Couleur de la pièce (blanc ou noir).
     */
    couleur_t getCouleur() const;
    /**
     * @brief Obtient l'etat de la pièce.
     * @return etat de la pièce (EnJeu, Promue, Capture).
     */
    etat_t getEtat() const;

    /**
     * @brief Obtient l'icône de la pièce.
     * @return Icône de la pièce (caractère unicode correspondant).
     */
    string getIcone() const;

    /**
     * @brief Obtient l'identifiant unique de la pièce.
     * @return Identifiant de la pièce, caractérisant sa place dans la memoire de l'échiquier.
     */
    int getId() const ;

    /**
     * @brief Obtient le nombre de déplacements effectués par la pièce.
     * @return Nombre de déplacements effectués par la pièce.
     */
    size_t getNbDeplacement() const;

    /**
     * @brief Modifie le nombre de déplacements effectués par la pièce.
     * @param nbDeplacement Nouveau nombre de déplacements effectués par la pièce.
     */
    void setNbDeplacement(size_t nbDeplacement);

    /**
     * @brief Incrémente le nombre de déplacements effectués par la pièce de 1.
     */
    void incr_nb_deplacement();

    /**
     * @brief Affiche le code unicode de la piece
     */
    void affiche();

    /** y compris sa couleur, son icône, son identifiant et sa case occupée.
     * @brief modifie l'état de la piece.
     * @param etata à destination de la piece
     */
    void set_etat(etat_t etat);



    /**
     * @brief Vérifie si un mouvement vers une case donnée est légal pour la pièce.
     * @param square La case vers laquelle effectuer le mouvement.
     * @param mouvCapture Spécifie si le mouvement est un mouvement de capture
     * (pour les pions)
     * @return true si le mouvement est légal, false sinon.
     */
    virtual bool mouvement_legal(Square square, bool mouvCapture = false);
};

#endif
