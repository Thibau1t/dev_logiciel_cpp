#ifndef __ZZ__CPP__CONSOMMATEUR__
#define __ZZ__CPP__CONSOMMATEUR__

#include <memory>

#include "ressource.hpp"

class Consommateur
{
    using shared_pr = std::shared_ptr<Ressource>;

private:
    unsigned int _besoin;
    shared_pr _shared_ptr_r;

public:
    Consommateur(const unsigned int &, const shared_pr &);

    void puiser();
};

#endif