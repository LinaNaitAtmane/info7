#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "types.hpp" // contient enum Piece et Board
#include "view.hpp"
#include "board.hpp" // contient write_FEN et start

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage : " << argv[0] << " fichier_FEN.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    Board T;
    start(T); // initialise le plateau avec les pièces de départ

    write_FEN(T, filename); // écrit le plateau dans le fichier FEN

    cout << "Plateau écrit dans le fichier " << filename << endl;

    return 0;
}
