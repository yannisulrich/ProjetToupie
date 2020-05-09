//
// Created by Yannis on 06.03.20.
//

#include "Toupie.h"
#include <iostream>
using namespace std;

Matrice Toupie::getIg() const {
    return Ig;
}

void Toupie::afficheSimple(std::ostream & out) const {
    out << "P: " << P << ", P_dot: " << P_dot << ", E,LAk, LAa, a*(w^L)" << returnIndicators();
}

void Toupie::afficheFile(std::ostream & out) const {
    for(double i: P.v()) {
        out << i << " ";
    }
    for(double i: P_dot.v()) {
        out << i << " ";
    }
    for(double i: returnIndicators().v()) {
        out << i << " ";
    }

}




