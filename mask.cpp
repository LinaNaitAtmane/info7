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
// Calcule les cases où le Roi en (i,j) peut se déplacer
// Le roi se déplace d'une seule case dans 8 directions
// T : plateau, M : masque, i/j : position du roi
void highlight_possible_moves_king(int i, int j, Board T, Mask M)
{
    /* Les 8 directions possibles pour le roi :
       horizontal, vertical et diagonales */
    int directions[8][2] = {
        {1, 0},  /* bas        */
        {-1, 0}, /* haut       */
        {0, 1},  /* droite     */
        {0, -1}, /* gauche     */
        {1, 1},  /* bas-droite */
        {1, -1}, /* bas-gauche */
        {-1, 1}, /* haut-droite*/
        {-1, -1} /* haut-gauche*/
    };

    /* Récupère la pièce du roi à la position (i, j) */
    Piece roi = get_square(i, j, T);

    /* Détermine si le roi est blanc (K majuscule) ou noir */
    bool est_blanc;
    if (roi == K)
        est_blanc = true;
    else
        est_blanc = false;

    /* Parcourt chaque direction possible du roi */
    for (int d = 0; d < 8; d++)
    {
        /* Calcule la case cible dans la direction d */
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        /* Vérifie que la case cible est bien dans les limites de l'échiquier (0 à 7) */
        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8)
        {
            /* Récupère la pièce présente sur la case cible */
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                /* La case est vide : le roi peut s'y déplacer librement */
                set_mask(ni, nj, M, 1);
            }
            else if (est_blanc && cible >= r && cible <= p)
            {
                /* Le roi est blanc et la case contient une pièce noire :
                   le roi peut capturer cette pièce */
                set_mask(ni, nj, M, 2);
            }
            else if (!est_blanc && cible >= R && cible <= P)
            {
                /* Le roi est noir et la case contient une pièce blanche :
                   le roi peut capturer cette pièce */
                set_mask(ni, nj, M, 2);
            }
            /* Si la case contient une pièce de même couleur, on ne fait rien */
        }
    }
}
void highlight_possible_moves(int i, int j, Board T, Mask M)
{
    /* On remet le masque à zéro avant de calculer les nouveaux mouvements */
    clear_mask(M);

    /* On récupère la pièce présente sur la case (i, j) */
    Piece piece = get_square(i, j, T);

    /* On appelle la fonction correspondante selon le type de pièce */
    switch (piece)
    {
    case K: /* Roi blanc */
        highlight_possible_moves_king(i, j, T, M);
        break;
    case k: /* Roi noir */
        highlight_possible_moves_king(i, j, T, M);
        break;
    case R: /* Tour blanche */
        highlight_possible_moves_rook(i, j, T, M);
        break;
    case r: /* Tour noire */
        highlight_possible_moves_rook(i, j, T, M);
        break;
    case B: /* Fou blanc */
        highlight_possible_moves_bishop(i, j, T, M);
        break;
    case b: /* Fou noir */
        highlight_possible_moves_bishop(i, j, T, M);
        break;
    case Q: /* Reine blanche */
        highlight_possible_moves_queen(i, j, T, M);
        break;
    case q: /* Reine noire */
        highlight_possible_moves_queen(i, j, T, M);
        break;
    case N: /* Cavalier blanc */
        highlight_possible_moves_knight(i, j, T, M);
        break;
    case n: /* Cavalier noir */
        highlight_possible_moves_knight(i, j, T, M);
        break;
    case P: /* Pion blanc */
        highlight_possible_moves_pawn(i, j, T, M);
        break;
    case p: /* Pion noir */
        highlight_possible_moves_pawn(i, j, T, M);
        break;
    default:
        /* Case vide ou pièce inconnue : rien à faire */
        break;
    }
}

/* -----------------------------------------------------------------------
   Tour : se déplace en ligne droite (horizontale ou verticale)
   sur autant de cases qu'elle veut jusqu'à rencontrer un obstacle
   ----------------------------------------------------------------------- */
