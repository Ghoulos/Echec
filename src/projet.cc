#include "../include/jeu.hpp"

int main() {
  Jeu monjeu;

  // boucle de jeu, s'arrete a la fin de la partie
  bool stop(false);
  do {
      monjeu.affiche();
      stop = monjeu.coup();
 } while (!stop);
 return 0;
}