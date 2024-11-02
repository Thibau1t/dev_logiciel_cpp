#ifndef __ZZ__iterator__hpp
#define __ZZ__iterator__hpp

class Iterator
{
private:
    int *_ptr;

public:
    Iterator(int *ptr = nullptr);

    Iterator &operator++();
    Iterator operator++(int);
    int &operator*() const;
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
};

#endif