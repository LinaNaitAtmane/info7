// =============================================================================
// testBishop.cpp — Test des déplacements du Fou
// =============================================================================
// Le fou se déplace uniquement en diagonale.
// Il est bloqué par toute pièce sur sa diagonale.
//
// Ici : Fou blanc en c1, pion noir en e3 (prise en diagonale haut-droite).
// Usage : ./test_bishop
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
    set_square(0, 2, T, B); // Fou blanc en c1
    set_square(2, 4, T, p); // Pion noir en e3 (prise possible en diagonale)

    highlight_possible_moves_bishop(0, 2, T, M);
    cout << "Fou blanc en c1 (pion noir en e3) :" << endl;
    print_board_color(T, M);

    return 0;
}