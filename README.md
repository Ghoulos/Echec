# Echec

## Projet réalisé par Killian Cavalier

# Les classes utilisées :
## Pos : doublon x,y
    *Square* modélise une case du plateau : Hérité de Pos, contient aussi un pointeur vers une piece

## Piece : Classe virtuelle et générique d'une piece, idetifiée par un int et uen couleur. Contient aussi un pointeur vers la case le contenant.
    En dérive toutes les classes associées au role des pieces :
    Roi, Dame, Pion, Cavalier, Fou, Tour