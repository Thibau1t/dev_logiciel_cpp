// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <complexe.hpp>

// complexe_t = Mouchard<Complexe>

// Fonction principale //---------------------------------------------------------------------------
int main(void)
{
    complexe_t::stats();

    std::cout << std::endl
              << "complexe_t c1(1,2);" << std::endl;
    complexe_t c1(1, 2);
    complexe_t::stats();
    // affectation  :
    // construction : 1
    // copie        :
    // mouvement    :

    std::cout << std::endl
              << "complexe_t c2(3,4);" << std::endl;
    complexe_t c2(3, 4);
    complexe_t::stats();
    // affectation  :
    // construction : 1+1=2
    // copie        :
    // mouvement    :

    std::cout << std::endl
              << "complexe_t c3(c1);" << std::endl;
    complexe_t c3(c1);
    complexe_t::stats();
    // affectation  :
    // construction : 1+1+1=3
    // copie        : 1
    // mouvement    :

    std::cout << std::endl
              << "complexe_t c4(std::move(c2));" << std::endl;
    complexe_t c4(std::move(c2));
    complexe_t::stats();
    // affectation  :
    // construction : 1+1+1+1=4
    // copie        : 1
    // mouvement    : 1

    std::cout << std::endl
              << "c3=c1;" << std::endl;
    c3 = c1;
    complexe_t::stats();
    // affectation  : 1
    // construction : 1+1+1+1=4
    // copie        : 1+1=2
    // mouvement    : 1

    std::cout << std::endl
              << "c4=complexe_t(5,6);" << std::endl;
    c4 = complexe_t(5, 6);
    complexe_t::stats();
    // affectation  : 1+1=2
    // construction : 1+1+1+1+1=5
    // copie        : 1+1=2
    // mouvement    : 1+1=2

    return 0;
}

// Fin //-------------------------------------------------------------------------------------------
