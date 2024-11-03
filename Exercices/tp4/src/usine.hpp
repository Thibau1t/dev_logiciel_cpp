#ifndef __ZZ__CPP__USINE__
#define __ZZ__CPP__USINE__

#include <memory>

#include "carte.hpp"

class UsineCarte
{
private:
    mutable unsigned int _compteur = 0;
    unsigned int _taille;

    // supression constructeur par copie et d'affectation
    UsineCarte(const UsineCarte &) = delete;
    UsineCarte &operator=(const UsineCarte &) = delete;

public:
    explicit UsineCarte(unsigned int n = 52);
    std::unique_ptr<Carte> getCarte() const;
};

#endif