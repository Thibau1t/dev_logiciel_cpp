#include "usine.hpp"

std::unique_ptr<Carte> UsineCarte::getCarte() const
{
    std::unique_ptr<Carte> p = nullptr;

    if (_compteur < 52) // unsigned int donc tjr >=0
    {
        p = std::make_unique<Carte>(_compteur);
        ++_compteur;
    }
    return p;
}