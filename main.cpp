
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"
#include <iostream>
using namespace std;

int main()
{
    Board board;
    empty(board);
    read_FEN(board, "FEN1.txt");

    // Créer un masque de test
    Mask mask;
    empty_mask(mask);

    // Mettre des valeurs dans le masque pour tester
    // val=1 (bleu) sur quelques cases
    set_mask(4, 4, mask, 1);
    set_mask(4, 3, mask, 1);
    set_mask(5, 4, mask, 1);
    // val=2 (rouge) sur d'autres
    set_mask(7, 0, mask, 2);
    set_mask(7, 7, mask, 2);
    // val=3 (vert) sur d'autres
    set_mask(0, 0, mask, 3);
    set_mask(0, 7, mask, 3);

    cout << "Plateau avec masque :" << endl;
    print_board_color(board, mask);

    return 0;
}