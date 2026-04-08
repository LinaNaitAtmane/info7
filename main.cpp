#include <iostream>
#include <string>
using namespace std;

#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"

// -----------------------------------------------------------------------
// Affiche le nom d'une pièce lisiblement
// -----------------------------------------------------------------------
string nom_piece(Piece piece)
{
    switch (piece)
    {
    case K:
        return "Roi blanc";
    case Q:
        return "Reine blanche";
    case R:
        return "Tour blanche";
    case B:
        return "Fou blanc";
    case N:
        return "Cavalier blanc";
    case P:
        return "Pion blanc";
    case k:
        return "Roi noir";
    case q:
        return "Reine noire";
    case r:
        return "Tour noire";
    case b:
        return "Fou noir";
    case n:
        return "Cavalier noir";
    case p:
        return "Pion noir";
    default:
        return "Vide";
    }
}

// Convertit les indices (i, j) en notation échecs (ex: "e4")
string case_nom(int i, int j)
{
    string s = "";
    s += (char)('a' + j);
    s += (char)('1' + i);
    return s;
}

// -----------------------------------------------------------------------
// Affiche les pièces déplaçables d'un joueur
// -----------------------------------------------------------------------
void afficher_pieces_deplacables(Board T, bool blanc)
{
    Mask M;
    empty_mask(M);
    highlight_movable_pieces(T, M, blanc);

    cout << "\n>>> Pieces " << (blanc ? "blanches" : "noires") << " pouvant se deplacer (fond bleu) :" << endl;
    bool aucune = true;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (M[i][j] == 1)
            {
                cout << "  - " << nom_piece(get_square(i, j, T))
                     << " en " << case_nom(i, j) << endl;
                aucune = false;
            }
    if (aucune)
        cout << "  Aucune." << endl;

    print_board_color(T, M);
}

// -----------------------------------------------------------------------
// Affiche les pièces adverses attaquées (rouge) et non attaquées (vert)
// -----------------------------------------------------------------------
void afficher_pieces_attaquees(Board T, bool blanc)
{
    Mask M;
    empty_mask(M);
    highlight_attacked_pieces(T, M, blanc);

    cout << "\n>>> Pieces " << (blanc ? "noires" : "blanches")
         << " vues par les " << (blanc ? "blancs" : "noirs") << " :" << endl;
    cout << "  ROUGE = attaquable | VERT = protegee" << endl;

    bool rouge = false, vert = false;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (M[i][j] == 2)
            {
                cout << "  [ROUGE] " << nom_piece(get_square(i, j, T))
                     << " en " << case_nom(i, j) << " peut etre prise !" << endl;
                rouge = true;
            }
            else if (M[i][j] == 3)
            {
                cout << "  [VERT]  " << nom_piece(get_square(i, j, T))
                     << " en " << case_nom(i, j) << " est protegee." << endl;
                vert = true;
            }
        }
    if (!rouge && !vert)
        cout << "  Aucune piece adverse." << endl;

    print_board_color(T, M);
}

// -----------------------------------------------------------------------
// Affiche quelles pièces adverses peuvent prendre la pièce en (i, j)
// -----------------------------------------------------------------------
void afficher_qui_peut_prendre(Board T, int i, int j)
{
    Piece cible = get_square(i, j, T);
    if (cible == vide)
    {
        cout << "\n>>> Case " << case_nom(i, j) << " est vide." << endl;
        return;
    }

    Mask M;
    empty_mask(M);
    highlight_take_pieces(i, j, T, M);

    cout << "\n>>> Qui peut prendre " << nom_piece(cible)
         << " en " << case_nom(i, j) << " ?" << endl;

    bool aucune = true;
    for (int ii = 0; ii < 8; ii++)
        for (int jj = 0; jj < 8; jj++)
            if (M[ii][jj] == 2)
            {
                cout << "  -> " << nom_piece(get_square(ii, jj, T))
                     << " en " << case_nom(ii, jj) << endl;
                aucune = false;
            }
    if (aucune)
        cout << "  Aucune piece adverse ne peut la prendre." << endl;

    print_board_color(T, M);
}

