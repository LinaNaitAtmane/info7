// =============================================================================
// testKing.cpp — Test des déplacements du Roi
// =============================================================================
// Ce programme teste la fonction highlight_possible_moves_king sur deux cas :
//   Test 1 : roi blanc au centre du plateau (beaucoup de liberté)
//   Test 2 : roi noir dans un coin (moins de cases accessibles)
// Usage : ./test_king
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

    // --- Test 1 : Roi blanc au centre en e4 (case [3][4]) ---
    // Le roi peut aller dans toutes les directions depuis le centre.
    // Un cavalier noir est placé à droite (g4 = [3][6]) : prise possible.
    empty(T);
    empty_mask(M);
    set_square(3, 4, T, K);
    set_square(3, 6, T, n);
    highlight_possible_moves_king(3, 4, T, M);
    cout << "Test 1 - Roi blanc en e4 (cavalier noir en g4) :" << endl;
    print_board_color(T, M);

    // --- Test 2 : Roi noir dans le coin a8 (case [7][0]) ---
    // En coin, le roi n'a accès qu'à 3 cases au lieu de 8.
    // Une tour blanche est en a7 ([6][0]) : prise possible.
    empty(T);
    empty_mask(M);
    set_square(7, 0, T, k);
    set_square(6, 0, T, R);
    highlight_possible_moves_king(7, 0, T, M);
    cout << "Test 2 - Roi noir en a8 (tour blanche en a7) :" << endl;
    print_board_color(T, M);

    return 0;
}