#ifndef MASK_HPP_
#define MASK_HPP_

#include "types.hpp"

// Créer un masque sans information (valeurs non initialisées)
void empty_mask(Mask M);

// Réinitialiser un masque à 0
void clear_mask(Mask M);

// Lire le contenu d'une case du masque
int get_mask(int i, int j, Mask M);

// Modifier le contenu d'une case du masque
void set_mask(int i, int j, Mask M, int val);

// Calcule le masque des déplacements possibles de la pièce en (i,j)
void highlight_possible_moves(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles du Roi en (i,j)
void highlight_possible_moves_king(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles de la Tour en (i,j)
void highlight_possible_moves_rook(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles du Fou en (i,j)
void highlight_possible_moves_bishop(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles de la Reine en (i,j)
void highlight_possible_moves_queen(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles du Cavalier en (i,j)
void highlight_possible_moves_knight(int i, int j, Board T, Mask M);

// Calcule les déplacements possibles du Pion en (i,j)
void highlight_possible_moves_pawn(int i, int j, Board T, Mask M);

// Met en évidence toutes les pièces d'une couleur qui peuvent se déplacer (val=1)
// couleur_blanche=true pour les blancs, false pour les noirs
void highlight_movable_pieces(Board T, Mask M, bool couleur_blanche);

// Met en évidence toutes les pièces adverses pouvant être prises au prochain coup
// couleur_blanche=true : cherche les pièces noires attaquables par les blancs
void highlight_attacked_pieces(Board T, Mask M, bool couleur_blanche);

// Met en évidence toutes les pièces adverses pouvant prendre la pièce en (i,j)
void highlight_take_pieces(int i, int j, Board T, Mask M);

#endif
