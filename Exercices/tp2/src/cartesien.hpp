#ifndef __ZZ__Cartesien__hpp
#define __ZZ__Cartesien__hpp

#include <iostream>
#include <cmath>

#include "point.hpp"

class Polaire; // déclaration anticipée

class Cartesien : public Point {
private:
    double _x, _y;
    
public:
    Cartesien(const double x = 0.0, const double y = 0.0);
    Cartesien(const Polaire &);

    Point* clone() const override;

    double getX() const;
    double getY() const;

    void setX(const double);
    void setY(const double);

    void afficher(std::ostream&) const override;
    void convertir(Polaire &) const override;
    void convertir(Cartesien&) const override;
};

std::istream & operator>>(std::istream&, Cartesien &); 

#endif