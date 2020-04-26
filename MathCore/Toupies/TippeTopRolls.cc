
#include "TippeTopRolls.h"
#include <cmath>

Vecteur5 TippeTopRolls::f(const double &t) const {
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
    return Vecteur5(((-9.81*alpha*m*R - alpha*m*pow(R,2)*pow(theta_dot,2) +
                      pow(psi_dot,2)*(I1*cosTheta +
                                       m*pow(R,2)*(alpha - cosTheta)*(-1 + alpha*cosTheta)) +
                      psi_dot*(-I3 + m*pow(R,2)*(-1 + alpha*cosTheta))*f1(theta,psi_dot,phi_dot))*
                     sinTheta)/(I1 + m*pow(R,2)*(1 + pow(alpha,2) - 2*alpha*cosTheta)),
                        f2(theta, theta_dot, psi_dot, phi_dot),
                    -(cos(theta)*f2(theta,theta_dot,psi_dot,phi_dot)) + psi_dot*theta_dot*sin(theta) -
                    (m*pow(R,2)*theta_dot*(I3*(alpha - cos(theta)) + I1*cos(theta))*
                     f1(theta,psi_dot,phi_dot)*sin(theta))/f3(theta),
                      R*(theta_dot*sinPsi - phi_dot*cosPsi*sinTheta),
                    - R*(theta_dot*cosPsi + phi_dot*sinPsi*sinTheta)
            );
}

Vecteur5 TippeTopRolls::f(const double &t, const Vecteur5 &P_, const Vecteur5 &P_dot_) const {
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
    return Vecteur5(((-9.81*alpha*m*R - alpha*m*pow(R,2)*pow(theta_dot,2) +
                      pow(psi_dot,2)*(I1*cosTheta +
                                      m*pow(R,2)*(alpha - cosTheta)*(-1 + alpha*cosTheta)) +
                      psi_dot*(-I3 + m*pow(R,2)*(-1 + alpha*cosTheta))*f1(theta,psi_dot,phi_dot))*
                     sinTheta)/(I1 + m*pow(R,2)*(1 + pow(alpha,2) - 2*alpha*cosTheta)),
                    f2(theta, theta_dot, psi_dot, phi_dot),
                    -(cos(theta)*f2(theta,theta_dot,psi_dot,phi_dot)) + psi_dot*theta_dot*sin(theta) -
                    (m*pow(R,2)*theta_dot*(I3*(alpha - cos(theta)) + I1*cos(theta))*
                     f1(theta,psi_dot,phi_dot)*sin(theta))/f3(theta),
                    R*(theta_dot*sinPsi - phi_dot*cosPsi*sinTheta),
                    - R*(theta_dot*cosPsi + phi_dot*sinPsi*sinTheta)
    );
}

double TippeTopRolls::f1(const double & th, const double & psd, const double & phd) const {
    return phd + psd * cos(th);
}
double TippeTopRolls::f2(const double & th, const double& thd, const double & psd, const double & phd) const {
    return thd/sin(th) * f1(th, psd, phd) * ((Ig.getCoord(2,2)*(Ig.getCoord(2,2)+m*R*R*(1 - alpha*cos(th))))/f3(th)) - 2*psd*thd*tan(M_PI_2 - th);
}

double TippeTopRolls::f3(const double &th) const {
    return Ig.getCoord(0,0) * Ig.getCoord(2,2) + m*R*R*Ig.getCoord(0,0)*pow(sin(th),2) + m*R*R*Ig.getCoord(2,2) * pow(alpha-cos(th),2) ;
}

void TippeTopRolls::affiche(std::ostream & out) const {
        out << "P: " << P << ", P_dot: " << P_dot;
        out << ", masse: " << m << ", Rayon:  " << R << ", h: " << h;
}

Vecteur4 TippeTopRolls::returnIndicators() const {
    /*
     * Calcul des indicateurs constants. Ici, L'énergie mécanique, Lz, et a*(w^L) sont constants. On les retourne dans le même ordre
     * que pour le cone simple:
     *       L'énergie mécanique
     *      L_A projeté sur k
     *      (L_A projeté sur a) non applicable ici, on met 0
     *      a*(w^L) (vaut toujours 0, comme pour le cone)
     */
    cosTheta = cos(P[0]);
    cosPsi = cos(P[1]);
    sinTheta = cos(P[0]);
    sinPsi = cos(P[1]);
    thetadot = P_dot[0];
    psidot = P_dot[1];
    phidot = P_dot[2];

    return Vecteur4((1.*(0.1*(2.25*pow(h,2)*m*(h - 1.*R) + (2 - 5*pow(alpha,2))*m*pow(R,2)*(h + R))*
                         pow(thetadot,2) + 9.81*m*R*(h + R)*(1 - alpha*cosTheta) -
                         0.05*m*(h - 2*R)*(3*pow(h,2) + 3*h*R + 2*pow(R,2))*
                         pow(phidot + psidot*cosTheta,2) +
                         0.1*pow(psidot,2)*(2.25*pow(h,2)*m*(h - 1.*R) +
                                            (2 - 5*pow(alpha,2))*m*pow(R,2)*(h + R))*pow(sinTheta,2) +
                         0.5*m*pow(R,2)*(h + R)*(pow(alpha,2)*pow(thetadot,2) -
                                                 2*alpha*pow(thetadot,2)*cosTheta +
                                                 pow(thetadot,2)*pow(cosTheta,2) +
                                                 (pow(phidot,2) + 2*alpha*phidot*psidot + pow(alpha,2)*pow(psidot,2) +
                                                  pow(thetadot,2))*pow(sinTheta,2))))/(h + R),
                    (0.1*(-1.*m*(h - 2*R)*(3*pow(h,2) + 3*h*R + 2*pow(R,2))*cosTheta*
                          (phidot + psidot*cosTheta) +
                          2.*(2.25*pow(h,2)*m*(h - 1.*R) + (2 - 5*pow(alpha,2))*m*pow(R,2)*(h + R))*
                          thetadot*sinPsi*sinTheta -
                          2.*psidot*(2.25*pow(h,2)*m*(h - 1.*R) +
                                     (2 - 5*pow(alpha,2))*m*pow(R,2)*(h + R))*cosPsi*pow(sinTheta,2)))/
                    (h + R),
                    0,
                    0
            );
}

QVector3D TippeTopRolls::translationModel() const {
    return QVector3D(P_dot[3],R,P_dot[4]);
}

void TippeTopRolls::addToTraces() {
    TraceA.push_front({float(P_dot[3]),0,float(P_dot[4])});
    TraceG.push_front({float(P_dot[3]-R*alpha*cos(P[1])*sin(P[0])),float(R-R*alpha*cos(P[0])),float(P_dot[4]-R*alpha*sin(P[1])*sin(P[0]))});
}
