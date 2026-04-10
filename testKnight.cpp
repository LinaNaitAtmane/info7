// =============================================================================
// testKnight.cpp — Test des déplacements du Cavalier
// =============================================================================
// Le cavalier se déplace en "L" : 2 cases dans une direction puis 1 case
// perpendiculairement. C'est la seule pièce qui peut sauter par-dessus
// les autres pièces.
//
// Ici : Cavalier blanc en d4, pion noir en e6 (prise possible).
// Usage : ./test_knight
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
    set_square(3, 3, T, N); // Cavalier blanc en d4
    set_square(5, 4, T, p); // Pion noir en e6 (à portée du cavalier)

    highlight_possible_moves_knight(3, 3, T, M);
    cout << "Cavalier blanc en d4 (pion noir en e6) :" << endl;
    print_board_color(T, M);

    return 0;
}