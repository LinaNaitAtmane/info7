// test_queen.cpp : teste les déplacements possibles de la Reine
// Usage : ./test_queen
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

    // Reine blanche en h5 ([4][7]) comme dans l'exemple du sujet
    empty(T);
    empty_mask(M);
    read_FEN(T, "FEN1.txt");
    // La dame blanche est en h5 dans FEN1
    // On cherche sa position dans le FEN : rnbqkbnr/pppp1p1p/6p1/4p2Q/4P3/8/PPPP1PPP/RNB1KBNR
    // Q est en h5 => [4][7]
    highlight_possible_moves(4, 7, T, M);
    cout << "Reine blanche en h5 (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}