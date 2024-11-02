#include "vecteur.hpp"

Vecteur::Vecteur() : _data(nullptr), _size(0), _capacity(0) {}

Vecteur::Vecteur(int n) : _size(0), _capacity(n)
{
    _data = new int[_capacity];
}

Vecteur::Vecteur(const Vecteur &o) : _size(o._size), _capacity(o._capacity)
{
    _data = new int[_capacity];
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = o._data[i];
    }
}

Vecteur::~Vecteur()
{
    delete[] _data;
}

Vecteur &Vecteur::operator=(const Vecteur &o)
{
    if (this != &o)
    {
        delete[] _data;
        _size = o._size;
        _capacity = o._capacity;
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _data[i] = o._data[i];
        }
    }
    return *this;
}

Vecteur Vecteur::operator+(const Vecteur &o) const
{
    Vecteur result(_size + o._size);

    for (int i = 0; i < _size; ++i)
    {
        result._data[i] = _data[i];
    }

    // Copy the other vector's data
    for (int i = 0; i < o._size; ++i)
    {
        result._data[_size + i] = o._data[i];
    }

    result._size = _size + o._size;

    return result;
}

int &Vecteur::operator[](int index)
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

const int &Vecteur::operator[](int index) const
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

int Vecteur::operator*(const Vecteur &o) const
{
    if (_size != o._size)
    {
        throw std::invalid_argument("Vectors must be of the same size for scalar product");
    }
    int product = 0;
    for (int i = 0; i < _size; ++i)
    {
        product += _data[i] * o._data[i];
    }
    return product;
}

void Vecteur::add(int v)
{
    if (_size == _capacity)
    {
        _capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int *newData = new int[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }
    _data[_size++] = v;
}

int Vecteur::get(int index) const
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

int Vecteur::size() const
{
    return _size;
}

void Vecteur::print(std::ostream &os) const
{
    for (int i = 0; i < _size; ++i)
    {
        os << _data[i] << " ";
    }
    os << std::endl;
}

Iterator Vecteur::begin()
{
    return Iterator(_data);
}

Iterator Vecteur::end()
{
    return Iterator(_data + _size);
}

std::ostream &operator<<(std::ostream &os, const Vecteur &v)
{
    v.print(os);
    return os;
}