#ifndef __ZZ__Poilaire__hpp
#define __ZZ__Poilaire__hpp

#include <cmath>
#include "point.hpp"

class Polaire : public Point {

private : 
    double _angle;
    double _radius;

public :
    Polaire(const double x=0, const double y=0);
    ~Polaire();

    double getAngle() const;
    double getDistance() const;

    void setAngle(const double);
    void setDistance(const double);

    void afficher(std::ostream &) const;
};


#endif