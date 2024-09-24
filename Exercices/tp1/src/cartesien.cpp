#include "cartesien.hpp"

Cartesien::Cartesien(const double x, const double y) {
    _x = x;
    _y = y;
}

Cartesien::~Cartesien() {

}

void Cartesien::afficher(std::ostream & os) const{
    os << "(x=" << _x << ";y=" << _y << ")";
}
