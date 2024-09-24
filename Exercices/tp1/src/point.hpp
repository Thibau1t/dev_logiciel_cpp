#ifndef __ZZ__point__hpp
#define __ZZ__point__hpp

#include <stdio.h> 

class Point {

protected :
    double _x;
    double _y;

public :
    Point(double x=0, double y=0);

    virtual ~Point();

    double getX() const;
    double getY() const;

    virtual void afficher() const = 0;
};

#endif