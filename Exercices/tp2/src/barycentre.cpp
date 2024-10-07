#include "nuage.hpp"

/*
template <typename T>
T barycentre_v1(const Nuage<T>& n) {
    size_t count = n.size();
    if (count == 0) return T(Cartesien(0.0, 0.0));
    
    double sumX = 0.0; double sumY = 0.0;

    for (auto it = n.begin(); it != n.end(); ++it) {
        const T p = *it;
        Cartesien c;
        p.convertir(c);
        sumX += c.getX();
        sumY += c.getY();
    }

    return T(Cartesien(sumX / count, sumY / count));
}
*/