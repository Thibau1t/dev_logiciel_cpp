#ifndef __ZZ__CPP__ECHANTILLON_
#define __ZZ__CPP__ECHANTILLON__

class Echantillon
{
private:
    unsigned int _taille;

public:
    Echantillon(const unsigned int t = 0);

    unsigned int getTaille() const;
};

#endif