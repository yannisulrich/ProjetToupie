//
// Created by Yannis on 06.03.20.
//

#include "Toupie.h"
#include <iostream>
using namespace std;
Vecteur Toupie::f() const {
    return -P;
}
Vecteur Toupie::getP() const {
    return P;
}

Vecteur Toupie::getP_dot() const {
    return P_dot;
}

Matrice Toupie::getI() const {
    return I;
}

ostream& operator<<(ostream &out, const Toupie &toup) {
    out << "P: " << toup.getP() << "P_dot: " << toup.getP_dot();
    return out;
}


