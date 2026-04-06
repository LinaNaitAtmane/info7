// test_rook.cpp : teste les déplacements possibles de la Tour
// Usage : ./test_rook
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

    // Tour blanche en d4 ([3][3]), pion noir en d7 ([6][3])
    empty(T);
    empty_mask(M);
    set_square(3, 3, T, R);
    set_square(6, 3, T, p);
    set_square(3, 6, T, P); // pion allié bloque à droite
    highlight_possible_moves_rook(3, 3, T, M);
    cout << "Tour blanche en d4 (pion noir en d7, pion blanc en g4) :" << endl;
    print_board_color(T, M);

    return 0;
}