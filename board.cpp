#include "board.hpp"
#include <iostream>
using namespace std;

/// creer un plateau vide empty
void empty(Board T)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            T[i][j] = vide;
}
/// initialiser le plateau avec ses pi`eces start
void start(Board T)
{
    empty(T);
    // la partie en noir
    T[0][0] = r;
    T[0][1] = n;
    T[0][2] = b;
    T[0][3] = q;
    T[0][4] = k;
    T[0][5] = b;
    T[0][6] = n;
    T[0][7] = r;
    /// On remplie la ligne 1 avec lespions
    for (int j = 0; j < 8; j++)
        T[1][j] = p;

    // en blanc
    T[7][0] = R;
    T[7][1] = N;
    T[7][2] = B;
    T[7][3] = Q;
    T[7][4] = K;
    T[7][5] = B;
    T[7][6] = N;
    T[7][7] = R;
    /// On remplie la ligne 6 avec lespions
    for (int j = 0; j < 8; j++)
        T[6][j] = P;
}
// r´ecup´erer le contenu d’une case get square,
Piece get_square(int i, int j, Board T)
{ ////On verifie que la position choisie est dans l'intervalle 0 et 7
    if ((i < 0) || (i >= 8) || (j < 0) || (j >= 8))
        return vide;
    return T[i][j];
}
// modifier le contenu d’une case set square,
void set_square(int i, int j, Board T, Piece p)
{
    if ((i >= 0) && (i < 8) && (j >= 0) && (j < 8))
        T[i][j] = p;
}
// d´eplacer une pi`ece d’une case de d´epart dans une case d’arriv´ee move piece
void move_piece(int i1, int j1, int i2, int j2, Board T)
{ ////On verifie que les cases choisies sont  dans l'intervalle 0 et 7
    if (i1 < 0 || i1 >= 8 || j1 < 0 || j1 >= 8)
        return;
    if (i2 < 0 || i2 >= 8 || j2 < 0 || j2 >= 8)
        return;
    T[i2][j2] = T[i1][j1];
    T[i1][j1] = vide;
}