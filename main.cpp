#include <iostream>
#include <string>
using namespace std;

#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"

// ============================================================
//  Fonctions de test (reprises des fichiers test*.cpp)
// ============================================================

void test_read_FEN()
{
    cout << "\n=== TEST : Lecture FEN (FEN1.txt) ===" << endl;
    Board T;
    empty(T);
    read_FEN(T, "FEN1.txt");
    print_board(T);
}

void test_write_FEN()
{
    cout << "\n=== TEST : Ecriture FEN (output_start.txt) ===" << endl;
    Board T;
    start(T);
    write_FEN(T, "output_start.txt");
    cout << "Plateau de depart ecrit dans output_start.txt" << endl;
    print_board(T);
}

void test_pawn()
{
    Board T;
    Mask M;

    // Test 1 : pion blanc sur sa ligne de depart (e2 = [1][4])
    empty(T);
    empty_mask(M);
    set_square(1, 4, T, P);
    set_square(2, 3, T, n); // cavalier noir en d3 : prise possible
    highlight_possible_moves_pawn(1, 4, T, M);
    cout << "\n=== TEST PION ===" << endl;
    cout << "Pion blanc en e2 sur ligne de depart (cavalier noir en d3) :" << endl;
    print_board_color(T, M);

    // Test 2 : pion noir sur sa ligne de depart (e7 = [6][4])
    empty(T);
    empty_mask(M);
    set_square(6, 4, T, p);
    set_square(5, 5, T, B); // fou blanc en f6 : prise possible
    highlight_possible_moves_pawn(6, 4, T, M);
    cout << "Pion noir en e7 sur ligne de depart (fou blanc en f6) :" << endl;
    print_board_color(T, M);

    // Test 3 : pion blanc bloque
    empty(T);
    empty_mask(M);
    set_square(3, 3, T, P);
    set_square(4, 3, T, n); // piece devant : bloque l'avance
    highlight_possible_moves_pawn(3, 3, T, M);
    cout << "Pion blanc en d4 bloque par un cavalier noir en d5 :" << endl;
    print_board_color(T, M);
}

void test_knight()
{
    Board T;
    Mask M;

    empty(T);
    empty_mask(M);
    set_square(3, 3, T, N);
    set_square(5, 4, T, p); // pion noir attaquable
    highlight_possible_moves_knight(3, 3, T, M);
    cout << "\n=== TEST CAVALIER ===" << endl;
    cout << "Cavalier blanc en d4 (pion noir en e6) :" << endl;
    print_board_color(T, M);
}

void test_bishop()
{
    Board T;
    Mask M;

    empty(T);
    empty_mask(M);
    set_square(0, 2, T, B);
    set_square(2, 4, T, p); // pion noir en e3
    highlight_possible_moves_bishop(0, 2, T, M);
    cout << "\n=== TEST FOU ===" << endl;
    cout << "Fou blanc en c1 (pion noir en e3) :" << endl;
    print_board_color(T, M);
}

void test_rook()
{
    Board T;
    Mask M;

    empty(T);
    empty_mask(M);
    set_square(3, 3, T, R);
    set_square(6, 3, T, p);
    set_square(3, 6, T, P); // pion allie bloque a droite
    highlight_possible_moves_rook(3, 3, T, M);
    cout << "\n=== TEST TOUR ===" << endl;
    cout << "Tour blanche en d4 (pion noir en d7, pion blanc en g4) :" << endl;
    print_board_color(T, M);
}

void test_queen()
{
    Board T;
    Mask M;

    empty(T);
    empty_mask(M);
    read_FEN(T, "FEN1.txt");
    highlight_possible_moves(4, 7, T, M);
    cout << "\n=== TEST REINE ===" << endl;
    cout << "Reine blanche en h5 (FEN1) :" << endl;
    print_board_color(T, M);
}

