#include "view.hpp"
#include "types.hpp"
#include "board.hpp"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

// =============================================================================
// view.cpp — Affichage du plateau et lecture/écriture au format FEN
// =============================================================================

// -----------------------------------------------------------------------------
// print_square : affiche le symbole textuel d'une pièce (mode sans couleur)
// -----------------------------------------------------------------------------
// Chaque pièce est représentée par sa lettre standard :
//   Majuscule = blanc, Minuscule = noir, "." = case vide
void print_square(Piece piece)
{
    switch (piece)
    {
    case r:
        cout << "r ";
        break;
    case n:
        cout << "n ";
        break;
    case b:
        cout << "b ";
        break;
    case q:
        cout << "q ";
        break;
    case k:
        cout << "k ";
        break;
    case p:
        cout << "p ";
        break;
    case R:
        cout << "R ";
        break;
    case N:
        cout << "N ";
        break;
    case B:
        cout << "B ";
        break;
    case Q:
        cout << "Q ";
        break;
    case K:
        cout << "K ";
        break;
    case P:
        cout << "P ";
        break;
    case vide:
        cout << ". ";
        break;
    }
}

// -----------------------------------------------------------------------------
// print_board : affiche le plateau entier en mode texte simple
// -----------------------------------------------------------------------------
// On affiche les lignes de 7 à 0 (du haut vers le bas) pour que
// le rang 8 (côté noir) soit en haut et le rang 1 (côté blanc) en bas.
void print_board(Board T)
{
    cout << "  a b c d e f g h" << endl;
    for (int i = 7; i >= 0; i--)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
            print_square(T[i][j]);
        cout << i + 1 << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

// -----------------------------------------------------------------------------
// write_FEN : sauvegarde le plateau dans un fichier au format FEN
// -----------------------------------------------------------------------------
// On parcourt les lignes de 7 à 0 (rang 8 vers rang 1).
// Pour chaque ligne, on compte les cases vides consécutives et on les
// écrit sous forme d'un chiffre (ex: 3 cases vides = "3").
// Les pièces sont écrites directement avec leur lettre.
// Les lignes sont séparées par "/".
void write_FEN(Board T, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Erreur : impossible d'ouvrir le fichier " << filename << endl;
        return;
    }

    for (int i = 7; i >= 0; i--)
    {
        int cases_vides = 0; // compteur de cases vides consécutives

        for (int j = 0; j < 8; j++)
        {
            Piece piece = T[i][j];

            if (piece == vide)
            {
                cases_vides++; // on accumule les cases vides
            }
            else
            {
                // Avant d'écrire une pièce, on écrit le nombre de vides accumulés
                if (cases_vides > 0)
                {
                    file << cases_vides;
                    cases_vides = 0;
                }
                // On écrit la lettre correspondant à la pièce
                switch (piece)
                {
                case r:
                    file << 'r';
                    break;
                case n:
                    file << 'n';
                    break;
                case b:
                    file << 'b';
                    break;
                case q:
                    file << 'q';
                    break;
                case k:
                    file << 'k';
                    break;
                case p:
                    file << 'p';
                    break;
                case R:
                    file << 'R';
                    break;
                case N:
                    file << 'N';
                    break;
                case B:
                    file << 'B';
                    break;
                case Q:
                    file << 'Q';
                    break;
                case K:
                    file << 'K';
                    break;
                case P:
                    file << 'P';
                    break;
                default:
                    break;
                }
            }
        }

        // S'il reste des cases vides en fin de ligne
        if (cases_vides > 0)
            file << cases_vides;

        // Séparateur entre les rangs (sauf après le dernier)
        if (i > 0)
            file << '/';
    }

    file << endl;
    file.close();
}

