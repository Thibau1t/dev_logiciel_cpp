#include "echantillon.hpp"

unsigned int Echantillon::getTaille() const { return _valeurs.size(); }

void Echantillon::ajouter(const double &v)
{
    _valeurs.push_back(v);
}