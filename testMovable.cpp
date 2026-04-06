// test_movable.cpp : teste highlight_movable_pieces
// Affiche toutes les pièces blanches pouvant se déplacer
// Usage : ./test_movable
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

    read_FEN(T, "FEN1.txt");
    empty_mask(M);

    // Pièces blanches pouvant se déplacer
    highlight_movable_pieces(T, M, true);
    cout << "Pièces blanches pouvant se déplacer (FEN1) :" << endl;
    print_board_color(T, M);

    // Pièces noires pouvant se déplacer
    empty_mask(M);
    highlight_movable_pieces(T, M, false);
    cout << "Pièces noires pouvant se déplacer (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}