// =============================================================================
// testMovable.cpp — Test de highlight_movable_pieces
// =============================================================================
// Affiche toutes les pièces d'un joueur qui ont au moins un déplacement
// possible. Elles apparaissent surlignées en bleu sur le plateau.
//
// Ce test charge la position depuis FEN1.txt.
// Usage : ./test_movable
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

    // Pièces blanches qui peuvent se déplacer
    highlight_movable_pieces(T, M, true);
    cout << "Pieces blanches pouvant se deplacer (FEN1) :" << endl;
    print_board_color(T, M);

    // Pièces noires qui peuvent se déplacer
    empty_mask(M);
    highlight_movable_pieces(T, M, false);
    cout << "Pieces noires pouvant se deplacer (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}