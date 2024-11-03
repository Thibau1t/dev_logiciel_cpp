#ifndef __ZZ__CPP__CARTE__
#define __ZZ__CPP__CARTE__

class Carte
{
private:
    unsigned short int _value;

public:
    Carte(int v) { _value = v; }

    unsigned short int getValeur() const;
};
#endif