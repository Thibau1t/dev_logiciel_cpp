#ifndef __ZZ__CPP__RESSOURCE__
#define __ZZ__CPP__RESSOURCE__

class Ressource
{
private:
    unsigned int _stock;

public:
    Ressource(const unsigned int &);

    void consommer(const unsigned int &);

    int getStock() const;
};

#endif