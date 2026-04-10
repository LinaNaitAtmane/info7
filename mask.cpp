#include "mask.hpp"
#include "board.hpp"
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------
// Opérations de base sur le masque
// -----------------------------------------------------------------------

void empty_mask(Mask M)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            M[i][j] = 0;
}

void clear_mask(Mask M)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            M[i][j] = 0;
}

int get_mask(int i, int j, Mask M)
{
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
        return 0;
    return M[i][j];
}

void set_mask(int i, int j, Mask M, int val)
{
    if (i >= 0 && i < 8 && j >= 0 && j < 8)
        M[i][j] = val;
}

// -----------------------------------------------------------------------
// Roi : se déplace d'une seule case dans les 8 directions
// -----------------------------------------------------------------------
void highlight_possible_moves_king(int i, int j, Board T, Mask M)
{
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    Piece roi = get_square(i, j, T);
    // CORRECTION : on teste si la pièce est blanche (R..P) plutôt que (roi == K)
    bool est_blanc = (roi >= R && roi <= P);

    for (int d = 0; d < 8; d++)
    {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
                set_mask(ni, nj, M, 1);
            else if (est_blanc && cible >= r && cible <= p)
                set_mask(ni, nj, M, 2);
            else if (!est_blanc && cible >= R && cible <= P)
                set_mask(ni, nj, M, 2);
        }
    }
}

// -----------------------------------------------------------------------
// Tour : se déplace en ligne droite (horizontal/vertical)
// -----------------------------------------------------------------------
void highlight_possible_moves_rook(int i, int j, Board T, Mask M)
{
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    Piece tour = get_square(i, j, T);
    // CORRECTION : détection couleur générique
    bool est_blanc = (tour >= R && tour <= P);

    for (int d = 0; d < 4; d++)
    {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                set_mask(ni, nj, M, 1);
                ni += directions[d][0];
                nj += directions[d][1];
            }
            else
            {
                if (est_blanc && cible >= r && cible <= p)
                    set_mask(ni, nj, M, 2);
                else if (!est_blanc && cible >= R && cible <= P)
                    set_mask(ni, nj, M, 2);
                ni = 8; // forcer la sortie du while sans utiliser break
                nj = 8;
            }
        }
    }
}

// -----------------------------------------------------------------------
// Fou : se déplace en diagonale
// -----------------------------------------------------------------------
void highlight_possible_moves_bishop(int i, int j, Board T, Mask M)
{
    int directions[4][2] = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    Piece fou = get_square(i, j, T);
    // CORRECTION : détection couleur générique (avant : fou == B uniquement)
    bool est_blanc = (fou >= R && fou <= P);

    for (int d = 0; d < 4; d++)
    {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                set_mask(ni, nj, M, 1);
                ni += directions[d][0];
                nj += directions[d][1];
            }
            else
            {
                if (est_blanc && cible >= r && cible <= p)
                    set_mask(ni, nj, M, 2);
                else if (!est_blanc && cible >= R && cible <= P)
                    set_mask(ni, nj, M, 2);
                ni = 8; // forcer la sortie du while sans utiliser break
                nj = 8;
            }
        }
    }
}

// -----------------------------------------------------------------------
// Reine : combine tour + fou
// -----------------------------------------------------------------------
void highlight_possible_moves_queen(int i, int j, Board T, Mask M)
{
    highlight_possible_moves_rook(i, j, T, M);
    highlight_possible_moves_bishop(i, j, T, M);
}

// -----------------------------------------------------------------------
// Cavalier : se déplace en L (peut sauter par-dessus les pièces)
// -----------------------------------------------------------------------
void highlight_possible_moves_knight(int i, int j, Board T, Mask M)
{
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    Piece cavalier = get_square(i, j, T);
    // CORRECTION : détection couleur générique
    bool est_blanc = (cavalier >= R && cavalier <= P);

    for (int d = 0; d < 8; d++)
    {
        int ni = i + moves[d][0];
        int nj = j + moves[d][1];

        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
                set_mask(ni, nj, M, 1);
            else if (est_blanc && cible >= r && cible <= p)
                set_mask(ni, nj, M, 2);
            else if (!est_blanc && cible >= R && cible <= P)
                set_mask(ni, nj, M, 2);
        }
    }
}

// -----------------------------------------------------------------------
// Pion : avance tout droit, prend en diagonale
// Blanc : en ligne 6 (rang 1), avance vers les lignes croissantes (+1)
// Noir  : en ligne 1 (rang 6), avance vers les lignes décroissantes (-1)
// -----------------------------------------------------------------------
void highlight_possible_moves_pawn(int i, int j, Board T, Mask M)
{
    Piece pion = get_square(i, j, T);
    bool est_blanc = (pion == P);

    int dir = est_blanc ? 1 : -1;
    // CORRECTION : ligne de départ blanc = 6, noir = 1
    int ligne_depart = est_blanc ? 6 : 1;

    // Avancer d'une case
    int ni = i + dir;
    if (ni >= 0 && ni < 8 && get_square(ni, j, T) == vide)
    {
        set_mask(ni, j, M, 1);

        // Avancer de deux cases depuis la ligne de départ
        if (i == ligne_depart && get_square(i + 2 * dir, j, T) == vide)
            set_mask(i + 2 * dir, j, M, 1);
    }

    // Prise en diagonale gauche
    int pi = i + dir;
    int pj_gauche = j - 1;
    if (pi >= 0 && pi < 8 && pj_gauche >= 0 && pj_gauche < 8)
    {
        Piece cible = get_square(pi, pj_gauche, T);
        if (est_blanc && cible >= r && cible <= p)
            set_mask(pi, pj_gauche, M, 2);
        else if (!est_blanc && cible >= R && cible <= P)
            set_mask(pi, pj_gauche, M, 2);
    }

    // Prise en diagonale droite
    int pj_droite = j + 1;
    if (pi >= 0 && pi < 8 && pj_droite >= 0 && pj_droite < 8)
    {
        Piece cible = get_square(pi, pj_droite, T);
        if (est_blanc && cible >= r && cible <= p)
            set_mask(pi, pj_droite, M, 2);
        else if (!est_blanc && cible >= R && cible <= P)
            set_mask(pi, pj_droite, M, 2);
    }
}

