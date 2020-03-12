//
// Created by Yannis on 06.03.20.
//

#include "ConeSimple.h"
#include <iostream>

void operator<<(std::ostream& out, const ConeSimple & cone) {
    out << "P: " << cone.getP() << ", P_dot: " << cone.getP_dot(); // TODO: A corriger peutêtre, copié collé
    out << ", masse: " << cone.m << ", Longueur:  " << cone.L << ", Rayon" << cone.R;
}
