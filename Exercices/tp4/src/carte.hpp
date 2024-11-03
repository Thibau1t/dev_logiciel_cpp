#ifndef __ZZ__CPP__CARTE__
#define __ZZ__CPP__CARTE__

class UsineCarte;

class Carte
{
private:
    unsigned short int _value;
    inline static unsigned int compteur = 0;

    // constructeur ad hoc privée
    Carte(unsigned int v) : _value(v) { ++compteur; }

    // supression constructeur de copie et d'affectation
    Carte(const Carte &) = delete;
    Carte &operator=(const Carte &) = delete;

public:
    ~Carte() { --compteur; }
    unsigned short int getValeur() const;

    static unsigned int getCompteur();

    // Friend
    friend class UsineCarte;
};
#endif