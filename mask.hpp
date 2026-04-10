#ifndef MASK_HPP
#define MASK_HPP

// =============================================================================
// mask.hpp — Déclarations des fonctions de calcul des déplacements possibles
// =============================================================================
//
// Un "masque" (Mask) est un tableau 8x8 d'entiers qui sert à marquer
// des cases d'intérêt sur le plateau pour l'affichage coloré.
//
// Valeurs du masque :
//   0 = case normale (couleur de damier par défaut)
//   1 = bleu  → la pièce peut se déplacer sur cette case
//   2 = rouge → la pièce peut prendre une pièce adverse sur cette case
//   3 = vert  → pièce adverse présente mais protégée (non attaquable)
//
// Ce fichier déclare :
//   - Les opérations de base sur le masque (vider, lire, écrire)
//   - Les fonctions de calcul des coups par type de pièce
//   - Les fonctions avancées (pièces déplaçables, attaquées, prenables)
//
// Toutes les implémentations sont dans mask.cpp.
// =============================================================================

#include "types.hpp"
#include "board.hpp"

// --- Opérations de base sur le masque ---

// Met toutes les valeurs du masque à 0 (initialisation)
void empty_mask(Mask M);

// Remet toutes les valeurs du masque à 0 (remise à zéro)
// (identique à empty_mask, utilisé pour clarté dans le code)
void clear_mask(Mask M);

// Retourne la valeur du masque à la case (i, j)
// Retourne 0 si la case est hors du plateau
int get_mask(int i, int j, Mask M);

// Définit la valeur val dans le masque à la case (i, j)
// Ne fait rien si la case est hors du plateau
void set_mask(int i, int j, Mask M, int val);

// --- Calcul des déplacements possibles par type de pièce ---
// Chaque fonction remplit le masque M avec :
//   1 pour les cases où la pièce peut se déplacer (case vide)
//   2 pour les cases où la pièce peut prendre une pièce adverse

// Déplacements du Roi (une case dans les 8 directions)
void highlight_possible_moves_king(int i, int j, Board T, Mask M);

// Déplacements de la Tour (en ligne droite, bloquée par les pièces)
void highlight_possible_moves_rook(int i, int j, Board T, Mask M);

// Déplacements du Fou (en diagonale, bloqué par les pièces)
void highlight_possible_moves_bishop(int i, int j, Board T, Mask M);

// Déplacements de la Reine (combine Tour + Fou)
void highlight_possible_moves_queen(int i, int j, Board T, Mask M);

// Déplacements du Cavalier (en L, peut sauter par-dessus les pièces)
void highlight_possible_moves_knight(int i, int j, Board T, Mask M);

// Déplacements du Pion (avance, double pas au départ, prises en diagonale)
void highlight_possible_moves_pawn(int i, int j, Board T, Mask M);

// Appelle automatiquement la bonne fonction selon la pièce en (i, j)
void highlight_possible_moves(int i, int j, Board T, Mask M);

// --- Fonctions avancées ---

// Marque avec val=1 toutes les pièces du joueur (blanc si couleur_blanche=true)
// qui ont au moins un déplacement possible
void highlight_movable_pieces(Board T, Mask M, bool couleur_blanche);

// Marque les pièces adverses :
//   val=2 si elles peuvent être prises au prochain coup
//   val=3 si elles sont présentes mais non attaquables
void highlight_attacked_pieces(Board T, Mask M, bool couleur_blanche);

// Marque avec val=2 toutes les pièces adverses qui peuvent prendre
// la pièce se trouvant sur la case (i, j)
void highlight_take_pieces(int i, int j, Board T, Mask M);

#endif // MASK_HPP