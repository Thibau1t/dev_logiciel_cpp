#include "histogramme.hpp"

Histo::Histo(const double &i, const double &f, const int &n)
{
    double width = (f - i) / n;
    double borneInf, borneSup;

    for (int j = 0; j < n; ++j)
    {
        borneInf = i + j * width;
        borneSup = borneInf + width;
        _classes.emplace_back(borneInf, borneSup);
    }
}

const std::vector<Classe> &Histo::getClasses() const { return _classes; }

void Histo::ajouter(const double &valeur)
{
    auto it = std::find_if(_classes.begin(), _classes.end(), [&valeur](const Classe &c)
                           { return (c.getBorneInf() <= valeur && valeur < c.getBorneSup()); });

    if (it != _classes.end())
    {
        it->ajouter();
    }
}

void Histo::ajouter(const Echantillon &e)
{
    for (const auto &v : e)
    {
        ajouter(v.getNombre());
    }
    /*
    for (unsigned int i = 0; i < e.getTaille(); ++i)
    {
        this->ajouter(e.getValeur(i).getNombre());
    }
    */
}