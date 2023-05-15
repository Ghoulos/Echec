#include "../include/jeu.hpp"

int main() {
  Jeu monjeu;

  // boucle de jeu, s'arrete a la fin de la partie
  bool stop(false);
  //monjeu.deplace_piece(Pos(1,2),Pos(1,3));
  Pos testPos = Pos("e2");
  testPos.affiche_xy();
  do {
      
      monjeu.affiche();
      stop = monjeu.coup();
  } while (!stop);
  return 0;
}