#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "types.hpp" // contient enum Piece et Board
#include "board.hpp" // contient read_FEN et print_board
#include "view.cpp"
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage : " << argv[0] << " fichier_FEN.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    Board T;
    empty(T); // initialise le plateau vide

    read_FEN(T,filename) // lit le fichier FEN et remplit le plateau
    print_board(T);        // affiche le plateau

    return 0;
}
//.\test_read_FEN  FEN1.txt