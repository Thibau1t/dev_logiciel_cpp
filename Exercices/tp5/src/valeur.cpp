#include "valeur.hpp"

Valeur::Valeur(const double &v, const std::string &n) : _v(v), _nom(n) {}

double Valeur::getNombre() const
{
    return _v;
}

double Valeur::getNote() const
{
    return _v;
}

void Valeur::setNombre(const double &v)
{
    _v = v;
}

std::string Valeur::getEtudiant() const
{
    return _nom;
}