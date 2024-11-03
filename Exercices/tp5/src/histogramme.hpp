#ifndef __ZZ__CPP__HISTOGRAMME__
#define __ZZ__CPP__HISTOGRAMME__

#include <vector>
#include <algorithm>

#include "echantillon.hpp"
#include "classe.hpp"

class Histo
{
private:
    std::vector<Classe> _classes;

public:
    Histo(const double &i, const double &s, const int &n);

    const std::vector<Classe> &getClasses() const;

    void ajouter(const double &);

    void ajouter(const Echantillon &);
};

#endif