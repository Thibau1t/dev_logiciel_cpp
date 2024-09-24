#include "point.hpp"

Point::Point(double x, double y) :  _x(x), _y(y) {
}

Point::~Point() {
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

void Point::setX(const double x) {
    _x = x;
}

void Point::setY(const double y) {
    _y = y;
}

std::ostream & operator<<(std::ostream & os, Point const & p) {
    os << "(x=" << p._x << ";y=" << p._y << ")";
    return os;
}