// -----------------------------------------------------------------------------
// read_FEN : lit un fichier FEN et remplit le plateau
// -----------------------------------------------------------------------------
// On lit la chaîne FEN caractère par caractère :
//   '/'      → on passe à la ligne suivante (rang suivant vers le bas)
//   '1'-'8'  → on saute ce nombre de cases vides
//   lettre   → on place la pièce correspondante sur la case courante
// On commence au rang 8 (i=7) et on descend vers le rang 1 (i=0).
void read_FEN(Board T, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erreur : impossible d'ouvrir le fichier " << filename << endl;
        return;
    }

    string fen;
    getline(file, fen);
    file.close();

    int i = 7; // on commence par le rang 8 (ligne 7 du tableau)
    int j = 0; // colonne courante

    for (char c : fen)
    {
        if (c == '/')
        {
            // Changement de rang : on descend d'une ligne
            i--;
            j = 0;
        }
        else if (c >= '1' && c <= '8')
        {
            // Chiffre = nombre de cases vides à sauter
            j += c - '0';
        }
        else
        {
            // Lettre = une pièce à placer sur la case (i, j)
            switch (c)
            {
            case 'r':
                T[i][j++] = r;
                break;
            case 'n':
                T[i][j++] = n;
                break;
            case 'b':
                T[i][j++] = b;
                break;
            case 'q':
                T[i][j++] = q;
                break;
            case 'k':
                T[i][j++] = k;
                break;
            case 'p':
                T[i][j++] = p;
                break;
            case 'R':
                T[i][j++] = R;
                break;
            case 'N':
                T[i][j++] = N;
                break;
            case 'B':
                T[i][j++] = B;
                break;
            case 'Q':
                T[i][j++] = Q;
                break;
            case 'K':
                T[i][j++] = K;
                break;
            case 'P':
                T[i][j++] = P;
                break;
            default:
                T[i][j++] = vide;
                break;
            }
        }
    }
}

// =============================================================================
// Fonctions d'affichage en couleur (codes ANSI pour le terminal)
// =============================================================================
// Les codes ANSI permettent de changer la couleur du texte et du fond
// dans le terminal. Syntaxe : \x1b[<code>m
//   48;5;N  → couleur de fond (numéro de couleur 256)
//   1;97m   → texte blanc vif
//   1;30m   → texte noir gras
//   0m      → remise à zéro (couleur normale)
// =============================================================================

// -----------------------------------------------------------------------------
// set_background : définit la couleur de fond d'une case du damier
// -----------------------------------------------------------------------------
// Les cases sombres sont marron foncé (couleur 94), les cases claires
// sont marron clair / beige (couleur 180). C'est le damier classique.
void set_background(bool is_dark_square)
{
    if (is_dark_square)
        cout << "\x1b[48;5;94m"; // marron foncé
    else
        cout << "\x1b[48;5;180m"; // marron clair / beige
}

// -----------------------------------------------------------------------------
// set_foreground : affiche le symbole Unicode d'une pièce avec sa couleur
// -----------------------------------------------------------------------------
// Le paramètre is_dark indique si la case est sombre ou claire.
// On adapte la couleur du texte en fonction du fond pour que la pièce
// soit toujours visible, quelle que soit la case sur laquelle elle se trouve.
//
// Règle :
//   Pièce BLANCHE sur case SOMBRE  → texte blanc vif   (contraste élevé ✓)
//   Pièce BLANCHE sur case CLAIRE  → texte blanc + contour sombre → on utilise
//                                     un blanc légèrement plus terne (couleur 231)
//                                     pour garder la lisibilité
//   Pièce NOIRE  sur case SOMBRE   → texte blanc cassé (la pièce noire sur fond
//                                     sombre serait invisible en noir pur)
//   Pièce NOIRE  sur case CLAIRE   → texte noir pur (contraste élevé ✓)
//
// Symboles Unicode utilisés (standard international) :
//   Blanches (creux) : ♔♕♖♗♘♙  (U+2654 à U+2659)
//   Noires  (pleins) : ♚♛♜♝♞♟  (U+265A à U+265F)
void set_foreground(Piece piece, bool is_dark)
{
    // Couleur du texte selon la couleur de la pièce et la couleur de la case :
    //   Pièce blanche sur case sombre → blanc vif      \x1b[1;97m
    //   Pièce blanche sur case claire → blanc terne    \x1b[38;5;231m
    //   Pièce noire  sur case sombre  → blanc cassé    \x1b[38;5;255m  (lisible)
    //   Pièce noire  sur case claire  → noir pur        \x1b[30m
    switch (piece)
    {
    // --- Pièces blanches ---
    case K:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x94";
        break; // ♔
    case Q:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x95";
        break; // ♕
    case R:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x96";
        break; // ♖
    case B:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x97";
        break; // ♗
    case N:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x98";
        break; // ♘
    case P:
        cout << (is_dark ? "\x1b[1;97m" : "\x1b[38;5;231m") << "\xe2\x99\x99";
        break; // ♙

    // --- Pièces noires ---
    case k:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9a";
        break; // ♚
    case q:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9b";
        break; // ♛
    case r:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9c";
        break; // ♜
    case b:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9d";
        break; // ♝
    case n:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9e";
        break; // ♞
    case p:
        cout << (is_dark ? "\x1b[38;5;255m" : "\x1b[30m") << "\xe2\x99\x9f";
        break; // ♟

    case vide:
        cout << " ";
        break;
    }
}

