#include "nuage.hpp"

Cartesien Nuage::barycentre(const Nuage & n) {
    size_t size = n.size();

    double sum_x = 0.0;
    double sum_y = 0.0;

    for(size_t i=0; i<size; ++i) {

        Point * point = n.getPoint(i);

        if (dynamic_cast<Cartesien*>(point)) { // if point is Cartesien
            Cartesien* c = dynamic_cast<Cartesien*>(point);
            sum_x += c->getX();
            sum_y += c->getY();
        } else if (dynamic_cast<Polaire*>(point)) { // if point is Polaire
            Polaire* p = dynamic_cast<Polaire*>(point);
            Cartesien c(*p); // convert Polaire to Cartesien
            sum_x += c.getX();
            sum_y += c.getY();
        }
    }


    return (size == 0) ? Cartesien(0, 0) : Cartesien(sum_x / size, sum_y / size);
}

Cartesien Nuage::BarycentreCartesien::operator()(const Nuage &n) const {
    return Nuage::barycentre(n);
}

Polaire Nuage::BarycentrePolaire::operator()(const Nuage &n) const {
    return Polaire(Nuage::barycentre(n));
}


Nuage::Nuage() {
}

Nuage::~Nuage() {
    for(Point * p : _points) {
        delete p;
    }
}

Point * Nuage::getPoint(size_t i) const {
    return _points.at(i);
}

void Nuage::ajouter(const Point&  p) {
    _points.push_back(p.clone());
} 

size_t Nuage::size() const {
    return _points.size();
}

Nuage::iterator Nuage::begin() {
    return _points.begin();
}


Nuage::iterator Nuage::end() {
    return _points.end();
}

Nuage::const_iterator Nuage::begin() const {
    return _points.begin();
};

Nuage::const_iterator Nuage::end() const {
    return _points.end();
};