void highlight_possible_moves_rook(int i, int j, Board T, Mask M)
{
    /* Les 4 directions de la tour */
    int directions[4][2] = {
        {1, 0},  /* bas    */
        {-1, 0}, /* haut   */
        {0, 1},  /* droite */
        {0, -1}  /* gauche */
    };

    /* Récupère la pièce tour et détermine sa couleur */
    Piece tour = get_square(i, j, T);
    bool est_blanc;
    if (tour == R)
        est_blanc = true;
    else
        est_blanc = false;

    /* Parcourt chacune des 4 directions */
    for (int d = 0; d < 4; d++)
    {
        /* Première case dans la direction d */
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        /* On avance case par case tant qu'on est dans le plateau */
        while ((ni >= 0) && (ni < 8) && (nj >= 0) && (nj < 8))
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                /* Case libre : on peut s'y déplacer, on continue dans cette direction */
                set_mask(ni, nj, M, 1); /* bleu = case libre */
                ni += directions[d][0];
                nj += directions[d][1];
            }
            else
            {
                /* Case occupée : prise possible si pièce adverse, sinon bloqué */
                if ((est_blanc) && (cible >= r) && (cible <= p))
                    set_mask(ni, nj, M, 2); /* rouge = prise d'une pièce noire */
                else if ((!est_blanc) && (cible >= R) && (cible <= P))
                    set_mask(ni, nj, M, 2); /* rouge = prise d'une pièce blanche */

                /* Dans tous les cas on s'arrête : pièce alliée ou adverse bloque la route */
                break;
            }
        }
    }
}

/* -----------------------------------------------------------------------
   Fou : se déplace en diagonale sur autant de cases qu'il veut
   jusqu'à rencontrer un obstacle
   ----------------------------------------------------------------------- */
void highlight_possible_moves_bishop(int i, int j, Board T, Mask M)
{
    /* Récupère la pièce fou et détermine sa couleur */
    Piece fou = get_square(i, j, T);
    bool est_blanc;
    if (fou == B)
        est_blanc = true;
    else
        est_blanc = false;

    /* Les 4 directions diagonales */
    int directions[4][2] = {
        {1, 1},  /* bas-droite  */
        {1, -1}, /* bas-gauche  */
        {-1, 1}, /* haut-droite */
        {-1, -1} /* haut-gauche */
    };

    /* Parcourt chacune des 4 diagonales */
    for (int d = 0; d < 4; d++)
    {
        /* Première case dans la diagonale d */
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        /* On avance case par case tant qu'on est dans le plateau */
        while ((ni >= 0) && (ni < 8) && (nj >= 0) && (nj < 8))
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                /* Case libre : on peut s'y déplacer, on continue la diagonale */
                set_mask(ni, nj, M, 1); /* bleu = case libre */
                ni += directions[d][0];
                nj += directions[d][1];
            }
            else
            {
                /* Case occupée : prise possible si pièce adverse, sinon bloqué */
                if ((est_blanc) && (cible >= r) && (cible <= p))
                    set_mask(ni, nj, M, 2); /* rouge = prise d'une pièce noire */
                else if ((!est_blanc) && (cible >= R) && (cible <= P))
                    set_mask(ni, nj, M, 2); /* rouge = prise d'une pièce blanche */

                /* Dans tous les cas on s'arrête dans cette diagonale */
                break;
            }
        }
    }
}

/* -----------------------------------------------------------------------
   Reine : combine les mouvements de la tour (lignes droites)
   et du fou (diagonales)
   ----------------------------------------------------------------------- */
void highlight_possible_moves_queen(int i, int j, Board T, Mask M)
{
    /* La reine peut se déplacer comme une tour (4 directions droites) */
    highlight_possible_moves_rook(i, j, T, M);

    /* Et aussi comme un fou (4 directions diagonales) */
    highlight_possible_moves_bishop(i, j, T, M);
}

/* -----------------------------------------------------------------------
   Cavalier : se déplace en L (2 cases + 1 case perpendiculaire)
   C'est la seule pièce qui peut sauter par-dessus les autres
   ----------------------------------------------------------------------- */
