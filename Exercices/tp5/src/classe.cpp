#include "classe.hpp"

Classe::Classe(const double &i, const double &s) : _inf(i), _sup(s), _quantite(0) {}

const double &Classe::getBorneInf() const { return _inf; }
const double &Classe::getBorneSup() const { return _sup; }
const unsigned int &Classe::getQuantite() const
{
    return _quantite;
}