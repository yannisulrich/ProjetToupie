

#include "ConeSymFixe.h"
#include <cmath>

Vecteur5 ConeSymFixe::f(const double & t) const {
    double IA1 = Ig.getCoord(0,0) + m*0.5625*L*L;
    double sinTheta = sin(P.getCoord(0));
    double cosTheta = cos(P.getCoord(0));
    double theta_dot = P_dot.getCoord(0);
    double psi_dot = P_dot.getCoord(1);
    double phi_dot = P_dot.getCoord(2);
    double I3 = Ig.getCoord(2,2);

    return Vecteur5(sinTheta/(IA1) * (9.81*0.75*m*L + psi_dot*((IA1 - I3)*psi_dot*cosTheta - I3*phi_dot)),
                    theta_dot/(IA1*sinTheta) * ((I3-2*IA1)*psi_dot*cosTheta + I3*phi_dot),
                    theta_dot/(IA1*sinTheta) * ((IA1 - (I3-IA1)*cosTheta*cosTheta)*psi_dot - I3*phi_dot*cosTheta),
                    0,
                    0
    );
}
Vecteur5 ConeSymFixe::f(const double & t, const Vecteur5& P_, const Vecteur5& P_dot_) const {
    double IA1 = Ig.getCoord(0,0) + m*0.5625*L*L;
    double sinTheta = sin(P_.getCoord(0));
    double cosTheta = cos(P_.getCoord(0));
    double theta_dot = P_dot_.getCoord(0);
    double psi_dot = P_dot_.getCoord(1);
    double phi_dot = P_dot_.getCoord(2);
    double I3 = Ig.getCoord(2,2);
    return Vecteur5(sinTheta/(IA1) * (9.81*0.75*m*L + psi_dot*((IA1 - I3)*psi_dot*cosTheta - I3*phi_dot)),
                    theta_dot/(IA1*sinTheta) * ((I3-2*IA1)*psi_dot*cosTheta + I3*phi_dot),
                    theta_dot/(IA1*sinTheta) * ((IA1 - (I3-IA1)*cosTheta*cosTheta)*psi_dot - I3*phi_dot*cosTheta),
                    0,
                    0
    );
}
Vecteur4 ConeSymFixe::returnIndicators() const {
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
    sinTheta = sin(P[0]);
    sinPsi = sin(P[1]);
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
