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