void test_king()
{
    Board T;
    Mask M;

    // Test 1 : roi blanc au centre (e4 = [3][4])
    empty(T);
    empty_mask(M);
    set_square(3, 4, T, K);
    set_square(3, 6, T, n); // cavalier noir a droite : prise possible
    highlight_possible_moves_king(3, 4, T, M);
    cout << "\n=== TEST ROI ===" << endl;
    cout << "Test 1 - Roi blanc en e4 (cavalier noir en g4) :" << endl;
    print_board_color(T, M);

    // Test 2 : roi noir en coin (a8 = [7][0])
    empty(T);
    empty_mask(M);
    set_square(7, 0, T, k);
    set_square(6, 0, T, R); // tour blanche : prise possible
    highlight_possible_moves_king(7, 0, T, M);
    cout << "Test 2 - Roi noir en a8 (tour blanche en a7) :" << endl;
    print_board_color(T, M);
}

void test_movable()
{
    Board T;
    Mask M;

    read_FEN(T, "FEN1.txt");
    empty_mask(M);

    cout << "\n=== TEST PIECES DEPLACABLES ===" << endl;
    highlight_movable_pieces(T, M, true);
    cout << "Pieces blanches pouvant se deplacer (FEN1) :" << endl;
    print_board_color(T, M);

    empty_mask(M);
    highlight_movable_pieces(T, M, false);
    cout << "Pieces noires pouvant se deplacer (FEN1) :" << endl;
    print_board_color(T, M);
}

void test_attacked()
{
    Board T;
    Mask M;

    read_FEN(T, "FEN1.txt");
    empty_mask(M);

    highlight_attacked_pieces(T, M, true);
    cout << "\n=== TEST PIECES ATTAQUEES ===" << endl;
    cout << "Pieces noires attaquees (rouge) / non attaquees (vert) par les blancs (FEN1) :" << endl;
    print_board_color(T, M);
}

void test_take()
{
    Board T;
    Mask M;

    read_FEN(T, "FEN1.txt");
    empty_mask(M);

    highlight_take_pieces(3, 4, T, M);
    cout << "\n=== TEST QUI PEUT PRENDRE ===" << endl;
    cout << "Pieces noires pouvant prendre le pion blanc en e4 (FEN1) :" << endl;
    print_board_color(T, M);
}

// ============================================================
//  Menu principal
// ============================================================

void afficher_menu()
{
    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║         MENU DES TESTS ECHECS        ║" << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
    cout << "║  1. Lire un fichier FEN              ║" << endl;
    cout << "║  2. Ecrire un fichier FEN            ║" << endl;
    cout << "║  3. Deplacements du Pion             ║" << endl;
    cout << "║  4. Deplacements du Cavalier         ║" << endl;
    cout << "║  5. Deplacements du Fou              ║" << endl;
    cout << "║  6. Deplacements de la Tour          ║" << endl;
    cout << "║  7. Deplacements de la Reine         ║" << endl;
    cout << "║  8. Deplacements du Roi              ║" << endl;
    cout << "║  9. Pieces pouvant se deplacer       ║" << endl;
    cout << "║ 10. Pieces attaquees                 ║" << endl;
    cout << "║ 11. Qui peut prendre une piece ?     ║" << endl;
    cout << "║  0. Quitter                          ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << "Choix : ";
}

int main()
{
    int choix = -1;

    while (choix != 0)
    {
        afficher_menu();
        cin >> choix;

        switch (choix)
        {
        case 1:
            test_read_FEN();
            break;
        case 2:
            test_write_FEN();
            break;
        case 3:
            test_pawn();
            break;
        case 4:
            test_knight();
            break;
        case 5:
            test_bishop();
            break;
        case 6:
            test_rook();
            break;
        case 7:
            test_queen();
            break;
        case 8:
            test_king();
            break;
        case 9:
            test_movable();
            break;
        case 10:
            test_attacked();
            break;
        case 11:
            test_take();
            break;
        case 0:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide, reessayez." << endl;
            break;
        }
    }

    return 0;
}