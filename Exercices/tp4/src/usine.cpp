#include "usine.hpp"

UsineCarte::UsineCarte(unsigned int n)
{
    _taille = n;
}

std::unique_ptr<Carte> UsineCarte::getCarte() const
{
    if (_compteur < _taille) // pas besoin de regarder >=0 car usigned int
    {
        return std::unique_ptr<Carte>(new Carte(_compteur++));
    }
    return nullptr;
}
