#include "nuage.hpp"

Nuage::Nuage() {
}

Nuage::~Nuage() {
    for(Point * p : _points) {
        delete p;
    }
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