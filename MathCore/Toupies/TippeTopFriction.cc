

#include "TippeTopFriction.h"
#include <cmath>





void TippeTopFriction::affiche(std::ostream & out) const {
    out << "P: " << P << ", P_dot: " << P_dot;
    out << ", masse: " << m << ", Rayon:  " << R << ", h: " << h;
}

Vecteur5 TippeTopFriction::f(const double &t) const {
    double I1 = Ig.getCoord(0,0);
    double sinTheta = sin(P.getCoord(0));
    double sinPsi = sin(P.getCoord(1));
    double cosTheta = cos(P.getCoord(0));
    double cosPsi = cos(P.getCoord(1));
    double theta = P.getCoord(0);
    double theta_dot = P_dot.getCoord(0);
    double psi_dot = P_dot.getCoord(1);
    double phi_dot = P_dot.getCoord(2);
    double I3 = Ig.getCoord(2,2);
    double vx = P_dot.getCoord(3);
    double vy = P_dot.getCoord(4);
    return Vecteur5(
            (mu*R*vx*(1 - alpha*cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                                                 I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
            (I1*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))) +
            (sinTheta*(I1*pow(psi_dot,2)*cosTheta - I3*psi_dot*(phi_dot + psi_dot*cosTheta) -
                         (alpha*R*(9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                                       I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                         (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,

            (1/sinTheta*(-2*I1*psi_dot*theta_dot*cosTheta + I3*theta_dot*(phi_dot + psi_dot*cosTheta) -
                         (mu*R*vy*(alpha - cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                                                            I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                         (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,

            (alpha*I3*m*mu*psi_dot*pow(R,2)*pow(cosTheta,3)*(alpha*(2*I1 - I3)*theta_dot*vx - (I1 - I3)*psi_dot*vy*sinTheta) +
             (alpha*I3*m*pow(R,2)*cosTheta*tan(M_PI_2-theta)*(-2*I1*mu*pow(theta_dot,2)*vy*cosTheta +
                                                           2*sinTheta*(mu*(-(alpha*I3*phi_dot) + (-2*I1 + I3)*psi_dot)*theta_dot*vx +
                                                                         psi_dot*(I3*mu*phi_dot*vy - alpha*I3*(theta_dot + mu*psi_dot*vy) + alpha*I1*(2*theta_dot + mu*psi_dot*vy))*sinTheta)))/2. +
             I1*(-(I3*(I3*phi_dot*theta_dot - alpha*9.81*m*mu*R*vy)*tan(M_PI_2-theta)) +
                 sinTheta*(I1*(I3*psi_dot*theta_dot - 9.81*m*mu*R*vy) - alpha*I3*m*mu*psi_dot*pow(R,2)*theta_dot*vx*sinTheta +
                             alpha*I3*m*psi_dot*pow(R,2)*(alpha*theta_dot + mu*phi_dot*vy)*pow(sinTheta,2))) +
             cosTheta*(I1*I3*(2*I1*psi_dot*theta_dot - I3*psi_dot*theta_dot + m*mu*R*(-9.81 + pow(alpha,2)*R*pow(theta_dot,2))*vy)*tan(M_PI_2-theta) -
                         alpha*m*pow(R,2)*(-(pow(I3,2)*mu*phi_dot*theta_dot*vx) +
                                             (pow(I1,2)*mu*pow(theta_dot,2)*vy + alpha*pow(I3,2)*phi_dot*(theta_dot + mu*psi_dot*vy))*sinTheta -
                                             alpha*I1*I3*mu*psi_dot*theta_dot*vx*pow(sinTheta,2) + I1*(I1 - I3)*mu*pow(psi_dot,2)*vy*pow(sinTheta,3))))/
            (I1*I3*(I1 + alpha*m*mu*pow(R,2)*vx*(-1 + alpha*cosTheta)*sinTheta + pow(alpha,2)*m*pow(R,2)*pow(sinTheta,2))),

            psi_dot*vy - (mu*vx*(I1 + m*pow(R,2)*pow(-1 + alpha*cosTheta,2))*
                         (9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                              I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                        (I1*m*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))) +
            (R*sinTheta*(-(psi_dot*(I1 - I3 + alpha*I3*cosTheta)*(phi_dot + psi_dot*cosTheta)) -
                           alpha*I1*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)) +
                           (alpha*R*(1 - alpha*cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                                                                I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                           (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,

            -(psi_dot*vx) + (R*theta_dot*(alpha*I3 + (I1 - I3)*cosTheta)*(phi_dot + psi_dot*cosTheta))/I1 -
            (mu*vy*(I1*I3 + I3*m*pow(R,2)*pow(alpha - cosTheta,2) + I1*m*pow(R,2)*pow(sinTheta,2))*
             (9.81*I1*m + alpha*m*R*(-(I3*psi_dot*(phi_dot + psi_dot*cosTheta)*pow(sinTheta,2)) +
                                  I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
            (I1*I3*m*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta)))
            );
}

Vecteur5 TippeTopFriction::f(const double &t, const Vecteur5 &P_, const Vecteur5 &P_dot_) const {
    double I1 = Ig.getCoord(0,0);
    double sinTheta = sin(P_.getCoord(0));
    double sinPsi = sin(P_.getCoord(1));
    double cosTheta = cos(P_.getCoord(0));
    double cosPsi = cos(P_.getCoord(1));
    double theta = P_.getCoord(0);
    double theta_dot = P_dot_.getCoord(0);
    double psi_dot = P_dot_.getCoord(1);
    double phi_dot = P_dot_.getCoord(2);
    double I3 = Ig.getCoord(2,2);
    double vx = P_dot_.getCoord(3);
    double vy = P_dot_.getCoord(4);
    return Vecteur5(
            (mu*R*vx*(1 - alpha*cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) +
                                                                  I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
            (I1*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))) +
            (sinTheta*(-(I3*phi_dot*psi_dot) + I1*pow(psi_dot,2)*cosTheta -
                       (alpha*R*(9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) +
                                                        I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                       (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,

            (1/sinTheta*(I3*phi_dot*theta_dot - 2*I1*psi_dot*theta_dot*cosTheta -
                         (mu*R*vy*(alpha - cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) +
                                                                             I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                         (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,
            -((mu*R*vy*sinTheta*(9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) +
                                                        I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
              (I3*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta)))),

            psi_dot*vy - (mu*vx*(I1 + m*pow(R,2)*pow(-1 + alpha*cosTheta,2))*
                          (9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) + I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                         (I1*m*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))) +
            (R*sinTheta*(-(phi_dot*psi_dot*(I1 - I3 + alpha*I3*cosTheta)) - alpha*I1*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)) +
                         (alpha*R*(1 - alpha*cosTheta)*(9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) +
                                                                               I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
                         (I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta))))/I1,

            -(psi_dot*vx) + (phi_dot*R*theta_dot*(alpha*I3 + (I1 - I3)*cosTheta))/I1 -
            (mu*vy*(I1*I3 + I3*m*pow(R,2)*pow(alpha - cosTheta,2) + I1*m*pow(R,2)*pow(sinTheta,2))*
             (9.81*I1*m + alpha*m*R*(-(I3*phi_dot*psi_dot*pow(sinTheta,2)) + I1*cosTheta*(pow(theta_dot,2) + pow(psi_dot,2)*pow(sinTheta,2)))))/
            (I1*I3*m*(I1 + alpha*m*pow(R,2)*sinTheta*(-(mu*vx) + alpha*mu*vx*cosTheta + alpha*sinTheta)))
    );
}
