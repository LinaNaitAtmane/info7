#ifndef MASK_HPP
#define MASK_HPP

#include "types.hpp"
#include "board.hpp"

// -----------------------------------------------------------------------
// Opérations de base sur le masque
// -----------------------------------------------------------------------
void empty_mask(Mask M);
void clear_mask(Mask M);
int get_mask(int i, int j, Mask M);
void set_mask(int i, int j, Mask M, int val);

// -----------------------------------------------------------------------
// Déplacements possibles par pièce
// -----------------------------------------------------------------------
void highlight_possible_moves_king(int i, int j, Board T, Mask M);
void highlight_possible_moves_rook(int i, int j, Board T, Mask M);
void highlight_possible_moves_bishop(int i, int j, Board T, Mask M);
void highlight_possible_moves_queen(int i, int j, Board T, Mask M);
void highlight_possible_moves_knight(int i, int j, Board T, Mask M);
void highlight_possible_moves_pawn(int i, int j, Board T, Mask M);

// Dispatcher général : appelle la bonne fonction selon la pièce en (i,j)
void highlight_possible_moves(int i, int j, Board T, Mask M);

// -----------------------------------------------------------------------
// Fonctions avancées
// -----------------------------------------------------------------------

// Met en évidence les pièces du joueur (couleur_blanche) pouvant bouger
void highlight_movable_pieces(Board T, Mask M, bool couleur_blanche);

// Met en évidence les pièces adverses pouvant être prises au prochain coup
void highlight_attacked_pieces(Board T, Mask M, bool couleur_blanche);

// Met en évidence les pièces adverses pouvant prendre la pièce en (i,j)
void highlight_take_pieces(int i, int j, Board T, Mask M);

#endif // MASK_HPP