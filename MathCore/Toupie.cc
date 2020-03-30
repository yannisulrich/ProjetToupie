//
// Created by Yannis on 06.03.20.
//

#include "Toupie.h"
#include <iostream>
using namespace std;
Vecteur5 Toupie::f(const double & t,const Vecteur5& P_, const Vecteur5& P_dot_) const {
    return f_(t, P_, P_dot_);
}
Vecteur5 Toupie::f(const double & t) const {
    return f_(t, P, P_dot);
}
Vecteur5 Toupie::getP() const {
    return P;
}

Vecteur5 Toupie::getP_dot() const {
    return P_dot;
}

Matrice Toupie::getI() const {
    return Ig;
}
void Toupie::setP(const Vecteur5 & P_) {
    P = P_;
}
void Toupie::setP_dot(const Vecteur5 & P_dot_) {
    P_dot = P_dot_;
}
/* TODO: clean up
std::ofstream & Toupie::imprimeFichierP(std::ofstream &out) {
    for(double i: P.v()) {
        out << i << " ";
    }
    out << endl;
    return out;
}
std::ofstream & Toupie::imprimeFichierP_dot(std::ofstream &out) {
    for(double i: P_dot.v()) {
        out << i << " ";
    }
    out << endl;
    return out;
}
*/
std::string Toupie::getType() const {
    return type;
}




