#ifndef __ZZ__Nuage__hpp
#define __ZZ__Nuage__hpp

#include <vector>

#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"


class Nuage {
private :
    std::vector<Point *> _points;

public : 
    using iterator = std::vector<Point*>::iterator; // Non-const iterator
    using const_iterator = std::vector<Point*>::const_iterator; // Const iterator

    Cartesien static barycentre(const Nuage &);
    

    struct BarycentreCartesien {
        Cartesien operator()(const Nuage &n) const;
    };

    struct BarycentrePolaire {
        Polaire operator()(const Nuage &n) const;
    };

    Nuage();
    ~Nuage();

    Point * getPoint(size_t) const;

    void ajouter(const Point &);
    size_t size() const;
    
    
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;


};

#endif