void highlight_possible_moves_knight(int i, int j, Board T, Mask M)
{
    /* Récupère la pièce cavalier et détermine sa couleur */
    Piece cavalier = get_square(i, j, T);
    bool est_blanc;
    if (cavalier == N)
        est_blanc = true;
    else
        est_blanc = false;

    /* Les 8 déplacements en L du cavalier */
    int moves[8][2] = {
        {2, 1},   /* bas-bas-droite   */
        {2, -1},  /* bas-bas-gauche   */
        {-2, 1},  /* haut-haut-droite */
        {-2, -1}, /* haut-haut-gauche */
        {1, 2},   /* bas-droite-droite  */
        {1, -2},  /* bas-gauche-gauche  */
        {-1, 2},  /* haut-droite-droite */
        {-1, -2}  /* haut-gauche-gauche */
    };

    /* Vérifie chacun des 8 sauts possibles */
    for (int d = 0; d < 8; d++)
    {
        int ni = i + moves[d][0];
        int nj = j + moves[d][1];

        /* On vérifie que la case d'arrivée est bien dans le plateau */
        if ((ni >= 0) && (ni < 8) && (nj >= 0) && (nj < 8))
        {
            Piece cible = get_square(ni, nj, T);

            if (cible == vide)
            {
                /* Case libre : le cavalier peut s'y poser */
                set_mask(ni, nj, M, 1); /* bleu = case libre */
            }
            else if ((est_blanc) && (cible >= r) && (cible <= p))
            {
                /* Pièce noire adverse : le cavalier peut la capturer */
                set_mask(ni, nj, M, 2); /* rouge = prise */
            }
            else if ((!est_blanc) && (cible >= R) && (cible <= P))
            {
                /* Pièce blanche adverse : le cavalier peut la capturer */
                set_mask(ni, nj, M, 2); /* rouge = prise */
            }
            /* Si la case contient une pièce alliée, on ne fait rien */
        }
    }
}

/* -----------------------------------------------------------------------
   Pion : avance tout droit (1 ou 2 cases au départ), prend en diagonale
   Blanc monte (direction +1), Noir descend (direction -1)
   ----------------------------------------------------------------------- */
