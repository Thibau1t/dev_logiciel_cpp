#include "cartesien.hpp"

Cartesien::Cartesien(const double x, const double y) : _x(x), _y(y) {
}

double Cartesien::getX() const {
    return _x;
}

double Cartesien::getY() const {
    return _y;
}

void Cartesien::setX(const double x) {
    _x = x;
}

void Cartesien::setY(const double y) {
    _y = y;
}

void Cartesien::afficher(std::ostream & os) const {
    os << "(x=" << _x << ";y=" << _y << ")";
}

std::istream & operator>>(std::istream& flux, Cartesien & c){
    double x, y;
    flux >> x >> y;
    c.setX(x);
    c.setY(y);

    return flux;
}