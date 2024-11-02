#ifndef __ZZ3_CPP_PUISSANCE__
#define __ZZ3_CPP_PUISSANCE__

template <int N>
class Puissance
{
public:
    static double valeur(const double &v)
    {
        return Puissance<N - 1>::valeur(v) * v;
    }
};

template <>
class Puissance<0>
{
public:
    static double valeur(const double &)
    {
        return 1;
    }
};

template <>
class Puissance<1>
{
public:
    static double valeur(const double &v)
    {
        return v;
    }
};

#endif