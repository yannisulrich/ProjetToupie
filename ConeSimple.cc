//
// Created by Yannis on 06.03.20.
//

#include "ConeSimple.h"
#include <iostream>
#include <iomanip>

std::ostream& operator<<(std::ostream& out, const ConeSimple & cone) {
    //out << Toupie(cone);
    out << "P: " << std::setw(10) << cone.getP() << ", P_dot: " << cone.getP_dot(); // TODO: Lequel est meilleur?
    out << ", masse: " << cone.m << ", Longueur:  " << cone.L << ", Rayon: " << cone.R;
    return out;
}
