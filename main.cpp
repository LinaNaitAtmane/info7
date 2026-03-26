#include "board.hpp"
#include "view.hpp"
#include <iostream>
using namespace std;

int main()
{
    Board board;

    start(board);

    cout << "Plateau initial :" << endl;
    print_board(board);

    // déplacer 2 pièces noires
    move_piece(1, 0, 3, 0, board); // pion a7 -> a5
    move_piece(0, 1, 2, 2, board); // cavalier b8 -> c6

    // déplacer 2 pièces blanches
    move_piece(6, 0, 4, 0, board); // pion a2 -> a4
    move_piece(7, 1, 5, 2, board); // cavalier b1 -> c3

    cout << "\nPlateau après déplacements :" << endl;
    print_board(board);

    // tester write FEN
    write_FEN(board, "FEN_test.txt");
    cout << "\nFEN écrit dans FEN_test.txt" << endl;

    // tester read FEN
    Board newBoard;
    read_FEN(newBoard, "FEN_test.txt");
    cout << "\nLecture FEN :" << endl;
    print_board(newBoard);

    return 0;
}