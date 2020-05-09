
#include "ConeSymGlisse.h"
void ConeSymGlisse::affiche(std::ostream & out) const {
    out << "P: " << P << ", P_dot: " << P_dot;
    out << ", masse: " << m << ", Rayon:  " << r << ", L3: " << L3;
}
void ConeSymGlisse::accels(double t, double *p, double *pdot, void *data) {
    double theta, psi, phi, x, y, thetadot, psidot, phidot, xdot, ydot;
    double sinTheta, cosTheta, cotTheta, sinPhi, cosPhi, sinPsi, cosPsi;

    auto * constants = static_cast<double*>(data);
    double m = *constants;
    double muk = *(constants+1);
    double L3 = *(constants+2);
    double lambdaa = *(constants+3);
    double lambdat = *(constants+4);
    theta = p[0];





    pdot[0] = p[5];
    pdot[1] = p[6];
    pdot[2] = p[7];
    pdot[3] = p[8];
    pdot[4] = p[9];


    psi = p[1];
    phi = p[2];
    x = p[3];
    y = p[4];

    thetadot = p[5];
    psidot = p[6];
    phidot = p[7];
    xdot = p[8];
    ydot = p[9];

    sinTheta = sin(theta);
    sinPsi = sin(psi);
    sinPhi = sin(phi);

    cosTheta = cos(theta);
    cosPsi = cos(psi);
    cosPhi = cos(phi);

    cotTheta = tan(M_PI_2 - theta);

    pdot[5] = (-981.*L3*m*muk*ydot*cosPsi*cosTheta + 100*pow(L3,2)*m*muk*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,2) -
               981.*pow(L3,2)*m*muk*thetadot*pow(cosPsi,2)*pow(cosTheta,2) + 100*pow(L3,3)*m*muk*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,3) +
               981.*L3*m*muk*xdot*cosTheta*sinPsi - 100*pow(L3,2)*m*muk*pow(thetadot,2)*xdot*pow(cosTheta,2)*sinPsi -
               981.*pow(L3,2)*m*muk*thetadot*pow(cosTheta,2)*pow(sinPsi,2) + 100*pow(L3,3)*m*muk*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2) +
               9.81*L3*m*sinTheta - lambdaa*phidot*psidot*sinTheta + 981.*L3*m*sinTheta*
                                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
  pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
               100*lambdaa*phidot*psidot*sinTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
               100*lambdaa*pow(psidot,2)*cosTheta*sinTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                            pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
               100*lambdat*pow(psidot,2)*cosTheta*sinTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                            pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
               100*pow(L3,2)*m*pow(thetadot,2)*cosTheta*sinTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                  pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) - (lambdaa*pow(psidot,2)*sin(2*theta))/2. +
               (lambdat*pow(psidot,2)*sin(2*theta))/2. - (pow(L3,2)*m*pow(thetadot,2)*sin(2*theta))/2.)/
              (lambdat - 100*pow(L3,2)*m*muk*ydot*cosPsi*cosTheta*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta +
               100*pow(L3,2)*m*muk*xdot*cosTheta*sinPsi*sinTheta + pow(L3,2)*m*pow(sinTheta,2) +
               100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta*(-1 + pow(sinTheta,2)) +
               100*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
               100*pow(L3,2)*m*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)));

    pdot[6] = -((-10000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2) + 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*pow(cosPsi,3) -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*pow(cosPsi,3) - 10000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*cosTheta +
                 20000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*cosTheta -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*pow(cosPsi,3)*cosTheta +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*pow(cosPsi,3)*cosTheta -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*cosTheta +
                 20000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta - 40000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta +
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosPsi,2)*cotTheta - 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosPsi,2)*cotTheta -
                 100*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta +
                 1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*cotTheta +
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosPsi,2)*cotTheta -
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosPsi,2)*cotTheta +
                 2000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*pow(cosPsi,2)*cotTheta +
                 9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*pow(cosPsi,2)*cosTheta*cotTheta -
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*pow(cosPsi,2)*cosTheta*cotTheta -
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,2)*cotTheta +
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,2)*cotTheta -
                 1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*cotTheta -
                 1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*pow(cotTheta,2) +
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*pow(cotTheta,2) -
                 20000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2) +
                 40000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2) -
                 10000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,2) -
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cotTheta,2) +
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cotTheta,2) -
                 2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*xdot*ydot*pow(cosPsi,2)*pow(cotTheta,2) +
                 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cotTheta,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cotTheta,2) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*pow(cosPsi,3)*pow(cotTheta,2) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,4)*pow(cotTheta,2) +
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*cosTheta*pow(cotTheta,2) -
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*cosTheta*pow(cotTheta,2) +
                 2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*cosTheta*pow(cotTheta,2) -
                 10000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2) +
                 20000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*cosTheta*pow(cotTheta,2) +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*cosTheta*pow(cotTheta,2) -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*xdot*pow(cosPsi,3)*cosTheta*pow(cotTheta,2) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,4)*cosTheta*pow(cotTheta,2) -
                 1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cotTheta,3) +
                 1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cotTheta,3) -
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*pow(cotTheta,3) -
                 1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cotTheta,3) +
                 1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cotTheta,3) -
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*pow(cotTheta,3) +
                 1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,3) -
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*ydot*cosPsi*pow(cotTheta,3) +
                 100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3) -
                 200*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3) +
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3) -
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3) +
                 1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosPsi,2)*pow(cotTheta,3) -
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*cosTheta*pow(cotTheta,3) +
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*cosTheta*pow(cotTheta,3) -
                 2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*ydot*cosPsi*cosTheta*pow(cotTheta,3) +
                 9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cosTheta*pow(cotTheta,3) -
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosPsi,2)*cosTheta*pow(cotTheta,3) -
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(cotTheta,3) +
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(cotTheta,3) -
                 1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosPsi,2)*pow(cosTheta,2)*pow(cotTheta,3) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,4) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,4) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,4) +
                 20000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*xdot*cosPsi*(1/sinTheta) + 981.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*(1/sinTheta) -
                 9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*pow(cosPsi,2)*(1/sinTheta) +
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*pow(cosPsi,2)*(1/sinTheta) -
                 1.962e7*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*pow(cosPsi,2)*(1/sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*pow(cosPsi,2)*(1/sinTheta) - pow(L3,2)*lambdaa*m*psidot*thetadot*cotTheta*(1/sinTheta) +
                 2*pow(L3,2)*lambdat*m*psidot*thetadot*cotTheta*(1/sinTheta) - 10000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(xdot,2)*cotTheta*(1/sinTheta) +
                 20000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*cotTheta*(1/sinTheta) - 10000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(ydot,2)*cotTheta*(1/sinTheta) +
                 20000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*cotTheta*(1/sinTheta) -
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*cotTheta*(1/sinTheta) +
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*cotTheta*(1/sinTheta) +
                 100*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*(1/sinTheta) -
                 2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*cotTheta*(1/sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(xdot,3)*cosPsi*cotTheta*(1/sinTheta) +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(xdot,3)*cosPsi*cotTheta*(1/sinTheta) -
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(xdot,3)*cosPsi*cotTheta*(1/sinTheta) -
                 20000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*ydot*cosPsi*cotTheta*(1/sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*pow(ydot,2)*cosPsi*cotTheta*(1/sinTheta) +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*pow(ydot,2)*cosPsi*cotTheta*(1/sinTheta) -
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*pow(ydot,2)*cosPsi*cotTheta*(1/sinTheta) -
                 10000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosPsi,2)*cotTheta*(1/sinTheta) +
                 20000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*cotTheta*(1/sinTheta) +
                 1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*xdot*ydot*pow(cosPsi,2)*cotTheta*(1/sinTheta) -
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*xdot*ydot*pow(cosPsi,2)*cotTheta*(1/sinTheta) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*pow(cosPsi,3)*cotTheta*(1/sinTheta) +
                 981.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cotTheta,2)*(1/sinTheta) - 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(cotTheta,2)*(1/sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*pow(cotTheta,2)*(1/sinTheta) -
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*pow(cotTheta,2)*(1/sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*pow(cotTheta,2)*(1/sinTheta) -
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*pow(cotTheta,2)*(1/sinTheta) +
                 100*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta) -
                 200*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta) +
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta) -
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta) +
                 2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta) +
                 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta) -
                 9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta) +
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cotTheta,3)*(1/sinTheta) -
                 10000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta) +
                 20000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta) -
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta) -
                 pow(L3,2)*lambdaa*m*phidot*thetadot*pow((1/sinTheta),2) - 10000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(xdot,2)*pow((1/sinTheta),2) -
                 10000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(ydot,2)*pow((1/sinTheta),2) - 100*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*cosPsi*pow((1/sinTheta),2) +
                 1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*pow((1/sinTheta),2) -
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*pow((1/sinTheta),2) +
                 9.81e6*pow(L3,3)*pow(m,2)*muk*pow(xdot,3)*cosPsi*pow((1/sinTheta),2) -
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(xdot,3)*cosPsi*pow((1/sinTheta),2) +
                 9.81e6*pow(L3,3)*pow(m,2)*muk*xdot*pow(ydot,2)*cosPsi*pow((1/sinTheta),2) -
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*pow(ydot,2)*cosPsi*pow((1/sinTheta),2) -
                 10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*pow((1/sinTheta),2) +
                 1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*cotTheta*pow((1/sinTheta),2) -
                 1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*cotTheta*pow((1/sinTheta),2) +
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*cotTheta*pow((1/sinTheta),2) +
                 1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*cotTheta*pow((1/sinTheta),2) -
                 1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*cotTheta*pow((1/sinTheta),2) +
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*cotTheta*pow((1/sinTheta),2) +
                 20000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*pow((1/sinTheta),2) -
                 40000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*pow((1/sinTheta),2) +
                 100*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2) -
                 1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2) +
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2) -
                 100*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2) -
                 20000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) +
                 40000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) +
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) -
                 10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) -
                 981.*pow(L3,4)*pow(m,2)*muk*psidot*pow((1/sinTheta),3) + 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow((1/sinTheta),3) -
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*pow((1/sinTheta),3) +
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*pow((1/sinTheta),3) -
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*pow((1/sinTheta),3) +
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*pow((1/sinTheta),3) +
                 20000*L3*lambdaa*lambdat*phidot*psidot*thetadot*xdot*cosPsi*pow((1/sinTheta),3) + 981.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*pow((1/sinTheta),3) -
                 lambdaa*lambdat*psidot*thetadot*cotTheta*pow((1/sinTheta),3) + 2*pow(lambdat,2)*psidot*thetadot*cotTheta*pow((1/sinTheta),3) -
                 10000*lambdaa*lambdat*psidot*thetadot*pow(xdot,2)*cotTheta*pow((1/sinTheta),3) +
                 20000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*cotTheta*pow((1/sinTheta),3) -
                 10000*lambdaa*lambdat*psidot*thetadot*pow(ydot,2)*cotTheta*pow((1/sinTheta),3) +
                 20000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*cotTheta*pow((1/sinTheta),3) +
                 100*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),3) +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*cotTheta*pow((1/sinTheta),3) -
                 20000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*ydot*cosPsi*cotTheta*pow((1/sinTheta),3) - lambdaa*lambdat*phidot*thetadot*pow((1/sinTheta),4) -
                 10000*lambdaa*lambdat*phidot*thetadot*pow(xdot,2)*pow((1/sinTheta),4) - 10000*lambdaa*lambdat*phidot*thetadot*pow(ydot,2)*pow((1/sinTheta),4) -
                 981.*L3*lambdat*m*muk*xdot*cosPsi*pow((1/sinTheta),4) + 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow(cosPsi,2)*sinPsi -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow(cosPsi,2)*sinPsi -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*pow(cosPsi,2)*cosTheta*sinPsi +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*pow(cosPsi,2)*cosTheta*sinPsi -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*cosTheta*sinPsi +
                 20000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*ydot*cotTheta*sinPsi - 40000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*cotTheta*sinPsi +
                 4000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*xdot*ydot*cosPsi*cotTheta*sinPsi -
                 4000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*xdot*ydot*cosPsi*cotTheta*sinPsi +
                 4000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*xdot*ydot*cosPsi*cotTheta*sinPsi +
                 20000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*sinPsi -
                 40000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*sinPsi -
                 1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*pow(xdot,2)*cosPsi*pow(cotTheta,2)*sinPsi -
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*pow(xdot,2)*cosPsi*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*pow(xdot,2)*cosPsi*pow(cotTheta,2)*sinPsi -
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*pow(ydot,2)*cosPsi*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*pow(ydot,2)*cosPsi*pow(cotTheta,2)*sinPsi -
                 2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*pow(ydot,2)*cosPsi*pow(cotTheta,2)*sinPsi -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosPsi,2)*pow(cotTheta,2)*sinPsi +
                 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cotTheta,2)*sinPsi -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*cosTheta*pow(cotTheta,2)*sinPsi -
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*cosTheta*pow(cotTheta,2)*sinPsi +
                 2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*cosTheta*pow(cotTheta,2)*sinPsi -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*sinPsi +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*sinPsi -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*ydot*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*sinPsi -
                 1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*xdot*pow(cotTheta,3)*sinPsi +
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*xdot*pow(cotTheta,3)*sinPsi +
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*xdot*cosTheta*pow(cotTheta,3)*sinPsi -
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*xdot*cosTheta*pow(cotTheta,3)*sinPsi +
                 2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*xdot*cosTheta*pow(cotTheta,3)*sinPsi -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,4)*sinPsi +
                 20000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*ydot*(1/sinTheta)*sinPsi - 3.924e7*pow(L3,4)*pow(m,2)*muk*psidot*xdot*ydot*cosPsi*(1/sinTheta)*sinPsi +
                 4000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*xdot*ydot*cosPsi*(1/sinTheta)*sinPsi +
                 20000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*xdot*cotTheta*(1/sinTheta)*sinPsi -
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*cotTheta*(1/sinTheta)*sinPsi +
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*cotTheta*(1/sinTheta)*sinPsi +
                 100*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi -
                 2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi -
                 1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(xdot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(xdot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi -
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(xdot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi -
                 1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(ydot,3)*cotTheta*(1/sinTheta)*sinPsi +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(ydot,3)*cotTheta*(1/sinTheta)*sinPsi -
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(ydot,3)*cotTheta*(1/sinTheta)*sinPsi -
                 1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*pow(xdot,2)*cosPsi*cotTheta*(1/sinTheta)*sinPsi +
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*pow(xdot,2)*cosPsi*cotTheta*(1/sinTheta)*sinPsi +
                 1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*pow(ydot,2)*cosPsi*cotTheta*(1/sinTheta)*sinPsi -
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*pow(ydot,2)*cosPsi*cotTheta*(1/sinTheta)*sinPsi +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosPsi,2)*cotTheta*(1/sinTheta)*sinPsi -
                 100*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                 200*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi -
                 2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                 2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi -
                 2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cotTheta,3)*(1/sinTheta)*sinPsi -
                 100*pow(L3,2)*lambdaa*m*muk*phidot*psidot*ydot*pow((1/sinTheta),2)*sinPsi +
                 1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow((1/sinTheta),2)*sinPsi -
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow((1/sinTheta),2)*sinPsi +
                 9.81e6*pow(L3,3)*pow(m,2)*muk*pow(xdot,2)*ydot*pow((1/sinTheta),2)*sinPsi -
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(xdot,2)*ydot*pow((1/sinTheta),2)*sinPsi +
                 9.81e6*pow(L3,3)*pow(m,2)*muk*pow(ydot,3)*pow((1/sinTheta),2)*sinPsi -
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(ydot,3)*pow((1/sinTheta),2)*sinPsi -
                 100*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi +
                 1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi -
                 2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi +
                 20000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*ydot*cotTheta*pow((1/sinTheta),2)*sinPsi -
                 40000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*cotTheta*pow((1/sinTheta),2)*sinPsi +
                 20000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi -
                 40000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi +
                 20000*L3*lambdaa*lambdat*phidot*psidot*thetadot*ydot*pow((1/sinTheta),3)*sinPsi -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*cotTheta*pow((1/sinTheta),3)*sinPsi +
                 20000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*xdot*cotTheta*pow((1/sinTheta),3)*sinPsi +
                 100*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),3)*sinPsi - 981.*L3*lambdat*m*muk*ydot*pow((1/sinTheta),4)*sinPsi -
                 10000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(sinPsi,2) + 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*pow(sinPsi,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*pow(sinPsi,2) +
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(sinPsi,2) -
                 10000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*cosTheta*pow(sinPsi,2) +
                 20000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*cosTheta*pow(sinPsi,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*cosTheta*pow(sinPsi,2) +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*cosTheta*pow(sinPsi,2) -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*cosTheta*pow(sinPsi,2) -
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*cotTheta*pow(sinPsi,2) - 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*cotTheta*pow(sinPsi,2) -
                 100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2) +
                 200*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2) -
                 100*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2) +
                 1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*cotTheta*pow(sinPsi,2) +
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*cotTheta*pow(sinPsi,2) -
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*cotTheta*pow(sinPsi,2) +
                 2000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*cotTheta*pow(sinPsi,2) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*cotTheta*pow(sinPsi,2) +
                 9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*cosTheta*cotTheta*pow(sinPsi,2) -
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*cosTheta*cotTheta*pow(sinPsi,2) -
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosTheta,2)*cotTheta*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosTheta,2)*cotTheta*pow(sinPsi,2) -
                 1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,2)*cotTheta*pow(sinPsi,2) -
                 10000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cotTheta,2)*pow(sinPsi,2) +
                 2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cotTheta,2)*pow(sinPsi,2) -
                 2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cotTheta,2)*pow(sinPsi,2) +
                 2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*xdot*ydot*pow(cotTheta,2)*pow(sinPsi,2) +
                 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow(cotTheta,2)*pow(sinPsi,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*xdot*cosPsi*pow(cotTheta,2)*pow(sinPsi,2) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow(sinPsi,2) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,2)*pow(sinPsi,2) -
                 10000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) +
                 20000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*xdot*cosPsi*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cotTheta,3)*pow(sinPsi,2) -
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cotTheta,3)*pow(sinPsi,2) +
                 1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cotTheta,3)*pow(sinPsi,2) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cotTheta,3)*pow(sinPsi,2) +
                 9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*cosTheta*pow(cotTheta,3)*pow(sinPsi,2) -
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*cosTheta*pow(cotTheta,3)*pow(sinPsi,2) -
                 1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,2)*pow(cotTheta,3)*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,2)*pow(cotTheta,3)*pow(sinPsi,2) -
                 1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosTheta,2)*pow(cotTheta,3)*pow(sinPsi,2) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cotTheta,4)*pow(sinPsi,2) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,4)*pow(sinPsi,2) +
                 981.*pow(L3,4)*pow(m,2)*muk*psidot*(1/sinTheta)*pow(sinPsi,2) - 9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*(1/sinTheta)*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*(1/sinTheta)*pow(sinPsi,2) -
                 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*(1/sinTheta)*pow(sinPsi,2) -
                 1.962e7*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*(1/sinTheta)*pow(sinPsi,2) +
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*(1/sinTheta)*pow(sinPsi,2) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*(1/sinTheta)*pow(sinPsi,2) -
                 10000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*cotTheta*(1/sinTheta)*pow(sinPsi,2) +
                 20000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*cotTheta*(1/sinTheta)*pow(sinPsi,2) -
                 1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*xdot*ydot*cotTheta*(1/sinTheta)*pow(sinPsi,2) +
                 2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*xdot*ydot*cotTheta*(1/sinTheta)*pow(sinPsi,2) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*cotTheta*(1/sinTheta)*pow(sinPsi,2) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cotTheta*(1/sinTheta)*pow(sinPsi,2) -
                 9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2) +
                 1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2) -
                 10000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2) +
                 20000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2) -
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2) -
                 10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow((1/sinTheta),2)*pow(sinPsi,2) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow((1/sinTheta),2)*pow(sinPsi,2) +
                 100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2) -
                 300*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2) -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2) +
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPsi,2) -
                 10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPsi,2) +
                 981.*pow(L3,2)*lambdat*m*muk*psidot*pow((1/sinTheta),3)*pow(sinPsi,2) +
                 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow((1/sinTheta),3)*pow(sinPsi,2) +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow((1/sinTheta),3)*pow(sinPsi,2) +
                 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow(sinPsi,3) - 1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow(sinPsi,3) -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*cosTheta*pow(sinPsi,3) +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*cosTheta*pow(sinPsi,3) -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*cosTheta*pow(sinPsi,3) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*cotTheta*pow(sinPsi,3) -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow(sinPsi,3) +
                 9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cotTheta,2)*pow(sinPsi,3) -
                 1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*ydot*pow(cotTheta,2)*pow(sinPsi,3) -
                 1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*cosTheta*pow(cotTheta,2)*pow(sinPsi,3) +
                 1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*cosTheta*pow(cotTheta,2)*pow(sinPsi,3) -
                 1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*ydot*cosTheta*pow(cotTheta,2)*pow(sinPsi,3) +
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cotTheta,3)*pow(sinPsi,3) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*(1/sinTheta)*pow(sinPsi,3) +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*cotTheta*(1/sinTheta)*pow(sinPsi,3) -
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,3) -
                 10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,3) +
                 98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow((1/sinTheta),3)*pow(sinPsi,3) +
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(sinPsi,4) -
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cosTheta*pow(sinPsi,4) +
                 10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cotTheta*(1/sinTheta)*pow(sinPsi,4) -
                 98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow((1/sinTheta),2)*pow(sinPsi,4) -
                 1000000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*cosTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*cosTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 2000000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 4000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*pow(cosPsi,3)*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,4)*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,4)*cosTheta*pow(cotTheta,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*pow(cosPsi,3)*pow(cotTheta,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*xdot*cosPsi*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 98100.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 100*pow(L3,2)*lambdaa*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 200*pow(L3,2)*lambdat*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(xdot,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(ydot,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 2000000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*ydot*cosPsi*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosPsi,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*pow(cosPsi,3)*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*pow(cosPsi,3)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 100*pow(L3,2)*lambdaa*m*phidot*thetadot*pow((1/sinTheta),2)*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
           pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
           pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(xdot,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(ydot,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 98100.*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 2000000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 4000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*phidot*psidot*thetadot*xdot*cosPsi*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 98100.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 100*lambdaa*lambdat*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 200*pow(lambdat,2)*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*lambdaa*lambdat*psidot*thetadot*pow(xdot,2)*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*lambdaa*lambdat*psidot*thetadot*pow(ydot,2)*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 2000000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*ydot*cosPsi*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 100*lambdaa*lambdat*phidot*thetadot*pow((1/sinTheta),4)*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
       pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
       pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*lambdaa*lambdat*phidot*thetadot*pow(xdot,2)*pow((1/sinTheta),4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*lambdaa*lambdat*phidot*thetadot*pow(ydot,2)*pow((1/sinTheta),4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 98100.*L3*lambdat*m*muk*xdot*cosPsi*pow((1/sinTheta),4)*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
       pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
       pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*ydot*cotTheta*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*cotTheta*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosPsi,2)*pow(cotTheta,2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosPsi,2)*pow(cotTheta,3)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*ydot*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*xdot*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosPsi,2)*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(xdot,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(ydot,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 98100.*pow(L3,3)*pow(m,2)*muk*ydot*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*ydot*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(xdot,2)*cosPsi*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(ydot,2)*cosPsi*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 4000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*phidot*psidot*thetadot*ydot*pow((1/sinTheta),3)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*xdot*cotTheta*pow((1/sinTheta),3)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),3)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 98100.*L3*lambdat*m*muk*ydot*pow((1/sinTheta),4)*sinPsi*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
       pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
       pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*cosTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*cosTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 98100.*pow(L3,4)*pow(m,2)*muk*psidot*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*cotTheta*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*cotTheta*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*cotTheta*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cotTheta*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 2000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 30000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 98100.*pow(L3,2)*lambdat*m*muk*psidot*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*cotTheta*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*(1/sinTheta)*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*cotTheta*(1/sinTheta)*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow((1/sinTheta),3)*pow(sinPsi,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(sinPsi,4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cosTheta*pow(sinPsi,4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cotTheta*(1/sinTheta)*pow(sinPsi,4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow((1/sinTheta),2)*pow(sinPsi,4)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta) -
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*pow(cosPsi,3)*pow(cotTheta,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*cosTheta*pow(cotTheta,4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 200*pow(L3,2)*lambdaa*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 400*pow(L3,2)*lambdat*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*cotTheta*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*cotTheta*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 196200.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*pow(cosPsi,3)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cotTheta,3)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cotTheta,3)*(1/sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 200*pow(L3,2)*lambdaa*m*phidot*thetadot*pow((1/sinTheta),2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
          pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*cosPsi*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 196200.*pow(L3,4)*pow(m,2)*muk*psidot*pow((1/sinTheta),3)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
        pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 20000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 200*lambdaa*lambdat*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 400*pow(lambdat,2)*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*cotTheta*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 200*lambdaa*lambdat*phidot*thetadot*pow((1/sinTheta),4)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 98100.*L3*lambdat*m*muk*xdot*cosPsi*pow((1/sinTheta),4)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosPsi,2)*pow(cotTheta,3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,4)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(xdot,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(ydot,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cotTheta,3)*(1/sinTheta)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,3)*pow(m,2)*muk*ydot*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*ydot*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(xdot,2)*cosPsi*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(ydot,2)*cosPsi*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*cotTheta*pow((1/sinTheta),3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 98100.*L3*lambdat*m*muk*ydot*pow((1/sinTheta),4)*sinPsi*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cotTheta,3)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cotTheta,4)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*cosTheta*pow(cotTheta,4)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,4)*pow(m,2)*muk*psidot*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 30000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 98100.*pow(L3,2)*lambdat*m*muk*psidot*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cotTheta,3)*pow(sinPsi,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPsi,3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 2000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,2)*lambdaa*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 40000*pow(L3,2)*lambdat*m*psidot*thetadot*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 2000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cotTheta,2)*(1/sinTheta)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*cotTheta*pow((1/sinTheta),2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*lambdaa*lambdat*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 40000*pow(lambdat,2)*psidot*thetadot*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),3)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 20000*lambdaa*lambdat*phidot*thetadot*pow((1/sinTheta),4)*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
         pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
         pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*L3*lambdat*m*muk*xdot*cosPsi*pow((1/sinTheta),4)*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
       pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
       pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*cotTheta*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 2000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cotTheta,2)*(1/sinTheta)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*pow(L3,3)*pow(m,2)*muk*ydot*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*cotTheta*pow((1/sinTheta),2)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),3)*sinPsi*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 9.81e6*L3*lambdat*m*muk*ydot*pow((1/sinTheta),4)*sinPsi*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta -
       pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta + pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) +
       pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) - 2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 2000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cotTheta*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*(1/sinTheta)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 3000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 9.81e6*pow(L3,2)*lambdat*m*muk*psidot*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                 1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow((1/sinTheta),3)*pow(sinPsi,2)*
                 sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
                       pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
                       2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                 50*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*sin(2*theta) +
                 50*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*sin(2*theta) -
                 50*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*sin(2*theta) -
                 50*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*pow((1/sinTheta),3)*sin(2*theta) +
                 50*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*pow((1/sinTheta),3)*sin(2*theta) -
                 50*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow((1/sinTheta),3)*sin(2*theta) +
                 50*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow((1/sinTheta),4)*sin(2*theta) - 50*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow((1/sinTheta),4)*sin(2*theta) +
                 50*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow((1/sinTheta),4)*sin(2*theta) -
                 50*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*pow((1/sinTheta),3)*sinPsi*sin(2*theta) +
                 50*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*pow((1/sinTheta),3)*sinPsi*sin(2*theta) -
                 50*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow((1/sinTheta),3)*sinPsi*sin(2*theta) -
                 5000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                 5000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                 5000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow((1/sinTheta),3)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                 5000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow((1/sinTheta),4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow((1/sinTheta),4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                 5000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow((1/sinTheta),4)*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*pow((1/sinTheta),3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                 5000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*pow((1/sinTheta),3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                 5000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow((1/sinTheta),3)*sinPsi*
                 sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                      pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta))/
                (lambdat*(1 + 100*sqrt((-2*L3*psidot*xdot*cosPsi + 2*L3*thetadot*ydot*cosPsi*cotTheta - pow(L3,2)*pow(psidot,2)*cosTheta*cotTheta +
    pow(L3,2)*pow(thetadot,2)*cosTheta*cotTheta + pow(L3,2)*pow(psidot,2)*(1/sinTheta) + pow(xdot,2)*(1/sinTheta) + pow(ydot,2)*(1/sinTheta) -
    2*L3*psidot*ydot*sinPsi - 2*L3*thetadot*xdot*cotTheta*sinPsi)*sinTheta))*
                 (1 + 100*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                               pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))*
                 (-100*pow(L3,3)*m*muk*thetadot*pow(cosPsi,2)*pow(cotTheta,2) + pow(L3,2)*m*(1/sinTheta) - 100*pow(L3,2)*m*muk*ydot*cosPsi*cotTheta*(1/sinTheta) +
                  lambdat*pow((1/sinTheta),3) + 100*pow(L3,2)*m*muk*xdot*cotTheta*(1/sinTheta)*sinPsi + 100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2) -
                  100*pow(L3,3)*m*muk*thetadot*pow((1/sinTheta),2)*pow(sinPsi,2) +
                  100*pow(L3,2)*m*(1/sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                  100*lambdat*pow((1/sinTheta),3)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))));

    pdot[7] = -(((1/sinTheta)*(lambdaa*lambdat*phidot*thetadot*cosTheta + 10000*lambdaa*lambdat*phidot*thetadot*pow(xdot,2)*cosTheta +
                               10000*lambdaa*lambdat*phidot*thetadot*pow(ydot,2)*cosTheta + 981.*L3*lambdat*m*muk*xdot*cosPsi*cosTheta +
                               lambdaa*lambdat*psidot*thetadot*pow(cosTheta,2) - 2*pow(lambdat,2)*psidot*thetadot*pow(cosTheta,2) +
                               10000*lambdaa*lambdat*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2) - 20000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2) +
                               10000*lambdaa*lambdat*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2) - 20000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2) -
                               100*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2) -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,2) +
                               20000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,2) +
                               20000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3) -
                               40000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3) +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3) -
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,3) +
                               10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,3) +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,4) +
                               10000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4) -
                               20000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4) +
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4) -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,5) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,5) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,6) + 981.*L3*lambdat*m*muk*ydot*cosTheta*sinPsi +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,2)*sinPsi -
                               20000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*xdot*pow(cosTheta,2)*sinPsi -
                               100*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi -
                               20000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi +
                               40000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,4)*sinPsi +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,5)*sinPsi -
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosTheta,3)*pow(sinPsi,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2) -
                               20000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2) +
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosTheta,5)*pow(sinPsi,2) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,6)*pow(sinPsi,2) +
                               981.*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*sinTheta - 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*cosTheta*sinTheta +
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*cosTheta*sinTheta -
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*cosTheta*sinTheta +
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*cosTheta*sinTheta -
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*cosTheta*sinTheta -
                               20000*L3*lambdaa*lambdat*phidot*psidot*thetadot*xdot*cosPsi*cosTheta*sinTheta -
                               981.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*cosTheta*sinTheta -
                               1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosTheta,2)*sinTheta +
                               1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosTheta,2)*sinTheta -
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*pow(cosTheta,2)*sinTheta -
                               1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,2)*sinTheta +
                               1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,2)*sinTheta -
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*pow(cosTheta,2)*sinTheta -
                               20000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*sinTheta +
                               40000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*sinTheta -
                               100*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta +
                               1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta -
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta +
                               100*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta -
                               981.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosTheta,3)*sinTheta + 100*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(cosTheta,3)*sinTheta -
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*pow(cosTheta,3)*sinTheta +
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*pow(cosTheta,3)*sinTheta -
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*pow(cosTheta,3)*sinTheta +
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*pow(cosTheta,3)*sinTheta -
                               100*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta +
                               200*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta -
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta +
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta -
                               2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*ydot*cosPsi*pow(cosTheta,3)*sinTheta -
                               100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta +
                               9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta -
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta +
                               1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosTheta,4)*sinTheta -
                               1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosTheta,4)*sinTheta +
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*pow(cosTheta,4)*sinTheta +
                               1000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,4)*sinTheta -
                               1000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,4)*sinTheta +
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*pow(cosTheta,4)*sinTheta -
                               1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,4)*sinTheta +
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*ydot*cosPsi*pow(cosTheta,4)*sinTheta -
                               100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta +
                               200*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta -
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta +
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta -
                               1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta +
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cosTheta,5)*sinTheta -
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*ydot*cosPsi*pow(cosTheta,5)*sinTheta +
                               2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*ydot*cosPsi*pow(cosTheta,5)*sinTheta -
                               9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,5)*sinTheta +
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,5)*sinTheta +
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,6)*sinTheta -
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,6)*sinTheta +
                               1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosPsi,2)*pow(cosTheta,6)*sinTheta -
                               20000*L3*lambdaa*lambdat*phidot*psidot*thetadot*ydot*cosTheta*sinPsi*sinTheta +
                               100*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta -
                               1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta +
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta -
                               20000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*sinTheta +
                               40000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*sinTheta +
                               100*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta -
                               200*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta +
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta -
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta +
                               2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*xdot*pow(cosTheta,3)*sinPsi*sinTheta +
                               1.962e7*pow(L3,5)*pow(m,2)*muk*psidot*thetadot*xdot*pow(cosTheta,4)*sinPsi*sinTheta -
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,2)*thetadot*xdot*pow(cosTheta,4)*sinPsi*sinTheta -
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,3)*thetadot*xdot*pow(cosTheta,5)*sinPsi*sinTheta +
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,3)*thetadot*xdot*pow(cosTheta,5)*sinPsi*sinTheta -
                               2000000*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,3)*xdot*pow(cosTheta,5)*sinPsi*sinTheta -
                               981.*pow(L3,2)*lambdat*m*muk*psidot*cosTheta*pow(sinPsi,2)*sinTheta -
                               100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*sinTheta -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*cosTheta*pow(sinPsi,2)*sinTheta -
                               100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta +
                               300*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta +
                               9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta -
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta -
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,4)*pow(sinPsi,2)*sinTheta +
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,4)*pow(sinPsi,2)*sinTheta -
                               1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosTheta,4)*pow(sinPsi,2)*sinTheta -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,4)*pow(sinPsi,2)*sinTheta -
                               9.81e6*pow(L3,6)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,5)*pow(sinPsi,2)*sinTheta +
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(thetadot,2)*pow(cosTheta,5)*pow(sinPsi,2)*sinTheta +
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,6)*pow(sinPsi,2)*sinTheta -
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,6)*pow(sinPsi,2)*sinTheta +
                               1000000*pow(L3,7)*pow(m,2)*muk*psidot*pow(thetadot,4)*pow(cosTheta,6)*pow(sinPsi,2)*sinTheta -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*cosTheta*pow(sinPsi,3)*sinTheta +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*sinTheta +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosTheta,3)*pow(sinPsi,3)*sinTheta -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,4)*pow(sinPsi,3)*sinTheta -
                               pow(lambdat,2)*psidot*thetadot*pow(sinTheta,2) - 10000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*pow(sinTheta,2) -
                               10000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*pow(sinTheta,2) + pow(L3,2)*lambdaa*m*phidot*thetadot*cosTheta*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(xdot,2)*cosTheta*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(ydot,2)*cosTheta*pow(sinTheta,2) +
                               100*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*cosPsi*cosTheta*pow(sinTheta,2) -
                               1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*cosTheta*pow(sinTheta,2) -
                               9.81e6*pow(L3,3)*pow(m,2)*muk*pow(xdot,3)*cosPsi*cosTheta*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(xdot,3)*cosPsi*cosTheta*pow(sinTheta,2) -
                               20000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*cosTheta*pow(sinTheta,2) -
                               9.81e6*pow(L3,3)*pow(m,2)*muk*xdot*pow(ydot,2)*cosPsi*cosTheta*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*pow(ydot,2)*cosPsi*cosTheta*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*cosTheta*pow(sinTheta,2) +
                               pow(L3,2)*lambdaa*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2) - 2*pow(L3,2)*lambdat*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*pow(sinTheta,2) -
                               20000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*pow(sinTheta,2) -
                               20000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) -
                               100*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(xdot,3)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(xdot,3)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(xdot,3)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               20000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*pow(ydot,2)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*pow(ydot,2)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*pow(ydot,2)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2) -
                               20000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2) -
                               10000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2) -
                               1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2) +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*pow(cosPsi,3)*pow(cosTheta,2)*pow(sinTheta,2) +
                               1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2) +
                               20000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2) -
                               40000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2) +
                               10000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,2) +
                               2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,2) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cosTheta,3)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cosTheta,3)*pow(sinTheta,2) -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*pow(cosPsi,3)*pow(cosTheta,3)*pow(sinTheta,2) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,4)*pow(cosTheta,3)*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,4)*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,4)*pow(sinTheta,2) -
                               2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,4)*pow(sinTheta,2) +
                               10000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,2) -
                               20000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cosTheta,4)*pow(sinTheta,2) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cosTheta,4)*pow(sinTheta,2) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*xdot*pow(cosPsi,3)*pow(cosTheta,4)*pow(sinTheta,2) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,4)*pow(cosTheta,4)*pow(sinTheta,2) +
                               20000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*cosTheta*sinPsi*pow(sinTheta,2) +
                               100*pow(L3,2)*lambdaa*m*muk*phidot*psidot*ydot*cosTheta*sinPsi*pow(sinTheta,2) -
                               1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*cosTheta*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*cosTheta*sinPsi*pow(sinTheta,2) -
                               9.81e6*pow(L3,3)*pow(m,2)*muk*pow(xdot,2)*ydot*cosTheta*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(xdot,2)*ydot*cosTheta*sinPsi*pow(sinTheta,2) -
                               9.81e6*pow(L3,3)*pow(m,2)*muk*pow(ydot,3)*cosTheta*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*pow(ydot,3)*cosTheta*sinPsi*pow(sinTheta,2) -
                               20000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*xdot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               100*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(xdot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(xdot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(xdot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*pow(ydot,3)*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*pow(ydot,3)*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*pow(ydot,3)*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*pow(xdot,2)*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*pow(xdot,2)*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*pow(ydot,2)*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*pow(ydot,2)*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosPsi,2)*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                               20000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               40000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               1.962e7*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*pow(xdot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*pow(xdot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*pow(xdot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*pow(ydot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*pow(ydot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*pow(ydot,2)*cosPsi*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) +
                               2000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) -
                               2000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*ydot*pow(cosPsi,2)*pow(cosTheta,4)*sinPsi*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*cosTheta*pow(sinPsi,2)*pow(sinTheta,2) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,2) +
                               10000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) -
                               20000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) -
                               10000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) +
                               1.962e7*pow(L3,4)*pow(m,2)*muk*thetadot*xdot*ydot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*psidot*thetadot*xdot*ydot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2) +
                               10000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) -
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) +
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,2)*thetadot*xdot*ydot*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) -
                               2000000*pow(L3,5)*pow(m,2)*muk*pow(thetadot,3)*xdot*ydot*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2) +
                               10000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) -
                               20000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*xdot*cosPsi*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2) -
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,2) +
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*pow(sinPsi,3)*pow(sinTheta,2) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosTheta,3)*pow(sinPsi,3)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*psidot*pow(thetadot,2)*ydot*pow(cosTheta,3)*pow(sinPsi,3)*pow(sinTheta,2) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosTheta,4)*pow(sinPsi,3)*pow(sinTheta,2) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosTheta,4)*pow(sinPsi,3)*pow(sinTheta,2) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(thetadot,4)*ydot*pow(cosTheta,4)*pow(sinPsi,3)*pow(sinTheta,2) +
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*cosTheta*pow(sinPsi,4)*pow(sinTheta,2) -
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,4)*pow(sinTheta,2) +
                               20000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*pow(sinTheta,3) -
                               20000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*xdot*cosPsi*cosTheta*pow(sinTheta,3) +
                               100*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*cosTheta*pow(sinTheta,3) -
                               981.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*cosTheta*pow(sinTheta,3) +
                               9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*pow(cosPsi,2)*cosTheta*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*pow(cosPsi,2)*cosTheta*pow(sinTheta,3) +
                               1.962e7*pow(L3,4)*pow(m,2)*muk*psidot*pow(xdot,2)*pow(cosPsi,2)*cosTheta*pow(sinTheta,3) -
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(xdot,2)*pow(cosPsi,2)*cosTheta*pow(sinTheta,3) -
                               20000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,3) +
                               40000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) +
                               100*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) +
                               100*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) -
                               1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) -
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) +
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(xdot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) -
                               2000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(xdot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3) -
                               9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,3) +
                               1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,3) +
                               20000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*sinPsi*pow(sinTheta,3) -
                               100*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*cosTheta*sinPsi*pow(sinTheta,3) -
                               20000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*ydot*cosTheta*sinPsi*pow(sinTheta,3) +
                               3.924e7*pow(L3,4)*pow(m,2)*muk*psidot*xdot*ydot*cosPsi*cosTheta*sinPsi*pow(sinTheta,3) -
                               4000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*xdot*ydot*cosPsi*cosTheta*sinPsi*pow(sinTheta,3) -
                               20000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,3) +
                               40000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,3) -
                               4000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*xdot*ydot*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,3) +
                               4000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*xdot*ydot*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,3) -
                               4000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*xdot*ydot*cosPsi*pow(cosTheta,2)*sinPsi*pow(sinTheta,3) +
                               100*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               981.*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) +
                               9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) +
                               100*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) +
                               1.962e7*pow(L3,4)*pow(m,2)*muk*psidot*pow(ydot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) -
                               2000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(ydot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) +
                               100*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               200*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) +
                               100*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               2000000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) +
                               2000000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(ydot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               2000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(ydot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3) -
                               9.81e6*pow(L3,6)*pow(m,2)*muk*pow(psidot,3)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdaa*m*muk*phidot*pow(psidot,4)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,3) +
                               1000000*pow(L3,5)*lambdaa*m*muk*pow(psidot,5)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,3) -
                               1000000*pow(L3,5)*lambdat*m*muk*pow(psidot,5)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,3) +
                               1000000*pow(L3,7)*pow(m,2)*muk*pow(psidot,3)*pow(thetadot,2)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,3) +
                               98100.*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*cosTheta*pow(sinPsi,3)*pow(sinTheta,3) -
                               10000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,3) -
                               pow(L3,2)*lambdat*m*psidot*thetadot*pow(sinTheta,4) - 10000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*pow(sinTheta,4) -
                               10000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*pow(sinTheta,4) -
                               10000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(sinTheta,4) -
                               20000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*cosTheta*pow(sinTheta,4) +
                               10000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*cosTheta*pow(sinTheta,4) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*pow(cosPsi,3)*cosTheta*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*pow(cosPsi,3)*cosTheta*pow(sinTheta,4) +
                               10000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4) -
                               20000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4) -
                               10000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*pow(cosPsi,3)*pow(cosTheta,2)*pow(sinTheta,4) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*pow(cosPsi,3)*pow(cosTheta,2)*pow(sinTheta,4) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*pow(cosPsi,3)*pow(cosTheta,2)*pow(sinTheta,4) +
                               20000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*cosTheta*sinPsi*pow(sinTheta,4) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*pow(cosPsi,2)*cosTheta*sinPsi*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*pow(cosPsi,2)*cosTheta*sinPsi*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*pow(cosPsi,2)*pow(cosTheta,2)*sinPsi*pow(sinTheta,4) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*pow(cosPsi,2)*pow(cosTheta,2)*sinPsi*pow(sinTheta,4) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosPsi,2)*pow(cosTheta,2)*sinPsi*pow(sinTheta,4) -
                               10000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(sinPsi,2)*pow(sinTheta,4) +
                               10000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*cosTheta*pow(sinPsi,2)*pow(sinTheta,4) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*pow(sinPsi,2)*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*xdot*cosPsi*cosTheta*pow(sinPsi,2)*pow(sinTheta,4) -
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,4) +
                               10000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) -
                               20000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) -
                               10000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) +
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4) -
                               9.81e6*pow(L3,5)*pow(m,2)*muk*pow(psidot,2)*ydot*cosTheta*pow(sinPsi,3)*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*phidot*pow(psidot,3)*ydot*cosTheta*pow(sinPsi,3)*pow(sinTheta,4) +
                               1000000*pow(L3,4)*lambdaa*m*muk*pow(psidot,4)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,4) -
                               1000000*pow(L3,4)*lambdat*m*muk*pow(psidot,4)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,4) +
                               1000000*pow(L3,6)*pow(m,2)*muk*pow(psidot,2)*pow(thetadot,2)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,4) -
                               98100.*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*cosTheta*pow(sinPsi,4)*pow(sinTheta,4) +
                               10000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,4)*pow(sinTheta,4) +
                               20000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(sinTheta,5) +
                               20000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*sinPsi*pow(sinTheta,5) -
                               100*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,5) -
                               10000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(sinTheta,6) -
                               10000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(sinPsi,2)*pow(sinTheta,6) +
                               100*lambdaa*lambdat*phidot*thetadot*cosTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
         pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
         2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               1000000*lambdaa*lambdat*phidot*thetadot*pow(xdot,2)*cosTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*lambdaa*lambdat*phidot*thetadot*pow(ydot,2)*cosTheta*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 98100.*L3*lambdat*m*muk*xdot*cosPsi*cosTheta*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) + 100*lambdaa*lambdat*psidot*thetadot*pow(cosTheta,2)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 200*pow(lambdat,2)*psidot*thetadot*pow(cosTheta,2)*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*lambdaa*lambdat*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*
                         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                              2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*lambdaa*lambdat*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*
                              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                   2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*
                                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
    2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*
    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
         2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,2)*
         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
              2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*
              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                   2*L3*psidot*ydot*sinPsi*sinTheta) - 4000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*
                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                        2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,3)*
                        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                             2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*
                             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                  2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*
                                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
   2*L3*psidot*ydot*sinPsi*sinTheta) + 98100.*L3*lambdat*m*muk*ydot*cosTheta*sinPsi*
   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
        2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*phidot*pow(thetadot,2)*xdot*pow(cosTheta,2)*sinPsi*
        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
             2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*
             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                  2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*
                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                       pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                       2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*
                       sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                            pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                            2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2)*
                            sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                 pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                 2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*
                                 sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
  2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*
  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
       pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
       2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*phidot*psidot*thetadot*xdot*cosPsi*cosTheta*sinTheta*
       sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
            pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
            2*L3*psidot*ydot*sinPsi*sinTheta) - 98100.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*cosTheta*sinTheta*
            sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                 pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                 2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*sinTheta*
                 sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                      pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                      2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*sinTheta*
                      sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                           pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                           2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta*
                           sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta*
                                sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
 pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
 2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta*
 sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
      pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
      2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
      sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
           pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
           2*L3*psidot*ydot*sinPsi*sinTheta) + 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
           sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta*
                sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                     2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta*
                     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                          2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*pow(cosPsi,3)*pow(cosTheta,3)*sinTheta*
                          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                               2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*pow(cosPsi,3)*pow(cosTheta,4)*sinTheta*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*phidot*psidot*thetadot*ydot*cosTheta*sinPsi*sinTheta*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*lambdaa*lambdat*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*sinTheta*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*sinTheta*
                         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                              2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(xdot,2)*cosPsi*pow(cosTheta,2)*sinPsi*sinTheta*
                              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                   2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(ydot,2)*cosPsi*pow(cosTheta,2)*sinPsi*sinTheta*
                                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
    2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
         2*L3*psidot*ydot*sinPsi*sinTheta) - 20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
              2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(xdot,2)*cosPsi*pow(cosTheta,3)*sinPsi*
              sinTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                            pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                            2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(ydot,2)*cosPsi*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*sinTheta*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosPsi,2)*pow(cosTheta,4)*sinPsi*
     sinTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                   pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                   2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               98100.*pow(L3,2)*lambdat*m*muk*psidot*cosTheta*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*sinTheta*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*cosTheta*pow(sinPsi,2)*sinTheta*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) + 30000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*
                         sinTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
   pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
   2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*cosTheta*pow(sinPsi,3)*sinTheta*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*sinTheta*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 100*pow(lambdat,2)*psidot*thetadot*pow(sinTheta,2)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(lambdat,2)*psidot*thetadot*pow(xdot,2)*pow(sinTheta,2)*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(lambdat,2)*psidot*thetadot*pow(ydot,2)*pow(sinTheta,2)*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) + 100*pow(L3,2)*lambdaa*m*phidot*thetadot*cosTheta*pow(sinTheta,2)*
                         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                              2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(xdot,2)*cosTheta*pow(sinTheta,2)*
                              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                   2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*m*phidot*thetadot*pow(ydot,2)*cosTheta*pow(sinTheta,2)*
                                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
    2*L3*psidot*ydot*sinPsi*sinTheta) + 98100.*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*cosTheta*pow(sinTheta,2)*
    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
         2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*ydot*cosPsi*cosTheta*pow(sinTheta,2)*
         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
              2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*cosTheta*pow(sinTheta,2)*
              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                   2*L3*psidot*ydot*sinPsi*sinTheta) + 100*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                        2*L3*psidot*ydot*sinPsi*sinTheta) - 200*pow(L3,2)*lambdat*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                             2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*pow(sinTheta,2)*
                             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                  2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*pow(cosTheta,2)*pow(sinTheta,2)*
                                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
   2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*pow(sinTheta,2)*
   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
        2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*pow(cosTheta,2)*pow(sinTheta,2)*
        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
             2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2)*
             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                  2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2)*
                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                       pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                       2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2)*
                       sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                            pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                            2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2)*
                            sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                 pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                 2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,2)*
                                 sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
  2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*pow(cosPsi,3)*pow(cosTheta,2)*pow(sinTheta,2)*
  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
       pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
       2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2)*
       sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
            pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
            2*L3*psidot*ydot*sinPsi*sinTheta) - 4000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinTheta,2)*
            sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                 pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                 2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinTheta,2)*
                 sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                      pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                      2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*pow(cosPsi,3)*pow(cosTheta,3)*
                      pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
       pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
       2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,4)*pow(cosTheta,3)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*pow(sinTheta,2)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,4)*pow(cosTheta,4)*
          pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                               pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                               2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               2000000*L3*pow(lambdat,2)*psidot*pow(thetadot,2)*xdot*cosTheta*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 98100.*pow(L3,3)*pow(m,2)*muk*ydot*cosTheta*sinPsi*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdaa*m*phidot*pow(thetadot,2)*xdot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosPsi,2)*pow(cosTheta,2)*sinPsi*
               pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               2000000*pow(L3,3)*lambdaa*m*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*
     pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                          pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                          2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               1000000*pow(L3,2)*lambdaa*lambdat*phidot*pow(psidot,2)*thetadot*cosTheta*pow(sinPsi,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*cosTheta*pow(sinPsi,2)*
pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                     pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                     2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               1000000*pow(L3,2)*lambdaa*lambdat*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*pow(lambdat,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*
          pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                               pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                               2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*phidot*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*
     pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                          pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                          2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,3)*pow(sinPsi,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*pow(sinTheta,2)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*
          pow(sinPsi,2)*pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
         pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
         2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,2)*pow(sinPsi,3)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*pow(sinPsi,3)*
pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                     pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                     2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*cosTheta*pow(sinPsi,4)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,4)*
pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                     pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                     2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               2000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*xdot*cosPsi*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*xdot*cosPsi*cosTheta*pow(sinTheta,3)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*cosTheta*pow(sinTheta,3)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 98100.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*cosTheta*pow(sinTheta,3)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,3)*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,3)*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                              2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                   2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*L3*pow(lambdat,2)*pow(psidot,2)*thetadot*ydot*sinPsi*pow(sinTheta,3)*
                                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
    2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*cosTheta*sinPsi*pow(sinTheta,3)*
    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
         2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdaa*m*phidot*psidot*thetadot*ydot*cosTheta*sinPsi*pow(sinTheta,3)*
         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
              2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdaa*m*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,3)*
              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                   2*L3*psidot*ydot*sinPsi*sinTheta) + 4000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,3)*
                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                        2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                             2*L3*psidot*ydot*sinPsi*sinTheta) - 98100.*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                  2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
   2*L3*psidot*ydot*sinPsi*sinTheta) + 9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
        pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
        2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
        sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
             pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
             2*L3*psidot*ydot*sinPsi*sinTheta) - 20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
             sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                  pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                  2*L3*psidot*ydot*sinPsi*sinTheta) + 10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                  sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                       pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                       2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,2)*pow(sinPsi,2)*
                       pow(sinTheta,3)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
        pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
        2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*cosTheta*pow(sinPsi,3)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,2)*pow(sinPsi,3)*
