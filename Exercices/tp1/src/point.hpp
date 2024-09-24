#ifndef __ZZ__point__hpp
#define __ZZ__point__hpp

#include <iostream>

class Polaire;
class Cartesien;

// class abstraite
class Point {
public:

    virtual ~Point() = default;

    virtual void afficher(std::ostream& flux) const = 0;
    virtual void convertir(Polaire &) const = 0;
    virtual void convertir(Cartesien &) const = 0;
};

std::ostream& operator<<(std::ostream&, const Point &);


#endif