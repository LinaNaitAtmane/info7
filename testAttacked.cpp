// test_attacked.cpp : teste highlight_attacked_pieces
// Affiche les pièces noires attaquables par les blancs
// Usage : ./test_attacked
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

    // Pièces noires attaquées par les blancs (rouge) / non attaquées (bleu)
    highlight_attacked_pieces(T, M, true);
    cout << "Pièces noires attaquées (rouge) / non attaquées (bleu) par les blancs (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}