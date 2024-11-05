#include "classe.hpp"

Classe::Classe(const double &i, const double &s) : _inf(i), _sup(s), _quantite(0) {}

const double &Classe::getBorneInf() const { return _inf; }

const double &Classe::getBorneSup() const { return _sup; }

const unsigned int &Classe::getQuantite() const { return _quantite; }

void Classe::setBorneInf(const double &i) { _inf = i; }
void Classe::setBorneSup(const double &s) { _sup = s; }
void Classe::setQuantite(const unsigned int &q) { _quantite = q; }

void Classe::ajouter() { ++_quantite; }