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

Vecteur4 ConeSimple::returnIndicators() const {
    /*
     * On rend ici sous forme de Vecteur4 les quatres indicateurs constants suivants:
     *      L'énergie mécanique
     *      L_A projeté sur k
     *      L_A projeté sur a
     *      a*(w^L)
     *      Ce dernier vaut automatiquement 0 pour cette toupie quelque soient les angles, indépendemment de l'approximation numérique.
     */
    cosTheta = cos(P[0]);
    cosPsi = cos(P[1]);
    sinTheta = cos(P[0]);
    sinPsi = cos(P[1]);
    thetadot = P_dot[0];
    psidot = P_dot[1];
    phidot = P_dot[2];
    return Vecteur4(0.75*L*9.81*m*cosTheta + 0.5*((3*m*(2*pow(L,2) + pow(R,2)/2.)*pow(thetadot,2))/10. +
                                            (3*m*pow(R,2)*pow(phidot + psidot*cosTheta,2))/5. +
                                            (3*m*pow(psidot,2)*(2*pow(L,2) + pow(R,2)/2.)*pow(sinTheta,2))/10.),
                    (3*m*pow(R,2)*cosTheta*(phidot + psidot*cosTheta))/5. +
                    (3*m*(2*pow(L,2) + pow(R,2)/2.)*thetadot*sinPsi*sinTheta)/10. -
                    (3*m*psidot*(2*pow(L,2) + pow(R,2)/2.)*cosPsi*pow(sinTheta,2))/10.,
                    0.015*(phidot + psidot*cosTheta),
                    0
                    );
}

QVector3D ConeSimple::translationModel() const {
    return QVector3D(P[3],0,P[4]);
}

void ConeSimple::addToTraces() {
    TraceA.push_front({float(P[3]),0,float(P[4])});
    TraceG.push_front({float(cos(P[1])*sin(P[0])),float(0.75*L*cos(P[0])),float(sin(P[1])*sin(P[0]))});
}
