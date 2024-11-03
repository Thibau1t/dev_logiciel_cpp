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

std::ostream &operator<<(std::ostream &os, const ressources_t &r)
{
    for (const auto &ressource : r)
    {
        if (auto res = ressource.lock())
        {
            os << res->getStock() << " ";
        }
        else
        {
            os << "- ";
        }
    }
    return os;
}
