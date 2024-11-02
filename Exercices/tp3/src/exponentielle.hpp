#ifndef __ZZ3__CPP__EXPONENTIELLE__
#define __ZZ3__CPP__EXPONENTIELLE__

#include "puissance.hpp"

template <int N>
class Exponentielle
{
public:
    static double valeur(const double &v)
    {
        return Exponentielle<N - 1>::valeur(v) + (Puissance<N>::valeur(v) / Factorielle<N>::valeur);
    }
};

template <>
class Exponentielle<0>
{
public:
    static double valeur(const double &)
    {
        return 1;
    }
};

#endif