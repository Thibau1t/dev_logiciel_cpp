#ifndef __ZZ__Nuage__hpp
#define __ZZ__Nuage__hpp

#include <vector>
#include <iterator> // Pour std::iterator_traits

#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

template <typename T>
class Nuage
{
public:
    using container_type = std::vector<T>;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    Nuage() = default;
    ~Nuage() = default;

    size_t size() const;
    void ajouter(const T &p);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

private:
    container_type _points;
};

template <typename T>
size_t Nuage<T>::size() const
{
    return _points.size();
}

template <typename T>
void Nuage<T>::ajouter(const T &p)
{
    _points.push_back(p);
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin()
{
    return _points.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end()
{
    return _points.end();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const
{
    return _points.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const
{
    return _points.end();
}

// Déclaration du template générique
template <typename T>
T barycentre_v1(const Nuage<T> &n)
{
    size_t size = n.size();
    if (size == 0)
        return T(Cartesien(0.0, 0.0));

    double sumX = 0.0;
    double sumY = 0.0;

    for (auto it = n.begin(); it != n.end(); ++it)
    {
        const T p = *it;
        Cartesien c;
        p.convertir(c);
        sumX += c.getX();
        sumY += c.getY();
    }

    return T(Cartesien(sumX / size, sumY / size));
}

// Déclaration de la template spécialisée pour Polaire
template <>
Polaire barycentre_v1(const Nuage<Polaire> &nuage)
{
    double sommeAngles = 0.0;
    double sommeDistances = 0.0;
    size_t count = nuage.size();

    if (count == 0)
    {
        return Polaire(0.0, 0.0);
    }

    for (const auto &point : nuage)
    {
        sommeAngles += point.getAngle();
        sommeDistances += point.getDistance();
    }

    double angleMoyen = sommeAngles / count;
    double distanceMoyenne = sommeDistances / count;

    return Polaire(angleMoyen, distanceMoyenne);
}

template <typename Container>
Cartesien barycentre_v2(const Container &nuage)
{
    size_t count = 0;
    double sumX = 0.0;
    double sumY = 0.0;

    for (const auto &point : nuage)
    {
        Cartesien c;
        point.convertir(c);
        sumX += c.getX();
        sumY += c.getY();
        count++;
    }

    return (count == 0) ? Cartesien(0.0, 0.0) : Cartesien(sumX / count, sumY / count);
}

#endif
