//
// Created by Yannis on 01.04.20.
//

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
