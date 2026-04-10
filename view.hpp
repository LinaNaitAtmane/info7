#ifndef VIEW_HPP_
#define VIEW_HPP_

// =============================================================================
// view.hpp — Déclarations des fonctions d'affichage et de lecture/écriture FEN
// =============================================================================
//
// Ce fichier déclare toutes les fonctions qui permettent :
//   1. D'afficher le plateau en mode texte simple (print_board)
//   2. D'afficher le plateau en couleur dans le terminal (print_board_color)
//   3. De lire/écrire un plateau au format FEN (notation standard des échecs)
//
// Le format FEN (Forsyth–Edwards Notation) est une façon standard de décrire
// une position sur l'échiquier sous forme d'une seule ligne de texte.
// Exemple : "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
//           représente la position de départ.
// =============================================================================

#include "types.hpp"
#include <string>

// Affiche le symbole d'une pièce en mode texte simple (sans couleur)
void print_square(Piece p);

// Affiche tout le plateau en mode texte simple avec les coordonnées (a-h, 1-8)
void print_board(Board T);

// Écrit le plateau dans un fichier au format FEN
void write_FEN(Board T, const std::string &filename);

// Lit un fichier FEN et remplit le plateau T avec la position décrite
void read_FEN(Board T, const std::string &filename);

// --- Fonctions d'affichage en couleur (terminal ANSI) ---

// Définit la couleur de fond d'une case (marron foncé ou marron clair selon la position)
void set_background(bool is_dark_square);

// Affiche le symbole Unicode d'une pièce avec sa couleur adaptée au fond
// is_dark = true si la case est sombre, false si elle est claire
void set_foreground(Piece piece, bool is_dark);

// Affiche une seule case (i, j) avec sa couleur de fond normale
void print_square_color(int i, int j, Piece T[8][8]);

// Affiche tout le plateau en couleur (sans masque)
void print_board_color(Board T);

// Affiche une seule case (i, j) en tenant compte du masque M
// (le masque peut colorer certaines cases en bleu, rouge ou vert)
void print_square_color(int i, int j, Piece T[8][8], Mask M);

// Affiche tout le plateau en couleur avec le masque M appliqué
void print_board_color(Board T, Mask M);

#endif // VIEW_HPP_