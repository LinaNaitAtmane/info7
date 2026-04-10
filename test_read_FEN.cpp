#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "types.hpp"
#include "board.hpp"
#include "view.hpp"

// =============================================================================
// test_read_FEN.cpp — Test de la lecture d'un fichier FEN
// =============================================================================
// Ce programme lit un fichier FEN passé en argument et affiche le plateau
// correspondant en mode texte.
//
// Usage : ./test_read_FEN fichier_FEN.txt
// Exemple : ./test_read_FEN FEN1.txt
// =============================================================================
int main(int argc, char *argv[])
{
    // On vérifie qu'un nom de fichier a été fourni en argument
    if (argc < 2)
    {
        cout << "Usage : " << argv[0] << " fichier_FEN.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    Board T;
    empty(T);              // on vide d'abord le plateau
    read_FEN(T, filename); // on remplit le plateau avec le contenu du fichier FEN
    print_board(T);        // on affiche le résultat en texte simple

    return 0;
}