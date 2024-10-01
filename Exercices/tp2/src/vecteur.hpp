#ifndef __ZZ__vecteur__hpp
#define __ZZ__vecteur__hpp

#include <iostream>

#include "iterator.hpp"

class Vecteur {
private:
    int* _data;
    int _size;
    int _capacity;

public:
    Vecteur(); // Default constructor
    Vecteur(int n);
    Vecteur(const Vecteur& o); // Copy constructor
    
    ~Vecteur();

    Vecteur& operator=(const Vecteur& ); // Copy assignment operator
    Vecteur operator+(const Vecteur &) const;
    int & operator[](int); // read/write
    const int & operator[](int) const; // read only
    int operator*(const Vecteur &) const;

    void add(int v);
    int get(int index) const;
    int size() const;
    void print(std::ostream& os) const;

    Iterator begin();
    Iterator end();
};

std::ostream & operator<<(std::ostream &, const Vecteur &); 

#endif