void highlight_possible_moves_pawn(int i, int j, Board T, Mask M)
{
    /* Récupère la pièce pion et détermine sa couleur */
    Piece pion = get_square(i, j, T);
    bool est_blanc;
    if (pion == P)
        est_blanc = true;
    else
        est_blanc = false;

    /* Direction de déplacement : blanc monte (+1), noir descend (-1) */
    int dir;
    if (est_blanc == true)
        dir = 1;
    else
        dir = -1;

    /* Ligne de départ où le pion peut avancer de 2 cases */
    int ligne_depart;
    if (est_blanc == true)
        ligne_depart = 1; /* ligne 1 pour les blancs */
    else
        ligne_depart = 6; /* ligne 6 pour les noirs */

    /* --- 1. Avancer d'une case tout droit --- */
    int ni = i + dir;

    /* On vérifie que la case devant est dans le plateau et qu'elle est vide */
    if ((ni >= 0) && (ni < 8) && (get_square(ni, j, T) == vide))
    {
        set_mask(ni, j, M, 1); /* bleu = peut avancer d'une case */

        /* --- 2. Avancer de deux cases depuis la ligne de départ --- */
        /* Possible uniquement si le pion n'a pas encore bougé
           et que la case deux pas devant est aussi vide */
        if ((i == ligne_depart) && (get_square(i + 2 * dir, j, T) == vide))
            set_mask(i + 2 * dir, j, M, 1); /* bleu = peut avancer de deux cases */
    }

    /* --- 3. Prise en diagonale gauche --- */
    int pi = i + dir;      /* ligne d'arrivée */
    int pj_gauche = j - 1; /* colonne gauche   */

    /* On vérifie que la case diagonale gauche est dans le plateau */
    if ((pi >= 0) && (pi < 8) && (pj_gauche >= 0) && (pj_gauche < 8))
    {
        Piece cible_gauche = get_square(pi, pj_gauche, T);

        if ((est_blanc == true) && (cible_gauche >= r) && (cible_gauche <= p))
            set_mask(pi, pj_gauche, M, 2); /* rouge = prise d'une pièce noire */
        else if ((!est_blanc) && (cible_gauche >= R) && (cible_gauche <= P))
            set_mask(pi, pj_gauche, M, 2); /* rouge = prise d'une pièce blanche */
    }

    /* --- 4. Prise en diagonale droite --- */
    int pj_droite = j + 1; /* colonne droite */

    /* On vérifie que la case diagonale droite est dans le plateau */
    if ((pi >= 0) && (pi < 8) && (pj_droite >= 0) && (pj_droite < 8))
    {
        Piece cible_droite = get_square(pi, pj_droite, T);

        if ((est_blanc == true) && (cible_droite >= r) && (cible_droite <= p))
            set_mask(pi, pj_droite, M, 2); /* rouge = prise d'une pièce noire */
        else if ((!est_blanc) && (cible_droite >= R) && (cible_droite <= P))
            set_mask(pi, pj_droite, M, 2); /* rouge = prise d'une pièce blanche */
    }
}
/////////////////
/ Met en évidence(val = 1) toutes les pièces du joueur(couleur_blanche)
qui peuvent se déplacer
    // Une pièce "peut se déplacer" si son masque de déplacements contient au moins une case possible
    void highlight_movable_pieces(Board T, Mask M, bool couleur_blanche)
{
    clear_mask(M);
    Mask tmp;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Piece p = get_square(i, j, T);
            if (p == vide)
                continue;

            // Vérifie si la pièce appartient au joueur courant
            bool est_blanche = (p >= R && p <= P);
            if (est_blanche != couleur_blanche)
                continue;

            // Calcule les déplacements possibles dans un masque temporaire
            highlight_possible_moves(i, j, T, tmp);

            // Si au moins une case est accessible, on marque la pièce
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

// Met en évidence les pièces adverses pouvant être prises au prochain coup
// couleur_blanche=true : marque les pièces noires attaquables par les blancs
// val=2 (rouge) pour les pièces attaquables, val=1 (bleu) pour les non attaquables
void highlight_attacked_pieces(Board T, Mask M, bool couleur_blanche)
{
    clear_mask(M);

    // Marque d'abord toutes les pièces adverses en val=1 (non attaquées)
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            Piece p = get_square(i, j, T);
            if (p == vide)
                continue;
            bool est_blanche = (p >= R && p <= P);
            // Pièce adverse : couleur opposée au joueur courant
            if (est_blanche == couleur_blanche)
                continue;
            set_mask(i, j, M, 3);
        }

    // Pour chaque pièce du joueur courant, calcule ses prises possibles
    // et met à jour le masque en val=2 pour les pièces adverses attaquables
    Mask tmp;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            Piece p = get_square(i, j, T);
            if (p == vide)
                continue;
            bool est_blanche = (p >= R && p <= P);
            if (est_blanche != couleur_blanche)
                continue;

            highlight_possible_moves(i, j, T, tmp);

            // Les cases marquées 2 dans tmp sont des prises → marque dans M
            for (int ii = 0; ii < 8; ii++)
                for (int jj = 0; jj < 8; jj++)
                    if (tmp[ii][jj] == 2)
                        set_mask(ii, jj, M, 2);
        }
}

// Met en évidence toutes les pièces adverses pouvant prendre la pièce en (i,j)
// val=2 : pièce pouvant prendre la cible
void highlight_take_pieces(int i, int j, Board T, Mask M)
{
    clear_mask(M);

    Piece cible = get_square(i, j, T);
    if (cible == vide)
        return;

    bool cible_est_blanche = (cible >= R && cible <= P);
    Mask tmp;

    // Parcourt toutes les pièces adverses
    for (int ii = 0; ii < 8; ii++)
        for (int jj = 0; jj < 8; jj++)
        {
            Piece p = get_square(ii, jj, T);
            if (p == vide)
                continue;
            bool est_blanche = (p >= R && p <= P);
            // On ne considère que les pièces de couleur opposée à la cible
            if (est_blanche == cible_est_blanche)
                continue;

            highlight_possible_moves(ii, jj, T, tmp);

            // Si cette pièce peut prendre la case (i,j), on la marque
            if (tmp[i][j] == 2)
                set_mask(ii, jj, M, 2);
        }
}