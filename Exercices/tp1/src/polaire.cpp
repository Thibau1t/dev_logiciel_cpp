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

void Polaire::afficher() const{
}