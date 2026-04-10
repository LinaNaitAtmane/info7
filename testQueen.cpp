// =============================================================================
// testQueen.cpp — Test des déplacements de la Reine
// =============================================================================
// La reine combine les mouvements de la tour et du fou.
// Elle peut donc se déplacer en ligne droite ET en diagonale.
//
// Ici : on charge la position FEN1 et on affiche les mouvements
//       de la reine blanche qui s'y trouve.
// Usage : ./test_queen
// =============================================================================
#include <iostream>
using namespace std;
#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"

int main()
{
    Board T;
    Mask M;

    empty(T);
    empty_mask(M);

    // On charge la position depuis le fichier FEN
    read_FEN(T, "FEN1.txt");

    // La reine blanche est en h5 dans FEN1, soit la case [4][7]
    highlight_possible_moves(4, 7, T, M);
    cout << "Reine blanche en h5 (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}