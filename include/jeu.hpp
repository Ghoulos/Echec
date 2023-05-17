#ifndef H_JEU
#define H_JEU

#include <iostream>
#include "../include/echiquier.hpp"
#include <memory>
#include <iostream>
#include <regex>

using namespace std;

/**
 * @brief Classe représentant le jeu d'échecs.
 * 
 * La classe Jeu gère le déroulement du jeu d'échecs, les interactions avec les 
 * joueurs, et les règles du jeu.
 */
class Jeu
{
private:
    Echiquier *echiquier; /**< Pointeur vers l'échiquier utilisé dans le jeu. */
    string dernier_mouvement; /**< Chaîne de caractères représentant le dernier
     mouvement effectué. */
    couleur_t couleur_joueur; /**< Couleur du joueur actuel (Blanc ou Noir). */

public:
    /**
     * @brief Constructeur par défaut de la classe Jeu.
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu.
     */
    ~Jeu();

    /**
     * @brief Définit le dernier mouvement effectué.
     * @param move Chaîne de caractères représentant le dernier mouvement.
     */
    void setDernierMouv(string move);

    /**
     * @brief Obtient le dernier mouvement effectué.
     * @return Chaîne de caractères représentant le dernier mouvement.
     */
    string getDernierMouv();

    /**
     * @brief Obtient la couleur du joueur actuel.
     * @return Couleur du joueur actuel (Blanc ou Noir).
     */
    couleur_t getJoueur();

    /**
     * @brief Définit la couleur du joueur actuel.
     * @param c Couleur du joueur (Blanc ou Noir).
     */
    void setJoueur(couleur_t c);

    /**
     * @brief Affiche l'état actuel de l'échiquier.
     */
    void affiche();

    /**
     * @brief Vérifie si le passage entre deux cases est possible, ie il n'y a 
     * pas de pièces (adverses ou pas) gènant le chemin
     * @param posDeb Position de départ.
     * @param posFin Position d'arrivée.
     * @return true si le passage est possible, false sinon.
     */
    bool passage_possible(Pos posDeb, Pos posFin);

    /**
     * @brief Affiche le message de fin de jeu soit la position canonique de
     * l'échiquier et le résultat de fin
     * @param result Résultat de la partie (ex: "Échec et mat").
     */
    void affichage_fin_jeu(string result);

    /**
     * @brief Vérifie si une position donnée est capturable par une couleur donnée.
     * @param pos Position à vérifier.
     * @param c Couleur de la pièce qui peut capturer.
     * @return true si la position est capturable, false sinon.
     */
    bool est_capturable(Pos pos, couleur_t c);

    /**
     * @brief Vérifie si le roi d'une couleur donnée est en échec.
     * @param c Couleur du roi à vérifier.
     * @return true si le roi est en échec, false sinon.
     */
    bool echec_au_roi(couleur_t c);


    /**
     * @brief Vérifie si un déplacement entre deux positions met en échec le roi
     *  d'une couleur donnée.
     * @param posDeb Position de départ.
     * @param posFin Position d'arrivée.
     * @param c Couleur du roi à vérifier.
     * @return true si le déplacement met en échec le roi, false sinon.
     */
    bool met_en_echec(Pos posDeb, Pos posFin, couleur_t c);

    /**
     * @brief Vérifie si une prise en passant est possible entre deux positions.
     * @param posDeb Position de départ.
     * @param posFin Position d'arrivée.
     * @return true si une prise en passant est possible, false sinon.
     */
    bool prise_en_passant(Pos posDeb, Pos posFin);

    /**
     * @brief Réalise le petit roque pour une couleur donnée.
     * @param c Couleur pour laquelle réaliser le petit roque.
     * @return true si le roque a été réalisé avec succès, false sinon.
     */
    bool petit_roque(couleur_t c);

    /**
     * @brief Réalise le grand roque pour une couleur donnée.
     * @param c Couleur pour laquelle réaliser le grand roque.
     * @return true si le roque a été réalisé avec succès, false sinon.
     */
    bool grand_roque(couleur_t c);

    /**
     * @brief Vérifie si une promotion est possible.
     * @param posFin Case du dernier mouvement joué
     * @return true si une promotion est possible, false sinon.
     */
    bool promotion_possible(Pos posFin);

    /**
     * @brief Déplace une pièce d'une position à une autre.
     * @param posDeb Position de départ.
     * @param posFin Position d'arrivée.
     * @param continueJeu Indique sion continue le jeu (utilisé pour les tests)
     * @return true si le déplacement a été effectué avec succès, false sinon.
     */
    bool deplace_piece(Pos posDeb, Pos posFin, bool continueJeu = true);

    /**
     * @brief Gère le déroulement d'un coup.
     * @return retourne true si fin de partie et false sinon.
     */
    bool coup();

    /**
     * @brief regarde si le roi est en mat /!\ ne fonctionne pas
     * @return true si le roi de couleur c est mat
     */
    bool mat(couleur_t c);

    /**
     * @brief Teste tous les mouvements possibles de la piece pour voir si elle
     * peut enlever si il en existe un où son roi n'est pas en echec
     * @param piece Pointeur vers la pièce à promouvoir.
     * @return true si il existe une position où le roi n'est pas en echec,
     * false sinon
     */
    bool enleve_echec(Piece* piece);
};

#endif
