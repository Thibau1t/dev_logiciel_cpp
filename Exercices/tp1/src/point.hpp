#ifndef __ZZ__point__hpp
#define __ZZ__point__hpp

#include <iostream>

class Point {

protected :
    double _x;
    double _y;

public :
    Point(double x=0, double y=0);

    virtual ~Point();

    double getX() const;
    double getY() const;

    void setX(const double);
    void setY(const double);


    virtual void afficher(std::ostream &) const = 0;

    friend std::ostream & operator<<(std::ostream &, Point  const &);
};

std::ostream & operator<<(std::ostream &, Point const &);

#endif