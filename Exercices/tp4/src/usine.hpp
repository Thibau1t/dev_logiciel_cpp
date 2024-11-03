#ifndef __ZZ__CPP__USINE__
#define __ZZ__CPP__USINE__

#include <memory>

#include "carte.hpp"

class UsineCarte
{
private:
    inline static unsigned int _compteur = 0;

public:
    std::unique_ptr<Carte> getCarte() const;
};

#endif