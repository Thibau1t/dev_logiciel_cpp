#include "histogramme.hpp"

Histogramme::Histogramme(const double &i, const double &s, const int &n)
{
    double width = (s - i) / n;
    double borneInf, borneSup;

    for (int j = 0; j < n; ++j)
    {
        borneInf = i + j * width;
        borneSup = borneInf + width;
        Classe c(borneInf, borneSup);
        _classes.insert(c);
    }
}

const std::set<Classe> &Histogramme::getClasses() const { return _classes; }

void Histogramme::ajouter(const double &valeur)
{

    auto it = std::find_if(_classes.begin(), _classes.end(), [&valeur](const Classe &c)
                           { return (c.getBorneInf() <= valeur && valeur < c.getBorneSup()); });

    Classe ma_classes = *it;
    ma_classes.ajouter();

    _classes.erase(it);

    _classes.insert(ma_classes);
}

void Histogramme::ajouter(const Echantillon &e)
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