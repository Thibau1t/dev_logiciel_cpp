#ifndef __ZZ3_CPP_PUISSANCE__
#define __ZZ3_CPP_PUISSANCE__

template <int N>
struct Puissance
{
    static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
};

template <>
struct Puissance<0>
{
    static const unsigned long valeur = 1;
};

#endif