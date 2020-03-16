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
    return Ig;
}
std::ostream& operator<<(std::ostream &out, const Toupie &toup) {
    out << "P: " << toup.getP() << ", P_dot: " << toup.getP_dot();
    return out;
}
void Toupie::setP(const Vecteur & P_) {
    P = P_;
}
void Toupie::setP_dot(const Vecteur & P_dot_) {
    P_dot = P_dot_;
}

std::ofstream & Toupie::imprimeFichierP(std::ofstream &out) {
    for(double i: P.getVect()) {
        out << i << " ";
    }
    out << endl;
    return out;
}
std::ofstream & Toupie::imprimeFichierP_dot(std::ofstream &out) {
    for(double i: P_dot.getVect()) {
        out << i << " ";
    }
    out << endl;
    return out;
}




