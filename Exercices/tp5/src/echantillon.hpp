#ifndef __ZZ__CPP__ECHANTILLON_
#define __ZZ__CPP__ECHANTILLON__

#include <vector>
#include <algorithm>

#include "valeur.hpp"

class Echantillon
{
private:
    std::vector<Valeur> _valeurs;

public:
    Echantillon() = default;

    unsigned int getTaille() const;

    void ajouter(const double &);

    const Valeur &getMinimum() const;
    const Valeur &getMaximum() const;
    const Valeur &getValeur(const int &) const;
};

#endif