#ifndef __ZZ__CPP__CLASSE__
#define __ZZ__CPP__CLASSE__

#include <vector>

class Classe
{
private:
    double _inf;
    double _sup;
    unsigned int _quantite;

public:
    Classe(const double &, const double &);
    Classe(const Classe &);

    const double &getBorneInf() const;
    const double &getBorneSup() const;
    const unsigned int &getQuantite() const;

    void setBorneInf(const double &);
    void setBorneSup(const double &);
    void setQuantite(const unsigned int &);

    void ajouter();

    bool operator<(const Classe &) const;
    bool operator>(const Classe &) const;
};

#endif