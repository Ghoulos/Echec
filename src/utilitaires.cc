#include "../include/jeu.hpp"
#include "../include/utilitaires.hpp"

bool entree_valide(string const & input){
    return (entree_mouvement(input)
        || entree_petit_rock(input)
        || entree_grand_rock(input)
        || entree_sortie(input)
        || entree_egalite(input)
        || entree_abandon(input));
}

bool promotion_valide(string const & input){
    return promotion_dame(input)
        || promotion_tour(input)
        || promotion_fou(input)
        || promotion_cavalier(input);
}

bool entree_mouvement(string const & input){
    regex pattern("^ *[a-h][1-8][a-h][1-8] *$|^ */(quit|draw|resign) *$");
    return regex_match(input, pattern);
}

bool entree_petit_rock(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool entree_grand_rock(string const & input) {
    regex pattern("(O|o|0)-(O|o|0)-(O|o|0)\\s*");
    return regex_match(input,pattern);
}

bool entree_sortie(string const & input){
    regex pattern("/quit\\s*");
    return regex_match(input,pattern);
}

bool entree_egalite(string const & input){
    regex pattern("/draw\\s*");
    return regex_match(input,pattern);
}

bool entree_abandon(string const & input){
    regex pattern("/resign\\s*");
    return regex_match(input,pattern);
}

bool promotion_dame(string const & input){
    regex pattern("(Q|q)\\s*");
    return regex_match(input,pattern);
}

bool promotion_tour(string const & input){
    regex pattern("(R|r)\\s*");
    return regex_match(input,pattern);
}

bool promotion_fou(string const & input){
    regex pattern("(B|b)\\s*");
    return regex_match(input,pattern);
}

bool promotion_cavalier(string const & input){
    regex pattern("(N|n)\\s*");
    return regex_match(input,pattern);
}