//
// Created by Yannis on 06.03.20.
//

#include "Toupie.h"
#include <iostream>
using namespace std;

Matrice Toupie::getIg() const {
    return Ig;
}

std::string Toupie::getType() const {
    return type;
}
void Toupie::afficheSimple(std::ostream & out) const {
    out << "P: " << P << ", P_dot: " << P_dot;
}

void Toupie::afficheFile(std::ostream & out) const { //TODO: ofstream& ?
    for(double i: P.v()) {
        out << i << " ";
    }
    for(double i: P_dot.v()) {
        out << i << " ";
    }

}




