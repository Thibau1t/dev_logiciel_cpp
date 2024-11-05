#ifndef __ZZ__CPP__ECHANTILLON__
#define __ZZ__CPP__ECHANTILLON__

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

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

    std::vector<Valeur>::const_iterator begin() const;
    std::vector<Valeur>::const_iterator end() const;
};

#endif