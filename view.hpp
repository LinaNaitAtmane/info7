#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "types.hpp"
#include <string>

void print_square(Piece p);

void print_board(Board T);

void write_FEN(Board T, const std::string &filename);

void read_FEN(Board T, const std::string &filename);

#endif // VIEW_HPP_