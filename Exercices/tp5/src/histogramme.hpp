#ifndef __ZZ__CPP__HISTOGRAMME__
#define __ZZ__CPP__HISTOGRAMME__

#include <vector>
#include <set>
#include <algorithm>
#include <functional>

#include "echantillon.hpp"
#include "classe.hpp"

template <typename T = std::less<Classe>>
class Histogramme
{
private:
    // std::vector<Classe> _classes;
    std::set<Classe, T> _classes;

public:
    Histogramme(const double &i, const double &s, const int &n);

    const std::set<Classe, T> &getClasses() const;

    void ajouter(const double &);

    void ajouter(const Echantillon &);
};

template <typename T>
Histogramme<T>::Histogramme(const double &i, const double &s, const int &n)
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

template <typename T>
const std::set<Classe, T> &Histogramme<T>::getClasses() const { return _classes; }

template <typename T>
void Histogramme<T>::ajouter(const double &valeur)
{

    auto it = std::find_if(_classes.begin(), _classes.end(), [&valeur](const Classe &c)
                           { return (c.getBorneInf() <= valeur && valeur < c.getBorneSup()); });

    Classe ma_classes = *it;
    ma_classes.ajouter();

    _classes.erase(it);

    _classes.insert(ma_classes);
}

template <typename T>
void Histogramme<T>::ajouter(const Echantillon &e)
{
    for (const auto &v : e)
    {
        ajouter(v.getNombre());
    }
}

#endif