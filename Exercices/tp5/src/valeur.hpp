#ifndef __ZZ__CPP__VALEUR__
#define __ZZ__CPP__VALEUR__

class Valeur
{
private:
    double _v;

public:
    Valeur(const double &v = 0.0);

    double getNombre() const;
};

#endif