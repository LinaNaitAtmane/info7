// test_bishop.cpp : teste les déplacements possibles du Fou
// Usage : ./test_bishop
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

    // Fou blanc en c1 ([0][2]), plateau de départ
    empty(T);
    empty_mask(M);
    set_square(0, 2, T, B);
    set_square(2, 4, T, p); // pion noir en e3
    highlight_possible_moves_bishop(0, 2, T, M);
    cout << "Fou blanc en c1 (pion noir en e3) :" << endl;
    print_board_color(T, M);

    return 0;
}