#ifndef __ZZ__point__hpp
#define __ZZ__point__hpp

#include <iostream>

// class abstraite
class Point {
public:
    virtual void afficher(std::ostream& flux) const = 0;
    virtual ~Point() = default;

};

std::ostream& operator<<(std::ostream&, const Point &);


#endif