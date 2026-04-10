// =============================================================================
// testRook.cpp — Test des déplacements de la Tour
// =============================================================================
// La tour se déplace en ligne droite (horizontal/vertical).
// Elle est bloquée par les pièces sur son chemin.
//
// Ici : Tour blanche en d4, pion noir en d7 (prise possible vers le haut),
//       pion blanc en g4 (bloque vers la droite).
// Usage : ./test_rook
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
    set_square(3, 3, T, R); // Tour blanche en d4
    set_square(6, 3, T, p); // Pion noir en d7 (prise possible)
    set_square(3, 6, T, P); // Pion blanc en g4 (bloque, pas de prise)

    highlight_possible_moves_rook(3, 3, T, M);
    cout << "Tour blanche en d4 (pion noir en d7, pion blanc en g4) :" << endl;
    print_board_color(T, M);

    return 0;
}