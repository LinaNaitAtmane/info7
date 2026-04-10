// =============================================================================
// testAttacked.cpp — Test de highlight_attacked_pieces
// =============================================================================
// Affiche les pièces adverses en danger (rouge) ou protégées (vert).
//
// Rouge = peut être prise au prochain coup par le joueur courant
// Vert  = pièce adverse présente mais non attaquable directement
//
// Ce test charge la position depuis FEN1.txt et affiche les pièces
// noires vues par les blancs.
// Usage : ./test_attacked
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

    // On calcule les pièces noires attaquées par les blancs
    highlight_attacked_pieces(T, M, true);
    cout << "Pieces noires attaquees (rouge) / protegees (vert) par les blancs (FEN1) :" << endl;
    print_board_color(T, M);

    return 0;
}