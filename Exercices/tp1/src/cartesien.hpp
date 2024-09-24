#ifndef __ZZ__cartesien__hpp
#define __ZZ__cartesien__hpp

#include "point.hpp"

class Cartesien : public Point {
private :

public :
    Cartesien(const double x=0, const double y=0);
    ~Cartesien();

    void afficher(std::ostream &) const;
};


#endif