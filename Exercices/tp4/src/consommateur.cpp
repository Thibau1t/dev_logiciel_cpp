#include "consommateur.hpp"

Consommateur::Consommateur(const unsigned int &b, const shared_pr &p)
    : _besoin(b), _shared_ptr_r(p) {}

void Consommateur::puiser()
{
    if (_shared_ptr_r)
    {
        _shared_ptr_r->consommer(_besoin);

        if (_shared_ptr_r->getStock() == 0)
            _shared_ptr_r.reset();
    }
}
