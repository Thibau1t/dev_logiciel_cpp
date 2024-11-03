#include "valeur.hpp"

Valeur::Valeur(const double &v) : _v(v) {}

double Valeur::getNombre() const
{
    return _v;
}