// -----------------------------------------------------------------------------
// print_square_color : affiche une case du plateau en couleur (sans masque)
// -----------------------------------------------------------------------------
// La couleur de fond dépend de la parité de (i+j) : damier classique.
// On transmet is_dark à set_foreground pour qu'elle adapte la couleur du texte.
void print_square_color(int i, int j, Piece T[8][8])
{
    bool is_dark = (i + j) % 2 == 0; // case sombre si (i+j) pair
    set_background(is_dark);
    cout << " ";
    set_foreground(T[i][j], is_dark);
    cout << " ";
    cout << "\x1b[0m";
}

// -----------------------------------------------------------------------------
// print_board_color : affiche tout le plateau en couleur (sans masque)
// -----------------------------------------------------------------------------
// On affiche de la ligne 7 (rang 8, côté noir) à la ligne 0 (rang 1, côté blanc).
void print_board_color(Board T)
{
    setlocale(LC_ALL, ""); // nécessaire pour afficher les symboles Unicode
    cout << "   a  b  c  d  e  f  g  h" << endl;
    for (int i = 7; i >= 0; i--)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
            print_square_color(i, j, T);
        cout << " " << i + 1 << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
}

// -----------------------------------------------------------------------------
// print_square_color (avec masque) : affiche une case en tenant compte du masque
// -----------------------------------------------------------------------------
// Le masque remplace la couleur normale du fond par une couleur de signal :
//   val = 0 → couleur normale du damier (marron clair/foncé)
//   val = 1 → bleu        (case accessible pour un déplacement)
//   val = 2 → rouge       (pièce adverse attaquable / prise possible)
//   val = 3 → vert        (pièce adverse protégée, non prenable directement)
void print_square_color(int i, int j, Piece T[8][8], Mask M)
{
    int val = M[i][j];
    bool is_dark;

    if (val == 0)
    {
        // Couleur normale du damier
        is_dark = (i + j) % 2 == 0;
        set_background(is_dark);
    }
    else
    {
        // Les fonds colorés (bleu, rouge, vert...) sont tous sombres :
        // on traite le texte comme sur une case sombre pour la lisibilité
        is_dark = true;
        if (val == 1)
            cout << "\x1b[48;5;20m"; // bleu foncé
        else if (val == 2)
            cout << "\x1b[48;5;196m"; // rouge vif
        else if (val == 3)
            cout << "\x1b[48;5;28m"; // vert foncé
        else if (val == 4)
            cout << "\x1b[48;5;130m"; // orange (réservé)
        else if (val == 5)
            cout << "\x1b[48;5;91m"; // violet (réservé)
        else if (val == 6)
            cout << "\x1b[48;5;30m"; // cyan (réservé)
        else if (val == 7)
            cout << "\x1b[48;5;244m"; // gris (réservé)
    }

    cout << " ";
    set_foreground(T[i][j], is_dark); // on adapte la couleur du texte selon le fond
    cout << " ";
    cout << "\x1b[0m";
}

// -----------------------------------------------------------------------------
// print_board_color (avec masque) : affiche le plateau entier avec le masque
// -----------------------------------------------------------------------------
void print_board_color(Board T, Mask M)
{
    setlocale(LC_ALL, "");
    cout << "   a  b  c  d  e  f  g  h" << endl;
    for (int i = 7; i >= 0; i--)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
            print_square_color(i, j, T, M);
        cout << " " << i + 1 << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
}