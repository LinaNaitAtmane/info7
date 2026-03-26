#ifndef BOARD_HPP_
#define BOARD_HPP_
#include "types.hpp"
#include <string>

// Initialiser un plateau vide
void empty(Board T);

// Placer les pièces dans leur position initiale
void start(Board T);

// Récupérer le contenu d'une case
Piece get_square(int i, int j, Board T);

// Modifier le contenu d'une case
void set_square(int i, int j, Board T, Piece p);
// Déplacer une pièce de (i1,j1) vers (i2,j2)
void move_piece(int i1, int j1, int i2, int j2, Board T);
#endif