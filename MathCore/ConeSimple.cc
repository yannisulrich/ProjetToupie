//
// Created by Yannis on 06.03.20.
//

#include "ConeSimple.h"
#include <iostream>
#include <iomanip>

double ConeSimple::getL() const {
    return L;
}
double ConeSimple::getR() const {
    return R;
}
double ConeSimple::getM() const {
    return m;
}

void ConeSimple::affiche(std::ostream & out) const {
    out << "P: " << std::setw(10) << P << ", P_dot: " << P_dot;
    out << ", masse: " << m << ", Longueur:  " << L << ", Rayon: " << R;
}