// -----------------------------------------------------------------------
// Dispatcher : appelle la bonne fonction selon la pièce en (i,j)
// -----------------------------------------------------------------------
void highlight_possible_moves(int i, int j, Board T, Mask M)
{
    clear_mask(M);
    Piece piece = get_square(i, j, T);

    switch (piece)
    {
    case K:
    case k:
        highlight_possible_moves_king(i, j, T, M);
        break;
    case R:
    case r:
        highlight_possible_moves_rook(i, j, T, M);
        break;
    case B:
    case b:
        highlight_possible_moves_bishop(i, j, T, M);
        break;
    case Q:
    case q:
        highlight_possible_moves_queen(i, j, T, M);
        break;
    case N:
    case n:
        highlight_possible_moves_knight(i, j, T, M);
        break;
    case P:
    case p:
        highlight_possible_moves_pawn(i, j, T, M);
        break;
    default:
        break;
    }
}

// -----------------------------------------------------------------------
// Met en évidence les pièces du joueur (couleur_blanche) pouvant bouger
// -----------------------------------------------------------------------
void highlight_movable_pieces(Board T, Mask M, bool couleur_blanche)
{
    clear_mask(M);
    // CORRECTION : Mask tmp déclaré et initialisé avant utilisation
    Mask tmp;
    empty_mask(tmp);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Piece piece = get_square(i, j, T);
            // Pièce vide ou mauvaise couleur : on ne fait rien
            if (piece != vide)
            {
                bool est_blanche = (piece >= R && piece <= P);
                if (est_blanche == couleur_blanche)
                {
                    highlight_possible_moves(i, j, T, tmp);

                    bool peut_bouger = false;
                    for (int ii = 0; ii < 8 && !peut_bouger; ii++)
                        for (int jj = 0; jj < 8 && !peut_bouger; jj++)
                            if (tmp[ii][jj] != 0)
                                peut_bouger = true;

                    if (peut_bouger)
                        set_mask(i, j, M, 1);
                }
            }
        }
    }
}

// -----------------------------------------------------------------------
// Met en évidence les pièces adverses pouvant être prises au prochain coup
// -----------------------------------------------------------------------
void highlight_attacked_pieces(Board T, Mask M, bool couleur_blanche)
{
    clear_mask(M);

    // Marque d'abord toutes les pièces adverses avec val=3 (non attaquées)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            Piece piece = get_square(i, j, T);
            if (piece != vide)
            {
                bool est_blanche = (piece >= R && piece <= P);
                if (est_blanche != couleur_blanche)
                    set_mask(i, j, M, 3);
            }
        }

    // Pour chaque pièce du joueur courant, marque ses prises possibles
    // CORRECTION : Mask tmp initialisé avant utilisation
    Mask tmp;
    empty_mask(tmp);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            Piece piece = get_square(i, j, T);
            if (piece != vide)
            {
                bool est_blanche = (piece >= R && piece <= P);
                if (est_blanche == couleur_blanche)
                {
                    highlight_possible_moves(i, j, T, tmp);

                    for (int ii = 0; ii < 8; ii++)
                        for (int jj = 0; jj < 8; jj++)
                            if (tmp[ii][jj] == 2)
                                set_mask(ii, jj, M, 2);
                }
            }
        }
}

// -----------------------------------------------------------------------
// Met en évidence les pièces adverses pouvant prendre la pièce en (i,j)
// -----------------------------------------------------------------------
void highlight_take_pieces(int i, int j, Board T, Mask M)
{
    clear_mask(M);

    Piece cible = get_square(i, j, T);
    if (cible == vide)
        return;

    bool cible_est_blanche = (cible >= R && cible <= P);

    // CORRECTION : Mask tmp initialisé avant utilisation
    Mask tmp;
    empty_mask(tmp);

    for (int ii = 0; ii < 8; ii++)
        for (int jj = 0; jj < 8; jj++)
        {
            Piece piece = get_square(ii, jj, T);
            if (piece != vide)
            {
                bool est_blanche = (piece >= R && piece <= P);
                if (est_blanche != cible_est_blanche)
                {
                    highlight_possible_moves(ii, jj, T, tmp);

                    if (tmp[i][j] == 2)
                        set_mask(ii, jj, M, 2);
                }
            }
        }
}