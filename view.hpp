#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "types.hpp"
#include <string>

void print_square(Piece p);

void print_board(Board T);

void write_FEN(Board T, const std::string &filename);

void read_FEN(Board T, const std::string &filename);

// Séance 3 : affichage couleur
void set_background(bool is_black);
void set_foreground(Piece piece);
void print_square_color(int i, int j, Piece T[8][8]);
void print_board_color(Board T);
void print_square_color(int i, int j, Piece T[8][8], Mask M);
void print_board_color(Board T, Mask M);


#endif // VIEW_HPP_