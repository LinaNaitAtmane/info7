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

#endif

