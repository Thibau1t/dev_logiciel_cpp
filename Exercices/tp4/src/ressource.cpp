#include "ressource.hpp"

Ressource::Ressource(const unsigned int &s) : _stock(s) {}

void Ressource::consommer(const unsigned int &c)
{
    if (c > _stock)
    {
        _stock = 0;
    }
    else
    {
        _stock -= c;
    }
}

int Ressource::getStock() const
{
    return _stock;
}