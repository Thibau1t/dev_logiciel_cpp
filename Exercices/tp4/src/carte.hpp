#ifndef __ZZ__CPP__CARTE__
#define __ZZ__CPP__CARTE__

class UsineCarte;

class Carte
{
private:
    unsigned short int _value;

    // constructeur ad hoc privée
    Carte(int v) { _value = v; }

    // supression constructeur de copie et d'affectation
    Carte(const Carte &) = delete;
    Carte &operator=(const Carte &) = delete;

public:
    unsigned short int getValeur() const;

    // Friend
    friend class UsineCarte;
};
#endif