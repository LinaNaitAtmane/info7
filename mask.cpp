#include "mask.hpp"
#include <iostream>
using namespace std;

// Créer un masque sans information
void empty_mask(Mask M)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            M[i][j] = 0;
}

// Réinitialiser un masque à 0
void clear_mask(Mask M)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            M[i][j] = 0;
}

// Lire le contenu d'une case du masque
int get_mask(int i, int j, Mask M)
{
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
        return 0;
    return M[i][j];
}

// Modifier le contenu d'une case du masque
void set_mask(int i, int j, Mask M, int val)
{
    if (i >= 0 && i < 8 && j >= 0 && j < 8)
        M[i][j] = val;
}