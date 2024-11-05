#ifndef __ZZ__CPP__HISTOGRAMME__
#define __ZZ__CPP__HISTOGRAMME__

#include <vector>
#include <set>
#include <algorithm>

#include "echantillon.hpp"
#include "classe.hpp"

class Histogramme
{
private:
    // std::vector<Classe> _classes;
    std::set<Classe> _classes;

public:
    Histogramme(const double &i, const double &s, const int &n);

    const std::set<Classe> &getClasses() const;

    void ajouter(const double &);

    void ajouter(const Echantillon &);
};

#endif