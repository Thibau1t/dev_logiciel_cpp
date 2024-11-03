#ifndef __ZZ__CPP__HISTOGRAMME__
#define __ZZ__CPP__HISTOGRAMME__

#include <vector>

#include "classe.hpp"

class Histo
{
private:
    std::vector<Classe> _classes;

public:
    Histo(const double &i, const double &s, const int &n);

    const std::vector<Classe> &getClasses() const;
};

#endif