// =============================================================================
// testTake.cpp — Test de highlight_take_pieces
// =============================================================================
// Affiche toutes les pièces adverses qui peuvent prendre une pièce donnée.
// Les pièces menaçantes apparaissent en rouge sur le plateau.
//
// Ce test charge la position depuis FEN1.txt et cherche qui peut
// prendre le pion blanc en e4 (case [3][4]).
// Usage : ./test_take
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

    read_FEN(T, "FEN1.txt");
    empty_mask(M);

    // On cherche quelles pièces noires peuvent prendre le pion blanc en e4
    highlight_take_pieces(3, 4, T, M);
    cout << "Pieces noires pouvant prendre le pion blanc en e4 (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}