// -----------------------------------------------------------------------
// Affiche les mouvements possibles d'une pièce en (i, j)
// -----------------------------------------------------------------------
void afficher_mouvements(Board T, int i, int j)
{
    Piece p = get_square(i, j, T);
    if (p == vide)
    {
        cout << "\n>>> Case " << case_nom(i, j) << " est vide." << endl;
        return;
    }

    Mask M;
    empty_mask(M);
    highlight_possible_moves(i, j, T, M);

    cout << "\n>>> Mouvements possibles de " << nom_piece(p)
         << " en " << case_nom(i, j) << " :" << endl;

    bool aucun = true;
    for (int ii = 0; ii < 8; ii++)
        for (int jj = 0; jj < 8; jj++)
        {
            if (M[ii][jj] == 1)
            {
                cout << "  -> " << case_nom(ii, jj) << " (libre)" << endl;
                aucun = false;
            }
            else if (M[ii][jj] == 2)
            {
                cout << "  -> " << case_nom(ii, jj)
                     << " (prise de " << nom_piece(get_square(ii, jj, T)) << ")" << endl;
                aucun = false;
            }
        }
    if (aucun)
        cout << "  Aucun mouvement possible." << endl;

    print_board_color(T, M);
}

// -----------------------------------------------------------------------
// Menu interactif
// -----------------------------------------------------------------------
void afficher_menu()
{
    cout << "\n============================================" << endl;
    cout << "  MENU PRINCIPAL" << endl;
    cout << "============================================" << endl;
    cout << "  1. Pieces blanches deplacables" << endl;
    cout << "  2. Pieces noires deplacables" << endl;
    cout << "  3. Pieces noires attaquees par les blancs" << endl;
    cout << "  4. Pieces blanches attaquees par les noirs" << endl;
    cout << "  5. Mouvements d'une piece specifique" << endl;
    cout << "  6. Qui peut prendre une piece ?" << endl;
    cout << "  7. Afficher le plateau" << endl;
    cout << "  0. Quitter" << endl;
    cout << "Votre choix : ";
}

// -----------------------------------------------------------------------
// Main interactif
// -----------------------------------------------------------------------
int main()
{
    Board T;
    start(T);

    cout << "\n=== BIENVENUE DANS LE JEU D'ECHECS ===" << endl;
    cout << "Plateau de depart :" << endl;
    print_board_color(T);

    int choix = -1;
    while (choix != 0)
    {
        afficher_menu();
        cin >> choix;

        if (choix == 1)
        {
            afficher_pieces_deplacables(T, true);
        }
        else if (choix == 2)
        {
            afficher_pieces_deplacables(T, false);
        }
        else if (choix == 3)
        {
            afficher_pieces_attaquees(T, true);
        }
        else if (choix == 4)
        {
            afficher_pieces_attaquees(T, false);
        }
        else if (choix == 5)
        {
            cout << "Entrez la colonne (a-h) et la ligne (1-8) (ex: e2) : ";
            char col;
            int ligne;
            cin >> col >> ligne;
            int j = col - 'a';
            int i = ligne - 1;
            afficher_mouvements(T, i, j);
        }
        else if (choix == 6)
        {
            cout << "Entrez la colonne (a-h) et la ligne (1-8) de la piece cible (ex: e4) : ";
            char col;
            int ligne;
            cin >> col >> ligne;
            int j = col - 'a';
            int i = ligne - 1;
            afficher_qui_peut_prendre(T, i, j);
        }
        else if (choix == 7)
        {
            cout << "\nPlateau actuel :" << endl;
            print_board_color(T);
        }
        else if (choix != 0)
        {
            cout << "Choix invalide, recommencez." << endl;
        }
    }

    cout << "\nAu revoir !" << endl;
    return 0;
}