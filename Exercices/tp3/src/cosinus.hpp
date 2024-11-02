#ifndef __ZZ__CPP__COSINUS__
#define __ZZ__CPP__COSINUS__

template <int N>
class Cosinus
{
public:
    static double valeur(const double &v)
    {
        return Cosinus<N - 1>::valeur(v) + Puissance<N>::valeur(-1) * (Puissance<2 * N>::valeur(v) / Factorielle<2 * N>::valeur);
    }
};

template <>
class Cosinus<0>
{
public:
    static double valeur(const double &)
    {
        return 1;
    }
};

#endif