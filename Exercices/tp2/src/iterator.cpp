#include "iterator.hpp"

Iterator::Iterator(int * p) : _ptr(p) {} 

Iterator& Iterator::operator++() {
    ++_ptr;
    return *this; 
}

Iterator Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

int& Iterator::operator*() const {
    return *_ptr;
}

bool Iterator::operator==(const Iterator& o) const {
    return _ptr == o._ptr;
}

bool Iterator::operator!=(const Iterator& o) const {
    return _ptr != o._ptr;
}
