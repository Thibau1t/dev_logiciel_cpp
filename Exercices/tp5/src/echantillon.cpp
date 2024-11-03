#include "echantillon.hpp"
#include <iostream>

unsigned int Echantillon::getTaille() const { return _valeurs.size(); }

void Echantillon::ajouter(const double &v)
{
    _valeurs.emplace_back(v); // creer un objet :: emplace_back
}

Valeur Echantillon::getMinimum() const
{
    if (_valeurs.empty())
        throw std::domain_error("Erreur : le tableau est vide !");

    return *(std::min_element(_valeurs.begin(), _valeurs.end(), [](const Valeur &a, const Valeur &b)
                              { return a.getNombre() < b.getNombre(); }));
}
Valeur Echantillon::getMaximum() const
{
    if (_valeurs.empty())
        throw std::domain_error("Erreur : le tableau est vide !");

    return *(std::max_element(_valeurs.begin(), _valeurs.end(), [](const Valeur &a, const Valeur &b)
                              { return a.getNombre() < b.getNombre(); }));
}