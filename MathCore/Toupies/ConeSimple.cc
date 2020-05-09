//
// Created by Yannis on 06.03.20.
//

#include "ConeSimple.h"
#include <iostream>
#include <cmath>

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
    out << "P: " << P << ", P_dot: " << P_dot;
    out << ", masse: " << m << ", Longueur:  " << L << ", Rayon: " << R;
}



QVector3D ConeSimple::translationModel() const {
    return QVector3D(P[3],0,P[4]);
}

void ConeSimple::addToTraces() {
    TraceA.push_front({float(P[3]),0.0001,float(P[4])}); //0.0001 sert a rendre la trace visible, et doit être ignoré physiquement
    TraceG.push_front({float(0.75*L*sin(P[1])*sin(P[0])+P[3]),float(0.75*L*cos(P[0])),float(0.75*L*cos(P[1])*sin(P[0])+P[4])});

}
