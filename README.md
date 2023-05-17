# Projet d'échecs

Ce projet implémente un jeu d'échecs en C++ avec les fonctionnalités principales du jeu.

## Contenu

Le projet est organisé en plusieurs fichiers d'en-tête (.hpp) et fichiers source (.cpp) 
contenus respectivement dans les dossiers include et source (le dossier obj servant à la compilation):

- `pos.hpp` : Définition de la classe `Pos` pour représenter une position sur l'échiquier.
- `square.hpp` : Définition de la classe `Square` héritant de `Pos` pour représenter une case de l'échiquier.
- `piece.hpp` : Définition de la classe abstraite `Piece` représentant une pièce d'échecs.
    - En hérite : `roi.hpp`,`dame.hpp`, `fou.hpp`, `cavalier.hpp`,`tour.hpp`, `pion.hpp`
    qui définissent la classe et donc les mouvements légaux de ces pièces.
- `echiquier.hpp` : Définition de la classe `Echiquier` représentant l'échiquier et les pièces en jeu.
- `utilitaire.hpp` : Définition de fonctions utilitaires pour le jeu d'échecs.
- `jeu.hpp` : Définition de la classe `Jeu` qui gère le déroulement du jeu d'échecs.

## Compilation

Le projet peut être compilé à l'aide du Makefile :
Exemple de compilation : `make`
Pour nettoyer les dossier : `make clean`


## Utilisation

Pour jouer au jeu d'échecs, exécutez le fichier exécutable `./bin/echecs` obtenu après la compilation.

Suivez les instructions affichées à l'écran pour entrer les mouvements et interagir avec le jeu.

## Implémentation :
### Réussi :
    - Déplacement basique des pieces
    - Prise en charge des cousp (alternance, entrée sortie, etc...)
    - Détection de l'échec au roi
    - Promotion d'un pion
    - Caractère spécial du pion (1er mouvement, prise en passant)
    - Grand et petit roque

### A faire :
    - Revoir la promotion
    - Echec et math implémenté mais à revoir
    - Path

## Tests
Passe tous les tests 1, 2. Une partie des 3, pas les 4.
Pour utiliser la batterie de test : `./test-level.sh <1-4> ./bin/echecs`

## Auteur

Ce projet a été développé par Killian Cavalier grâce aux outils à sa disposition,
et dans le cadre de la formation à la Programmation Orientée Objet proposée par
Stéphane Guenaud à Télécom Physique Strasbourg.


