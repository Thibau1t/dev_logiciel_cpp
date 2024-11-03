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