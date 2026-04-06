// test_king.cpp : teste les déplacements possibles du Roi
// Usage : ./test_king
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

    // Test 1 : roi blanc au centre (position e4 = case [3][4])
    empty(T);
    empty_mask(M);
    set_square(3, 4, T, K);
    set_square(3, 6, T, n); // cavalier noir à droite : prise possible
    highlight_possible_moves_king(3, 4, T, M);
    cout << "Test 1 - Roi blanc en e4 (cavalier noir en g4) :" << endl;
    print_board_color(T, M);

    // Test 2 : roi noir en coin (a8 = case [7][0])
    empty(T);
    empty_mask(M);
    set_square(7, 0, T, k);
    set_square(6, 0, T, R); // tour blanche : prise possible
    highlight_possible_moves_king(7, 0, T, M);
    cout << "Test 2 - Roi noir en a8 (tour blanche en a7) :" << endl;
    print_board_color(T, M);

    return 0;
}