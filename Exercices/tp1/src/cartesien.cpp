#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien(const double x, const double y) : _x(x), _y(y) {
}

Cartesien::Cartesien(const Polaire &) {
    
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

void Cartesien::convertir(Polaire & p) const {
    double distance = sqrt(_x * _x + _y * _y);
    double angle = atan2(_y, _x);

    angle = angle * (180.0 / M_PI); // conversion en degrés

    p.setDistance(distance);
    p.setAngle(angle);
}
void Cartesien::convertir(Cartesien& c) const {
    c = *this;
}

std::istream & operator>>(std::istream& flux, Cartesien & c){
    double x, y;
    flux >> x >> y;
    c.setX(x);
    c.setY(y);

    return flux;
}