#ifndef __ZZ__Nuage__hpp
#define __ZZ__Nuage__hpp

#include <vector>
#include <typeinfo>

#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"


template <typename T> 
class Nuage {
public : 
    using container_type = typename std::vector<T>;
    using iterator = typename container_type::iterator; // Non-const iterator
    using const_iterator = typename container_type::const_iterator; // Const iterator
    Nuage() = default;
    ~Nuage() = default;
    size_t size() const;
    void ajouter(const T & p);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

private :
    container_type _Ts;
};

template <typename T>
size_t Nuage<T>::size() const {
    return _Ts.size();
}

template <typename T>
void Nuage<T>::ajouter(const T&  p) {
    _Ts.push_back(p);
} 

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin() {
    return _Ts.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end() {
    return _Ts.end();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const {
    return _Ts.begin();
};

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const {
    return _Ts.end();
};

template class Nuage<Cartesien>;
template class Nuage<Polaire>;

#endif