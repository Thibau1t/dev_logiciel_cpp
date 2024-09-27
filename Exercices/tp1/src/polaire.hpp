#ifndef __ZZ__Poilaire__hpp
#define __ZZ__Poilaire__hpp

#include "point.hpp"

class Cartesien; // déclaration anticipée

class Polaire : public Point {

private : 
    double _a, _d;

public :
    Polaire(const double a=0, const double d=0);
    Polaire(const Cartesien &);

    double getAngle() const;
    double getDistance() const;

    void setAngle(const double);
    void setDistance(const double);

    void afficher(std::ostream &) const override;

    void convertir(Cartesien &) const override;
    void convertir(Polaire &) const override;

};

std::istream & operator>>(std::istream&, Polaire &); 

#endif