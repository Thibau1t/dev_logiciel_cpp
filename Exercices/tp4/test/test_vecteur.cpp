// Entetes //---------------------------------------------------------------------------------------
#include <algorithm>
#include <deque>
#include <vecteur.hpp>

/*
Avant
❯ ./tp4_vecteur
[0] affectations = 0 ; constructions = 0 ; copies = 0 ; mouvements = 0

v1 = (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0)
v2 = (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0) (0;0)
[1] affectations = 0 ; constructions = 20 ; copies = 0 ; mouvements = 0

v1 = (0;0) (10;1) (20;4) (30;9) (40;16) (50;25) (60;36) (70;49) (80;64) (90;81)
v2 = (0;1) (1;2) (2;3) (3;4) (4;5) (5;6) (6;7) (7;8) (8;9) (9;10)
[2] affectations = 20 ; constructions = 40 ; copies = 0 ; mouvements = 20

v3 = (0;0) (10;1) (20;4) (30;9) (40;16) (50;25) (60;36) (70;49) (80;64) (90;81)
[3] affectations = 30 ; constructions = 50 ; copies = 10 ; mouvements = 20

v4 = (0;1) (11;3) (22;7) (33;13) (44;21) (55;31) (66;43) (77;57) (88;73) (99;91)
[4] affectations = 50 ; constructions = 80 ; copies = 20 ; mouvements = 30

v5 = (0;0) (115;62) (440;296) (927;834) (1504;1808) (2075;3350) (2520;5592) (2695;8666) (2432;12704) (1539;17838)
[5] affectations = 80 ; constructions = 130 ; copies = 30 ; mouvements = 50

liste = v5
[6] affectations = 80 ; constructions = 140 ; copies = 40 ; mouvements = 50

(0;0) (115;62) (440;296) (927;834) (1504;1808) (1539;17838) (2075;3350) (2432;12704) (2520;5592) (2695;8666)
[7] affectations = 95 ; constructions = 149 ; copies = 40 ; mouvements = 74
*/

// Fonction principale //---------------------------------------------------------------------------
int main(void)
{
    complexe_t::stats();
    // affectation  : 0
    // construction : 0
    // copie        : 0
    // mouvement    : 0

    Vecteur v1;
    Vecteur v2;

    std::cout << std::endl
              << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    complexe_t::stats();
    // affectation  : 0
    // construction : 2*10=20
    // copie        : 0
    // mouvement    : 0

    for (unsigned i = 0; i < v1.getTaille(); ++i)
        v1[i] = complexe_t(10 * i, i * i);
    for (unsigned i = 0; i < v2.getTaille(); ++i)
        v2[i] = complexe_t(i, i + 1);

    std::cout << std::endl
              << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    complexe_t::stats();
    // affectation  : 20
    // construction : 2*10+2*10=40
    // copie        : 0
    // mouvement    : 20

    Vecteur v3 = v1;

    std::cout << std::endl
              << "v3 = " << v3 << std::endl;
    complexe_t::stats();
    // affectation  : 20+10=30
    // construction : 2*10+10+10=50
    // copie        : 10=10
    // mouvement    : 20

    Vecteur v4;

    v4 = v1 + v2;

    std::cout << std::endl
              << "v4 = " << v4 << std::endl;
    complexe_t::stats();
    // affectation  : 20+10=30
    // construction : 2*10+10+10+10+20=80
    // copie        : 10=10
    // mouvement    : 20

    Vecteur v5;

    v5 = v1 * (v2 + v4);

    std::cout << std::endl
              << "v5 = " << v5 << std::endl;
    complexe_t::stats();

    std::deque<complexe_t> liste;

    for (unsigned i = 0; i < v5.getTaille(); ++i)
        liste.push_back(v5[i]);

    std::cout << std::endl
              << "liste = v5" << std::endl;
    complexe_t::stats();

    std::sort(liste.begin(), liste.end(), ComparateurComplexe());

    std::cout << std::endl;
    for (unsigned i = 0; i < liste.size(); ++i)
        std::cout << liste[i] << " ";
    std::cout << std::endl;
    complexe_t::stats();
}

// Fin //-------------------------------------------------------------------------------------------
