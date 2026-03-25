#include <iostream>
using namespace std;

enum Piece
{
    r,
    n,
    b,
    q,
    k,
    p,
    R,
    N,
    B,
    Q,
    K,
    P,
    vide
};
// creer un plateau vide empty:on cree un tableau de 2 dimensions 8 cases horizontales et 8 verticales
void empty(Piece T[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            T[i][j] = vide;
        }
    }
}
// recuperer le contenu d'une case
/// Faut verifier que les chiffres entres sont dans l'intervalle 0 et 8
Piece get_square(int n, int m, Piece T[8][8])
{
    if ((n < 0) or (n = > 8) or (m < 0) or (m = > 8))
    {
        cout << "Erreur" return vide;
    }
    else
    {
        return T[n][m];
    }
}
// modifier le contenu d’une case set square
void set_square(int n, int m, Piece T[8][8], Piece x)
{
    T[n][m] = x;
}
// initialiser le plateau avec ses pieces start
void start(Piece T[8][8])
{
    empty(T);
    T[0][0] = r;
    T[0][1] = n;
    T[0][2] = b;
    T[0][3] = q;
    T[0][4] = k;
    T[0][5] = b;
    T[0][6] = n;
    T[0][7] = r;
    for ((int i = 0; i < 8; i++) and (j = 1))
    {
        T[i][j] = p;
    }
    for ((int i = 0; i < 8; i++) and (j = 6))
    {
        T[i][j] = P;
    }
    T[7][0] = R;
    T[7][1] = N;
    T[7][2] = B;
    T[7][3] = Q;
    T[7][4] = K;
    T[7][5] = B;
    T[7][6] = N;
    T[7][7] = R;
}
////////Deplacer une piece d'une case a une autre case
void move_piece(int i1, int j1, int i2, int j2, Piece T[8][8])
{
    T[i2][j2] = T[i1][j1];
    T[i1][j1] = vide;
}

///////Tableau 1D
enum Piece
{
    r,
    n,
    b,
    q,
    k,
    p,
    R,
    N,
    B,
    Q,
    K,
    P,
    vide
};

// créer un plateau vide (tableau 1D de 64 cases)
void empty1(Piece T[64])
{
    for (int i = 0; i < 64; i++)
    {
        T[i] = vide;
    }
}

// récupérer le contenu d'une case
Piece get_square1(int n, int m, Piece T[64])
{
    if ((n < 0) || (n >= 8) || (m < 0) || (m >= 8))
    {
        cout << "Erreur";
        return vide;
    }
    else
    {
        return T[n * 8 + m];
    }
}

// modifier le contenu d’une case
void set_square1(int n, int m, Piece T[64], Piece x)
{
    if (n >= 0 && n < 8 && m >= 0 && m < 8)
        T[n * 8 + m] = x;
}

// initialiser le plateau avec ses pièces
void start1(Piece T[64])
{
    empty(T);

    T[0 * 8 + 0] = r;
    T[0 * 8 + 1] = n;
    T[0 * 8 + 2] = b;
    T[0 * 8 + 3] = q;
    T[0 * 8 + 4] = k;
    T[0 * 8 + 5] = b;
    T[0 * 8 + 6] = n;
    T[0 * 8 + 7] = r;

    // pions noirs
    for (int i = 0; i < 8; i++)
        T[1 * 8 + i] = p;

    // pions blancs
    for (int i = 0; i < 8; i++)
        T[6 * 8 + i] = P;

    // ligne blanche
    T[7 * 8 + 0] = R;
    T[7 * 8 + 1] = N;
    T[7 * 8 + 2] = B;
    T[7 * 8 + 3] = Q;
    T[7 * 8 + 4] = K;
    T[7 * 8 + 5] = B;
    T[7 * 8 + 6] = N;
    T[7 * 8 + 7] = R;
}

// déplacer une pièce d'une case à une autre
void move_piece1(int i1, int j1, int i2, int j2, Piece T[64])
{
    T[i2 * 8 + j2] = T[i1 * 8 + j1];
    T[i1 * 8 + j1] = vide;
}

struct Game {
    Piece T[8][8];
};