pow(sinTheta,3)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                     pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                     2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               100*pow(L3,2)*lambdat*m*psidot*thetadot*pow(sinTheta,4)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(xdot,2)*pow(sinTheta,4)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(ydot,2)*pow(sinTheta,4)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(sinTheta,4)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*ydot*cosPsi*cosTheta*pow(sinTheta,4)*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*pow(cosPsi,2)*cosTheta*pow(sinTheta,4)*
                    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                         2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4)*
                         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                              2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4)*
                              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                                   2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,4)*
                                   sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
    2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*pow(L3,3)*lambdat*m*psidot*pow(thetadot,2)*xdot*cosTheta*sinPsi*pow(sinTheta,4)*
    sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
         pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
         2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,2)*pow(lambdat,2)*pow(psidot,3)*thetadot*pow(sinPsi,2)*pow(sinTheta,4)*
         sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
              pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
              2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,4)*lambdaa*m*phidot*pow(psidot,2)*thetadot*cosTheta*pow(sinPsi,2)*pow(sinTheta,4)*
              sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                   pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                   2*L3*psidot*ydot*sinPsi*sinTheta) - 9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*cosTheta*pow(sinPsi,2)*
                   pow(sinTheta,4)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
    pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
    2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               1000000*pow(L3,4)*lambdaa*m*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) - 2000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,4)*lambdat*m*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,4)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,2)*
          pow(sinPsi,2)*pow(sinTheta,4)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
         pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
         2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) -
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*cosTheta*pow(sinPsi,4)*pow(sinTheta,4)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPsi,4)*
pow(sinTheta,4)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
                     pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
                     2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta) +
                               2000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*xdot*cosPsi*pow(sinTheta,5)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta) + 2000000*pow(L3,3)*lambdat*m*pow(psidot,2)*thetadot*ydot*sinPsi*pow(sinTheta,5)*
sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
     pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
     2*L3*psidot*ydot*sinPsi*sinTheta) - 10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,5)*
     sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
          pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
          2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(cosPsi,2)*pow(sinTheta,6)*
          sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
               pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
               2*L3*psidot*ydot*sinPsi*sinTheta) - 1000000*pow(L3,4)*lambdat*m*pow(psidot,3)*thetadot*pow(sinPsi,2)*pow(sinTheta,6)*
               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
                    pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
                    2*L3*psidot*ydot*sinPsi*sinTheta) + 200*lambdaa*lambdat*phidot*thetadot*cosTheta*
                    sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                         pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               98100.*L3*lambdat*m*muk*xdot*cosPsi*cosTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
         pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               200*lambdaa*lambdat*psidot*thetadot*pow(cosTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               400*pow(lambdat,2)*psidot*thetadot*pow(cosTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
               pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*ydot*cosPsi*pow(cosTheta,4)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,4)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*ydot*cosPsi*pow(cosTheta,5)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosPsi,2)*pow(cosTheta,5)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosPsi,2)*pow(cosTheta,6)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               98100.*L3*lambdat*m*muk*ydot*cosTheta*sinPsi*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
         pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,2)*sinPsi*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,3)*sinPsi*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*psidot*xdot*pow(cosTheta,4)*sinPsi*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,2)*xdot*pow(cosTheta,5)*sinPsi*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosTheta,3)*pow(sinPsi,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,4)*pow(sinPsi,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,5)*pow(m,2)*pow(muk,2)*psidot*thetadot*pow(cosTheta,5)*pow(sinPsi,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,6)*pow(m,2)*pow(muk,2)*psidot*pow(thetadot,3)*pow(cosTheta,6)*pow(sinPsi,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               196200.*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               20000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               196200.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,3)*lambdaa*m*muk*phidot*pow(psidot,2)*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*pow(cosPsi,3)*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*pow(cosPsi,3)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(xdot,2)*cosPsi*pow(cosTheta,2)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*pow(ydot,2)*cosPsi*pow(cosTheta,2)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               20000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(xdot,2)*cosPsi*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*pow(ydot,2)*cosPsi*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosPsi,2)*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosPsi,2)*pow(cosTheta,4)*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,2)*lambdat*m*muk*psidot*cosTheta*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               30000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,3)*pow(m,2)*pow(muk,2)*xdot*ydot*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,4)*pow(m,2)*pow(muk,2)*pow(thetadot,2)*xdot*ydot*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*xdot*cosPsi*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*xdot*cosPsi*pow(cosTheta,4)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,4)*pow(m,2)*pow(muk,2)*thetadot*ydot*pow(cosTheta,3)*pow(sinPsi,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,5)*pow(m,2)*pow(muk,2)*pow(thetadot,3)*ydot*pow(cosTheta,4)*pow(sinPsi,3)*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               200*pow(lambdat,2)*psidot*thetadot*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
               pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               200*pow(L3,2)*lambdaa*m*phidot*thetadot*cosTheta*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*cosTheta*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*xdot*cosPsi*cosTheta*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               200*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               400*pow(L3,2)*lambdat*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,3)*pow(m,2)*muk*ydot*cosTheta*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,2)*lambdaa*m*muk*phidot*psidot*ydot*cosTheta*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*cosTheta*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*cosTheta*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*cosTheta*sinPsi*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               98100.*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               20000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               10000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               200*pow(L3,2)*lambdat*m*psidot*thetadot*pow(sinTheta,4)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               10000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,5)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*lambdaa*lambdat*phidot*thetadot*cosTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
           pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
           2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*L3*lambdat*m*muk*xdot*cosPsi*cosTheta*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
         pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
         2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*lambdaa*lambdat*psidot*thetadot*pow(cosTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) +
                  2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) -
                  2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               40000*pow(lambdat,2)*psidot*thetadot*pow(cosTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) +
                 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) -
                 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*L3*lambdat*m*muk*ydot*cosTheta*sinPsi*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
         pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
         2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,2)*lambdat*m*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,2)*lambdat*m*muk*psidot*pow(cosPsi,2)*cosTheta*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*ydot*cosPsi*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               2000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,3)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               2000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,4)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,2)*lambdaa*m*muk*phidot*thetadot*xdot*pow(cosTheta,2)*sinPsi*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,2)*lambdaa*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               2000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*pow(cosTheta,3)*sinPsi*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,2)*lambdat*m*muk*psidot*cosTheta*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               3000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               20000*pow(lambdat,2)*psidot*thetadot*pow(sinTheta,2)*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) +
                 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) -
                 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,2)*lambdaa*m*phidot*thetadot*cosTheta*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,3)*pow(m,2)*muk*xdot*cosPsi*cosTheta*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               20000*pow(L3,2)*lambdaa*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               40000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               9.81e6*pow(L3,3)*pow(m,2)*muk*ydot*cosTheta*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*ydot*cosPsi*cosTheta*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*pow(cosPsi,2)*cosTheta*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosPsi,2)*pow(cosTheta,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,2)*lambdat*m*muk*psidot*thetadot*xdot*cosTheta*sinPsi*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               9.81e6*pow(L3,4)*pow(m,2)*muk*psidot*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,3)*lambdaa*m*muk*phidot*pow(thetadot,2)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,3)*lambdaa*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               2000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                               1000000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,2)*pow(sinPsi,2)*pow(sinTheta,3)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               20000*pow(L3,2)*lambdat*m*psidot*thetadot*pow(sinTheta,4)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                               1000000*pow(L3,3)*lambdat*m*muk*psidot*pow(thetadot,2)*pow(sinPsi,2)*pow(sinTheta,5)*
                               sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta - pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) +
pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi - 2*L3*psidot*xdot*cosPsi*sinTheta -
2*L3*psidot*ydot*sinPsi*sinTheta)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) - 50*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*cosTheta*sin(2*theta) +
                               50*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*cosTheta*sin(2*theta) - 50*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cosTheta*sin(2*theta) +
                               50*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cosTheta,3)*sin(2*theta) - 50*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cosTheta,3)*sin(2*theta) +
                               50*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,3)*sin(2*theta) +
                               50*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*sinTheta*sin(2*theta) -
                               50*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*sinTheta*sin(2*theta) +
                               50*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*cosTheta*sinTheta*sin(2*theta) +
                               50*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*cosTheta*sinPsi*sinTheta*sin(2*theta) -
                               50*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*cosTheta*sinPsi*sinTheta*sin(2*theta) +
                               50*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*cosTheta*sinPsi*sinTheta*sin(2*theta) -
                               5000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*cosTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*cosTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                               5000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*cosTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,3)*lambdaa*m*muk*pow(psidot,3)*pow(cosTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                               5000*pow(L3,3)*lambdat*m*muk*pow(psidot,3)*pow(cosTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,5)*pow(m,2)*muk*psidot*pow(thetadot,2)*pow(cosTheta,3)*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                               5000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*xdot*cosPsi*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*xdot*cosPsi*cosTheta*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,2)*lambdaa*m*muk*pow(psidot,2)*ydot*cosTheta*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) -
                               5000*pow(L3,2)*lambdat*m*muk*pow(psidot,2)*ydot*cosTheta*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta) +
                               5000*pow(L3,4)*pow(m,2)*muk*pow(thetadot,2)*ydot*cosTheta*sinPsi*sinTheta*
                               sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))*sin(2*theta)))/
                (lambdat*(1 + 100*sqrt(pow(L3,2)*pow(psidot,2) + pow(xdot,2) + pow(ydot,2) + 2*L3*thetadot*ydot*cosPsi*cosTheta -
   pow(L3,2)*pow(psidot,2)*pow(cosTheta,2) + pow(L3,2)*pow(thetadot,2)*pow(cosTheta,2) - 2*L3*thetadot*xdot*cosTheta*sinPsi -
   2*L3*psidot*xdot*cosPsi*sinTheta - 2*L3*psidot*ydot*sinPsi*sinTheta))*
                 (1 + 100*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                               pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))*
                 (lambdat - 100*pow(L3,2)*m*muk*ydot*cosPsi*cosTheta*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta +
                  100*pow(L3,2)*m*muk*xdot*cosTheta*sinPsi*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta + pow(L3,2)*m*pow(sinTheta,2) +
                  100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*pow(sinTheta,3) +
                  100*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                  100*pow(L3,2)*m*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))));

    pdot[8] = (-50*muk*(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta)*
               (-19.62*lambdat + 2*L3*lambdat*pow(thetadot,2)*cosTheta + 1962.*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta -
                200*pow(L3,4)*m*muk*pow(thetadot,3)*cosTheta*pow(sinPsi,2)*sinTheta - 1962.*pow(L3,3)*m*muk*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta +
                200*pow(L3,4)*m*muk*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta - 2*L3*lambdaa*phidot*psidot*pow(sinTheta,2) +
                2*pow(L3,3)*m*pow(thetadot,2)*cosTheta*pow(sinTheta,2) - 1962.*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*pow(sinTheta,3) +
                200*pow(L3,4)*m*muk*pow(thetadot,3)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) -
                1962.*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                200*L3*lambdat*pow(thetadot,2)*cosTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                         pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                200*L3*lambdaa*phidot*psidot*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                              pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                200*L3*lambdaa*pow(psidot,2)*cosTheta*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                200*L3*lambdat*pow(psidot,2)*cosTheta*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) - L3*lambdaa*pow(psidot,2)*sinTheta*sin(2*theta) +
                L3*lambdat*pow(psidot,2)*sinTheta*sin(2*theta) - pow(L3,3)*m*pow(thetadot,2)*sinTheta*sin(2*theta)))/
              ((1 + 100*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                             pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))*
               (lambdat - 100*pow(L3,2)*m*muk*ydot*cosPsi*cosTheta*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta +
                100*pow(L3,2)*m*muk*xdot*cosTheta*sinPsi*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta + pow(L3,2)*m*pow(sinTheta,2) +
                100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*pow(sinTheta,3) +
                100*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                 pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                100*pow(L3,2)*m*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                 pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))));

    pdot[9] = (50*muk*(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta)*
               (-19.62*lambdat + 2*L3*lambdat*pow(thetadot,2)*cosTheta + 1962.*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta -
                200*pow(L3,4)*m*muk*pow(thetadot,3)*cosTheta*pow(sinPsi,2)*sinTheta - 1962.*pow(L3,3)*m*muk*thetadot*pow(cosTheta,2)*pow(sinPsi,2)*sinTheta +
                200*pow(L3,4)*m*muk*pow(thetadot,3)*pow(cosTheta,3)*pow(sinPsi,2)*sinTheta - 2*L3*lambdaa*phidot*psidot*pow(sinTheta,2) +
                2*pow(L3,3)*m*pow(thetadot,2)*cosTheta*pow(sinTheta,2) - 1962.*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*pow(sinTheta,3) +
                200*pow(L3,4)*m*muk*pow(thetadot,3)*cosTheta*pow(sinPsi,2)*pow(sinTheta,3) -
                1962.*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                200*L3*lambdat*pow(thetadot,2)*cosTheta*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                         pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                200*L3*lambdaa*phidot*psidot*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                              pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) -
                200*L3*lambdaa*pow(psidot,2)*cosTheta*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                200*L3*lambdat*pow(psidot,2)*cosTheta*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
   pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) - L3*lambdaa*pow(psidot,2)*sinTheta*sin(2*theta) +
                L3*lambdat*pow(psidot,2)*sinTheta*sin(2*theta) - pow(L3,3)*m*pow(thetadot,2)*sinTheta*sin(2*theta)))/
              ((1 + 100*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                             pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)))*
               (lambdat - 100*pow(L3,2)*m*muk*ydot*cosPsi*cosTheta*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(cosPsi,2)*pow(cosTheta,2)*sinTheta +
                100*pow(L3,2)*m*muk*xdot*cosTheta*sinPsi*sinTheta - 100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*sinTheta + pow(L3,2)*m*pow(sinTheta,2) +
                100*pow(L3,3)*m*muk*thetadot*pow(sinPsi,2)*pow(sinTheta,3) +
                100*lambdat*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                                 pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2)) +
                100*pow(L3,2)*m*pow(sinTheta,2)*sqrt(pow(-xdot + L3*thetadot*cosTheta*sinPsi + L3*psidot*cosPsi*sinTheta,2) +
                 pow(ydot + L3*thetadot*cosPsi*cosTheta - L3*psidot*sinPsi*sinTheta,2))));

}
int ConeSymGlisse::update(const double& dt)
{
    if(tan(M_PI_2 - P[0]) <= sqrt(2*lambdaa/m)/L3) //la toupie a touché le sol quand tan(Pi/2 - theta) = r/L3
    {
        return 0;
    }
    lsoda.lsoda_update(accels, 10, all_params_i, all_params_live, &t, t + dt, &istate, data,1e-3, 1e-3);

    P.setVect({all_params_live[1],all_params_live[2],all_params_live[3],all_params_live[4],all_params_live[5]});
    P_dot.setVect({all_params_live[6],all_params_live[7],all_params_live[8],all_params_live[9],all_params_live[10]});
    if (istate <= 0)
    {
        cerr << "LSODA integrator error istate = " <<  istate << endl;
        exit(0);
    }
    return 0;
}

