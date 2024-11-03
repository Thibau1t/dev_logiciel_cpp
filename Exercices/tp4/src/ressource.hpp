#ifndef __ZZ__CPP__RESSOURCE__
#define __ZZ__CPP__RESSOURCE__

#include <memory>
#include <vector>
#include <ostream>

class Ressource
{
private:
    unsigned int _stock;

public:
    Ressource(const unsigned int &);

    void consommer(const unsigned int &);

    int getStock() const;
};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream &operator<<(std::ostream &, const ressources_t &);

#endif