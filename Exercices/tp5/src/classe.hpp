#ifndef __ZZ__CPP__CLASSE_
#define __ZZ__CPP__CLASSE__

#include <vector>

class Classe
{
private:
    double _inf;
    double _sup;
    unsigned int _quantite;

public:
    Classe(const double &, const double &);

    const double &getBorneInf() const;
    const double &getBorneSup() const;
    const unsigned int &getQuantite() const;
};

#endif