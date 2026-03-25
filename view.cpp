#include "view.hpp"
#include "types.hpp"
#include "board.hpp" 
#include <iostream>
#include <fstream>
using namespace std;
// D´efinir la fonction print square qui affiche une case.
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

// D´efinir la fonction print board
void print_board(Board T)
{
    // lettres en haut
    cout << "  a b c d e f g h" << endl;

    for (int i = 7; i >= 0; i--)
    {
        // numero a gauche
        cout << i + 1 << " ";

        for (int j = 0; j < 8; j++)
        {
            print_square(T[i][j]);
        }

        // numero a droite
        cout << i + 1;

        cout << endl;
    }

    // lettres en bas
    cout << "  a b c d e f g h" << endl;
}
void write_FEN(Board T, string &filename)
{
    ofstream file(filename);
    // Verifier que le fichier est bien ouvert
    if (!file.is_open())
    {
        cout << "Erreur";
        return;
    }
    // On parcourt le plateau de la  rangee 8 a la 1
    for (int i = 7; i >= 0; i--)
    {
        // count compte le nombre de cases vides consécutives sur une rangée
        int count = 0;
        // Parcourt les colonnes de gauche a droite pour chaque rangee
        for (int j = 0; j < 8; j++)
        {
            Piece piece = T[i][j];
            if (piece == vide)
                count++;
            else
            { // on écrit le nombre de cases vides précédentes puis on reinitialise a 0
                if (count > 0)
                {
                    file << count;
                    count = 0;
                }
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
        // a  la fin de la rangee, si des cases vides étaient en fin de rangée, on écrit ce nombre
        if (count > 0)
            file << count;
        if (i > 0)
            file << '/';
    }
    file << endl;
    file.close();
}

void read_FEN(Board T, string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erreur";
        return;
    }
    // on a declare fen pour stocker la ligne FEN dans le fichier
    string fen;
    // on lit une ligne depuis le fichier
    getline(file, fen);
    file.close();

    int i = 7, j = 0;
    // c'est une boucle sur chaque caractere c de la chaine fen
    for (char c : fen)
    {
        if (c == '/') // Quand on rencontre /, on descend d’une ligne (i--) et on repart à la première colonne (j = 0).
        {
            i--;
            j = 0;
        }
        else if ((c >= '1') && (c <= '8')) // si c  est un chiffre on saute le nombre de cases
        {
            j += c - '0'; // il convertit un caractere en un entier
        }
        else
        {
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
void set_background(bool is_black)
{
    if (is_black)
        cout << "\x1b[48;5;238m"; // fond gris foncé pour case noire
    else
        cout << "\x1b[48;5;250m"; // fond gris clair pour case blanche
}
void set_foreground(Piece piece)
{
    switch (piece)
    {
    case r:
        cout << "\x1b[30m\u265C";
        break; // tour noire
    case n:
        cout << "\x1b[30m\u265E";
        break; // cavalier noir
    case b:
        cout << "\x1b[30m\u265D";
        break; // fou noir
    case q:
        cout << "\x1b[30m\u265B";
        break; // reine noire
    case k:
        cout << "\x1b[30m\u265A";
        break; // roi noir
    case p:
        cout << "\x1b[30m\u265F";
        break; // pion noir

    case R:
        cout << "\x1b[37m\u2656";
        break; // tour blanche
    case N:
        cout << "\x1b[37m\u2658";
        break; // cavalier blanc
    case B:
        cout << "\x1b[37m\u2657";
        break; // fou blanc
    case Q:
        cout << "\x1b[37m\u2655";
        break; // reine blanche
    case K:
        cout << "\x1b[37m\u2654";
        break; // roi blanc
    case P:
        cout << "\x1b[37m\u2659";
        break; // pion blanc

    case vide:
        cout << " ";
        break; // case vide
    }
}
void print_square_color(int i, int j, Piece T[8][8])
{
    bool is_black_square = (i + j) % 2 == 0; // case noire si somme des indices pair
    set_background(is_black_square);
    set_foreground(T[i][j]);
    cout << " ";       // espace pour bien encadrer la pièce
    cout << "\x1b[0m"; // reset couleurs après la case
}