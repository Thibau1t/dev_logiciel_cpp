#ifndef __ZZ__cartesien__hpp
#define __ZZ__cartesien__hpp

#include <iostream>

#include "point.hpp"

class Cartesien : public Point {
private:
    double _x, _y;
    
public:
    // Constructeurs
    Cartesien(const double x = 0.0, const double y = 0.0);

    // Accesseurs
    double getX() const;
    double getY() const;

    void setX(const double);
    void setY(const double);

    // Méthode afficher
    void afficher(std::ostream& flux) const override;
};

std::istream & operator>>(std::istream&, Cartesien &); 

#endif