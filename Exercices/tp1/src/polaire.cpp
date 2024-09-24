#include "polaire.hpp"
#include "cartesien.hpp"


Polaire::Polaire(const double a, const double d) {
    _a  = a;
    _d = d;
}

double Polaire::getAngle() const {
    return _a;
}

double Polaire::getDistance() const {
    return _d;
}

void Polaire::setAngle(const double a){
    _a = a;
}

void Polaire::setDistance(const double d) {
    _d = d;
}

void Polaire::afficher(std::ostream & os) const{
    os << "(a=" << _a << ";d=" << _d << ")";
}

void Polaire::convertir(Cartesien & c) const {
    double radians = _a * (M_PI / 180.0); // Convertir l'angle en radians
    double x = _d * cos(radians);
    double y = _d * sin(radians);

    c.setX(x);
    c.setY(y);
}

void Polaire::convertir(Polaire & p) const{
    p = *this; 
}

std::istream & operator>>(std::istream& flux, Polaire & p) {
    double a, d;
    flux >> a >> d;

    p.setAngle(a);
    p.setDistance(d);

    return flux;
}

