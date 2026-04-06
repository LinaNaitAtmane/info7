// test_take.cpp : teste highlight_take_pieces
// Affiche les pièces adverses pouvant prendre une pièce donnée
// Usage : ./test_take
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

    // Qui peut prendre le pion blanc en e4 ([3][4]) ?
    highlight_take_pieces(3, 4, T, M);
    cout << "Pièces noires pouvant prendre le pion blanc en e4 (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}