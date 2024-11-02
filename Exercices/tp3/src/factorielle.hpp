#ifndef __ZZ3_CPP_FACTORIELLE__
#define __ZZ3_CPP_FACTORIELLE__

template <int N>
struct Factorielle
{
    static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
};

template <>
struct Factorielle<0>
{
    static const unsigned long valeur = 1;
};

#endif