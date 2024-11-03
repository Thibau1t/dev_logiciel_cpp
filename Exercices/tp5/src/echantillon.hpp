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

    Valeur getMinimum() const;
    Valeur getMaximum() const;
};

#endif