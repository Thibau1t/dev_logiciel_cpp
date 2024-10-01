#ifndef __ZZ__Nuage__hpp
#define __ZZ__Nuage__hpp

#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"


template <typename T> 
class Nuage {
private :
    std::vector<T> _points;

public : 
    using iterator = typename std::vector<T>::iterator; // Non-const iterator
    using const_iterator = typename std::vector<T>::const_iterator; // Const iterator

    static T barycentre(const Nuage<T> &);

    struct BarycentreCartesien {
        Cartesien operator()(const Nuage<T> &n) const;
    };

    struct BarycentrePolaire {
        Polaire operator()(const Nuage<T> &n) const;
    };

    Nuage() = default;
    ~Nuage();

    T getPoint(size_t) const;

    void ajouter(const T &);
    size_t size() const;
    
    
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <typename T>
Nuage<T>::~Nuage() {
}

template <typename T>
T Nuage<T>::getPoint(size_t i) const {
    return _points.at(i);
}

template <typename T>
void Nuage<T>::ajouter(const T&  p) {
    _points.push_back(p);
} 

template <typename T>
size_t Nuage<T>::size() const {
    return _points.size();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin() {
    return _points.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end() {
    return _points.end();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
    return _points.begin();
};

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
    return _points.end();
};


template <typename T>
T Nuage<T>::barycentre(const Nuage<T>& n) {
    size_t size = n.size();
    double sum_x = 0.0, sum_y = 0.0;

    for (const auto& point : n._points) {
        if constexpr (std::is_same_v<T, Cartesien>) {
            sum_x += point.getX();
            sum_y += point.getY();
        } else if constexpr (std::is_same_v<T, Polaire>) {
            Cartesien c(point);
            sum_x += c.getX();
            sum_y += c.getY();
        }
    }

    return (size == 0) ? T(0, 0) : T(sum_x / size, sum_y / size);
}

template <typename T>
Cartesien Nuage<T>::BarycentreCartesien::operator()(const Nuage<T> &n) const {
    return Nuage<T>::barycentre(n);
}

template <typename T>
Polaire Nuage<T>::BarycentrePolaire::operator()(const Nuage<T> &n) const {
    return Polaire(Nuage<T>::barycentre(n));
}

template class Nuage<Cartesien>;
template class Nuage<Polaire>;

#endif