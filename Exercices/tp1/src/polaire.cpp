#include "polaire.hpp"


Polaire::Polaire(const double a, const double r) {
    _angle  = a;
    _radius = r;

    _x = r * cos(a);
    _y = r * sin(a);
}

Polaire::~Polaire() {
}

double Polaire::getAngle() const {
    return _angle;
}

double Polaire::getDistance() const {
    return _radius;
}

void Polaire::setAngle(const double a){
    _angle = a;
    _x = _radius * cos(a);
    _y = _radius * sin(a);
}

void Polaire::setDistance(const double r) {
    _radius = r;

    _x = r * cos(_angle);
    _y = r * sin(_angle);
}

void Polaire::afficher(std::ostream & os) const{
    os << "(a=" << _angle << ";d=" << _radius << ")";
}