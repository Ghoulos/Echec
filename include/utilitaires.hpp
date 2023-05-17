#ifndef H_UTILITAIRE
#define H_UTILITAIRE

/**
 * @brief Vérifie si une entrée donnée est valide.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée est valide, false sinon.
 */
bool entree_valide(const string& input);

/**
 * @brief Vérifie si une entrée de promotion donnée est valide.
 * @param input Chaîne de caractères représentant l'entrée de promotion à vérifier.
 * @return true si l'entrée de promotion est valide, false sinon.
 */
bool promotion_valide(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à un mouvement.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à un mouvement, false sinon.
 */
bool entree_mouvement(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à un petit roque.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à un petit roque, false sinon.
 */
bool entree_petit_rock(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à un grand roque.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à un grand roque, false sinon.
 */
bool entree_grand_rock(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à une sortie ie '/quit'.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à une sortie, false sinon.
 */
bool entree_sortie(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à une demande d'égalité ie
 * '/draw'.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à une demande d'égalité, false sinon.
 */
bool entree_egalite(const string& input);

/**
 * @brief Vérifie si une entrée donnée correspond à un abandon is '/resign'.
 * @param input Chaîne de caractères représentant l'entrée à vérifier.
 * @return true si l'entrée correspond à un abandon, false sinon.
 */
bool entree_abandon(const string& input);

/**
 * @brief Vérifie si une entrée de promotion donnée correspond à une promotion en dame.
 * @param input Chaîne de caractères représentant l'entrée de promotion à vérifier.
 * @return true si l'entrée de promotion correspond à une promotion en dame, false sinon.
 */
bool promotion_dame(const string& input);

/**
 * @brief Vérifie si une entrée de promotion donnée correspond à une promotion en tour.
 * @param input Chaîne de caractères représentant l'entrée de promotion à vérifier.
 * @return true si l'entrée de promotion correspond à une promotion en tour, false sinon.
 */
bool promotion_tour(const string& input);

/**
 * @brief Vérifie si une entrée de promotion donnée correspond à une promotion en fou.
 * @param input Chaîne de caractères représentant l'entrée de promotion à vérifier.
 * @return true si l'entrée de promotion correspond à une promotion en fou, false sinon.
 */
bool promotion_fou(const string& input);

/**
 * @brief Vérifie si une entrée de promotion donnée correspond à une promotion en cavalier.
 * @param input Chaîne de caractères représentant l'entrée de promotion à vérifier.
 * @return true si l'entrée de promotion correspond à une promotion en cavalier, false sinon.
 */
bool promotion_cavalier(const string& input);

#endif