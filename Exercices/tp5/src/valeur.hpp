#ifndef __ZZ__CPP__VALEUR__
#define __ZZ__CPP__VALEUR__

#include <string>

class Valeur
{
private:
    double _v;
    std::string _nom;

public:
    Valeur(const double &v = 0.0, const std::string &n = "inconnu");

    double getNombre() const;
    double getNote() const;
    std::string getEtudiant() const;

    void setNombre(const double &);
    void setNote(const double &);
    void setEtudiant(const std::string &);
};

#endif