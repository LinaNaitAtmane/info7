#include "view.hpp"
#include "types.hpp"
#include "board.hpp"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

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

void write_FEN(Board T, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Erreur";
        return;
    }
    for (int i = 7; i >= 0; i--)
    {
        int count = 0;
        for (int j = 0; j < 8; j++)
        {
            Piece piece = T[i][j];
            if (piece == vide)
                count++;
            else
            {
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
        if (count > 0)
            file << count;
        if (i > 0)
            file << '/';
    }
    file << endl;
    file.close();
}

void read_FEN(Board T, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Erreur";
        return;
    }
    string fen;
    getline(file, fen);
    file.close();

    int i = 7, j = 0;
    for (char c : fen)
    {
        if (c == '/')
        {
            i--;
            j = 0;
        }
        else if (c >= '1' && c <= '8')
        {
            j += c - '0';
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

// -----------------------------------------------------------------------
// Fond marron fonce (94) ou marron clair (180)
// -----------------------------------------------------------------------
void set_background(bool is_dark_square)
{
    if (is_dark_square)
        cout << "\x1b[48;5;172m";  // orange foncé
    else
        cout << "\x1b[48;5;180m";  // orange clair
}

void set_foreground(Piece piece)
{
    switch (piece)
    {
    // Pièces BLANCHES → texte blanc, symboles pleins
    case K: cout << "\x1b[1;97m" << "\xe2\x99\x9a"; break; // ♚
    case Q: cout << "\x1b[1;97m" << "\xe2\x99\x9b"; break; // ♛
    case R: cout << "\x1b[1;97m" << "\xe2\x99\x9c"; break; // ♜
    case B: cout << "\x1b[1;97m" << "\xe2\x99\x9d"; break; // ♝
    case N: cout << "\x1b[1;97m" << "\xe2\x99\x9e"; break; // ♞
    case P: cout << "\x1b[1;97m" << "\xe2\x99\x9f"; break; // ♟

    // Pièces NOIRES → texte noir, symboles pleins
    case k: cout << "\x1b[30m" << "\xe2\x99\x9a"; break;   // ♚
    case q: cout << "\x1b[30m" << "\xe2\x99\x9b"; break;   // ♛
    case r: cout << "\x1b[30m" << "\xe2\x99\x9c"; break;   // ♜
    case b: cout << "\x1b[30m" << "\xe2\x99\x9d"; break;   // ♝
    case n: cout << "\x1b[30m" << "\xe2\x99\x9e"; break;   // ♞
    case p: cout << "\x1b[30m" << "\xe2\x99\x9f"; break;   // ♟

    case vide: cout << " "; break;
    }
}

void print_square_color(int i, int j, Piece T[8][8])
{
    // a1 = case NOIRE : (i+j) pair → sombre
    bool is_dark = (i + j) % 2 == 0;
    set_background(is_dark);
    cout << " ";
    set_foreground(T[i][j]);
    cout << " ";
    cout << "\x1b[0m";
}

void print_board_color(Board T)
{
    setlocale(LC_ALL, "");
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

void print_square_color(int i, int j, Piece T[8][8], Mask M)
{
    int val = M[i][j];
    if (val == 0) {
        bool is_dark = (i + j) % 2 == 0;
        set_background(is_dark);
    }
    else if (val == 1) cout << "\x1b[48;5;20m";
    else if (val == 2) cout << "\x1b[48;5;196m";
    else if (val == 3) cout << "\x1b[48;5;28m";

    cout << " ";
    set_foreground(T[i][j]);
    cout << " ";
    cout << "\x1b[0m";
}

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