Vecteur4 ConeSymGlisse::returnIndicators() const {
    cosTheta = cos(P[0]);
    cosPsi = cos(P[1]);
    cosPhi = cos(P[2]);
    sinTheta = sin(P[0]);
    sinPsi = sin(P[1]);
    sinPhi = sin(P[2]);
    thetadot = P_dot[0];
    psidot = P_dot[1];
    phidot = P_dot[2];
    xdot = P[3];
    ydot = P[4];
    return Vecteur4(
            1/2*m*(xdot*xdot + ydot*ydot + pow((-L3*sinTheta*thetadot),2)) +
            1/2*(lambdat*pow(psidot*sinTheta*sinPhi + thetadot*cosPhi,2) +
            lambdat*pow(psidot*sinTheta*cosPhi - thetadot*sinPhi,2) +
            lambdaa*pow(psidot*cosTheta + phidot,2)) + m*9.81*L3*cosTheta,
            lambdat*(psidot*sinTheta*sinPhi + thetadot*cosPhi)*
            sinTheta*sinPhi +
            lambdat*(psidot*sinTheta*cosPhi - thetadot*sinPhi)*
            sinTheta*cosPhi +
            lambdaa*(psidot*cosTheta + phidot)*cosTheta,
            lambdaa*(psidot*cosTheta + phidot),
            0
            );
}
