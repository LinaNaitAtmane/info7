// test_pawn.cpp : teste les déplacements possibles du Pion
// Usage : ./test_pawn
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

    // Test 1 : pion blanc sur sa ligne de départ (e2 = [1][4])
    empty(T);
    empty_mask(M);
    set_square(1, 4, T, P);
    set_square(2, 3, T, n); // cavalier noir en d3 : prise possible
    highlight_possible_moves_pawn(1, 4, T, M);
    cout << "Pion blanc en e2 sur ligne de départ (cavalier noir en d3) :" << endl;
    print_board_color(T, M);

    // Test 2 : pion noir sur sa ligne de départ (e7 = [6][4])
    empty(T);
    empty_mask(M);
    set_square(6, 4, T, p);
    set_square(5, 5, T, B); // fou blanc en f6 : prise possible
    highlight_possible_moves_pawn(6, 4, T, M);
    cout << "Pion noir en e7 sur ligne de départ (fou blanc en f6) :" << endl;
    print_board_color(T, M);

    // Test 3 : pion blanc bloqué (case devant occupée)
    empty(T);
    empty_mask(M);
    set_square(3, 3, T, P);
    set_square(4, 3, T, n); // pièce devant : bloque l'avance
    highlight_possible_moves_pawn(3, 3, T, M);
    cout << "Pion blanc en d4 bloqué par un cavalier noir en d5 :" << endl;
    print_board_color(T, M);

    return 0;
}