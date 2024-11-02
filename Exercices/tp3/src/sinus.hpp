#ifndef __ZZ__CPP__SINUS__
#define __ZZ__CPP__SINUS__

#include "puissance.hpp"
#include "factorielle.hpp"

template <int N>
class Sinus
{
public:
    static double valeur(const double &v)
    {
        return Sinus<N - 1>::valeur(v) +
               Puissance<N>::valeur(-1) *
                   (Puissance<2 * N + 1>::valeur(v) / Factorielle<2 * N + 1>::valeur);
    }
};

template <>
class Sinus<0>
{
public:
    static double valeur(const double &v)
    {
        return v;
    }
};

#endif
