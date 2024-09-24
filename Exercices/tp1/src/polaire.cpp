#include "polaire.hpp"


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


std::istream & operator>>(std::istream& flux, Polaire & p) {
    double a, d;
    flux >> a >> d;

    p.setAngle(a);
    p.setDistance(d);

    return flux;
}

