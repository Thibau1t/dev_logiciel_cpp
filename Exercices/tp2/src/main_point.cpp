#include <cstdlib>


#include <vector>

#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

int main() {
    Polaire p0 = Polaire(0,0);
    Polaire p1 = Polaire(1,1);
    Polaire p2 = Polaire(2,2);
    Polaire p3 = Polaire(3,3);
    Polaire p4 = Polaire(4,4);
    Polaire p5 = Polaire(5,5);

    Cartesien c0 = Cartesien(0,0);
    Cartesien c1 = Cartesien(1,1);
    Cartesien c2 = Cartesien(2,2);
    Cartesien c3 = Cartesien(3,3);
    Cartesien c4 = Cartesien(4,4);
    Cartesien c5 = Cartesien(5,5);

    // std::vector<Point > points; ==> ne fonctionne pas car Point est abstraite
    std::vector<Point *> points;

    points.push_back(&p0);
    points.push_back(&p1);
    points.push_back(&p2);
    points.push_back(&p3);
    points.push_back(&p4);
    points.push_back(&p5);

    points.push_back(&c0);
    points.push_back(&c1);
    points.push_back(&c2);
    points.push_back(&c3);
    points.push_back(&c4);
    points.push_back(&c5);
    

    for(const auto&  point : points){
        point->afficher(std::cout);
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
