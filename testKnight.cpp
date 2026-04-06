// test_knight.cpp : teste les déplacements possibles du Cavalier
// Usage : ./test_knight
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

    // Cavalier blanc au centre en d4 ([3][3])
    empty(T);
    empty_mask(M);
    set_square(3, 3, T, N);
    set_square(5, 4, T, p); // pion noir attaquable
    highlight_possible_moves_knight(3, 3, T, M);
    cout << "Cavalier blanc en d4 (pion noir en e6) :" << endl;
    print_board_color(T, M);

    return 0;
}