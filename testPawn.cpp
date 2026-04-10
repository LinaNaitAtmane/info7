// =============================================================================
// testPawn.cpp — Test des déplacements du Pion
// =============================================================================
// Le pion est la pièce la plus complexe en déplacement :
//   - Il avance tout droit (d'une ou deux cases depuis sa ligne de départ)
//   - Il prend en diagonale (uniquement)
//   - Il ne peut jamais reculer
//
// Ce programme teste trois situations différentes.
// Usage : ./test_pawn
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

    // --- Test 1 : Pion blanc en e2 (ligne de départ) ---
    // Il peut avancer d'une ou deux cases.
    // Un cavalier noir en d3 peut être pris en diagonale.
    empty(T);
    empty_mask(M);
    set_square(1, 4, T, P); // Pion blanc en e2 (ligne de départ blanc = ligne 1)
    set_square(2, 3, T, n); // Cavalier noir en d3 : prise possible

    highlight_possible_moves_pawn(1, 4, T, M);
    cout << "Test 1 - Pion blanc en e2 sur ligne de depart (cavalier noir en d3) :" << endl;
    print_board_color(T, M);

    // --- Test 2 : Pion noir en e7 (ligne de départ) ---
    // Il peut avancer d'une ou deux cases vers le bas.
    // Un fou blanc en f6 peut être pris en diagonale.
    empty(T);
    empty_mask(M);
    set_square(6, 4, T, p); // Pion noir en e7 (ligne de départ noir = ligne 6)
    set_square(5, 5, T, B); // Fou blanc en f6 : prise possible

    highlight_possible_moves_pawn(6, 4, T, M);
    cout << "Test 2 - Pion noir en e7 sur ligne de depart (fou blanc en f6) :" << endl;
    print_board_color(T, M);

    // --- Test 3 : Pion blanc bloqué ---
    // La case devant est occupée par un cavalier noir : impossible d'avancer.
    empty(T);
    empty_mask(M);
    set_square(3, 3, T, P); // Pion blanc en d4
    set_square(4, 3, T, n); // Cavalier noir en d5 : bloque l'avance (pas de prise tout droit)

    highlight_possible_moves_pawn(3, 3, T, M);
    cout << "Test 3 - Pion blanc en d4 bloque par un cavalier noir en d5 :" << endl;
    print_board_color(T, M);

    return 0;
}