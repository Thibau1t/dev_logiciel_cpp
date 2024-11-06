#ifndef __ZZ3_CPP_FACTORIELLE__
#define __ZZ3_CPP_FACTORIELLE__

template <int N>
struct Factorielle
{
public:
    static const unsigned long valeur;
};

template <int N>
const unsigned long Factorielle<N>::valeur = N * Factorielle<N - 1>::valeur;

template <>
struct Factorielle<0>
{
    static const unsigned long valeur = 1;
};

#endif