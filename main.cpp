#include <iostream>
#include <string>
using namespace std;

#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"

// -----------------------------------------------------------------------
// Tests des déplacements possibles
// -----------------------------------------------------------------------

void test_pawn()
{
    cout << "=== Test Pion ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Pion blanc en e2 (ligne 1, colonne 4)
    highlight_possible_moves_pawn(1, 4, T, M);
    print_board_color(T, M);
}

void test_knight()
{
    cout << "=== Test Cavalier ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Cavalier blanc en d4 (ligne 3, colonne 3)
    highlight_possible_moves_knight(3, 3, T, M);
    print_board_color(T, M);
}

void test_bishop()
{
    cout << "=== Test Fou ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Fou blanc en a3 (ligne 2, colonne 0)
    highlight_possible_moves_bishop(0, 2, T, M);
    print_board_color(T, M);
}

void test_rook()
{
    cout << "=== Test Tour ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Tour blanche en d4 (ligne 3, colonne 3)
    highlight_possible_moves_rook(3, 3, T, M);
    print_board_color(T, M);
}

void test_queen()
{
    cout << "=== Test Reine ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Reine blanche en d4 (ligne 3, colonne 3)
    highlight_possible_moves_queen(3, 3, T, M);
    print_board_color(T, M);
}

void test_king()
{
    cout << "=== Test Roi ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Roi blanc en e4 (ligne 3, colonne 4)
    highlight_possible_moves_king(3, 4, T, M);
    print_board_color(T, M);
}

void test_movable()
{
    cout << "=== Test Pièces déplaçables (blancs) ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    highlight_movable_pieces(T, M, true);
    print_board_color(T, M);
}

void test_attacked()
{
    cout << "=== Test Pièces attaquées (blancs attaquent noirs) ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    highlight_attacked_pieces(T, M, true);
    print_board_color(T, M);
}

void test_take()
{
    cout << "=== Test Pièces pouvant prendre en e5 ===" << endl;
    Board T;
    Mask M;
    start(T);
    empty_mask(M);

    // Quelle pièce adverse peut prendre en ligne 4, colonne 4 ?
    highlight_take_pieces(4, 4, T, M);
    print_board_color(T, M);
}

// -----------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------
int main()
{
    test_pawn();
    test_knight();
    test_bishop();
    test_rook();
    test_queen();
    test_king();
    test_movable();
    test_attacked();
    test_take();

    return 0;
}