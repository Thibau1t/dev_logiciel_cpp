#ifndef __ZZ__CPP__PAQUET__
#define __ZZ__CPP__PAQUET__

#include <vector>
#include <ostream>

#include "usine.hpp"

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t &p, const UsineCarte &u)
{
    while (auto carte = u.getCarte())
    {
        p.push_back(std::move(carte));
    }
}

std::ostream &operator<<(std::ostream &os, const paquet_t &p)
{
    for (const auto &carte : p)
    {
        os << carte->getValeur() << " ";
    }
    return os;
}

#endif