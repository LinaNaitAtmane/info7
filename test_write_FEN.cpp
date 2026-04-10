#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "types.hpp"
#include "view.hpp"
#include "board.hpp"

// =============================================================================
// test_write_FEN.cpp — Test de l'écriture d'un plateau dans un fichier FEN
// =============================================================================
// Ce programme initialise le plateau en position de départ standard,
// puis écrit cette position dans un fichier FEN passé en argument.
//
// Usage : ./test_write_FEN fichier_FEN.txt
// Exemple : ./test_write_FEN FEN_depart.txt
// =============================================================================
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage : " << argv[0] << " fichier_FEN.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    Board T;
    start(T);               // position de départ standard
    write_FEN(T, filename); // on écrit la position dans le fichier

    cout << "Plateau ecrit dans le fichier " << filename << endl;
    return 0;
}