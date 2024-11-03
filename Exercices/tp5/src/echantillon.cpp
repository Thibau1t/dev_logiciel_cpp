#include "echantillon.hpp"

Echantillon::Echantillon(const unsigned int t) : _taille(t) {}

unsigned int Echantillon::getTaille() const { return _taille; }