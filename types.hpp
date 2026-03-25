ifndef TYPES_HPP_
#define TYPES_HPP_

enum Piece
{
    r,
    n,
    b,
    q,
    k,
    p,
    R,
    N,
    B,
    Q,
    K,
    P,
    vide
};
/// Board c'est le tableau de 2 dimensions
using Board = Piece[8][8];

#endif