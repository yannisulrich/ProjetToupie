

#include "TippeTopFriction.h"
#include <cmath>

using namespace std;


void TippeTopFriction::affiche(std::ostream & out) const {
    out << "P: " << P << ", P_dot: " << P_dot;
    out << ", masse: " << m << ", Rayon:  " << R << ", epsilon: " << epsilon;
}

void TippeTopFriction::accels( double t, double* p, double* pdot, void* data)
{
    //(theta, psi, phi, x, y)
    double theta, psi, phi, x, y, thetadot, psidot, phidot, xdot, ydot;
    double sinTheta, cosTheta, cotTheta, sinPhi, cosPhi, sinPsi, cosPsi;
    double m, I1, I3;

    //I1 = Ig.getCoord(0,0);
    //I3 = Ig.getCoord(2,2);

    auto * constants = static_cast<double*>(data);

    double R = *constants;
    double epsilon = *(constants+1);
    double mu = *(constants+2);
    m = *(constants+3);
    I1 = *(constants+4);
    I3 = *(constants+5);

    pdot[0] = p[5];
    pdot[1] = p[6];
    pdot[2] = p[7];
    pdot[3] = p[8];
    pdot[4] = p[9];

    theta = p[0];
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

    pdot[5] = -((0. - 9.81*m*mu*(R - 1.*epsilon*cosTheta)*(-1.*ydot*cosPsi + thetadot*(-1.*R + epsilon*cosTheta) + xdot*sinPsi) -
                 1.*epsilon*m*mu*pow(thetadot,2)*cosTheta*(R - 1.*epsilon*cosTheta)*
                 (-1.*ydot*cosPsi + thetadot*(-1.*R + epsilon*cosTheta) + xdot*sinPsi) +  I1 *phidot*psidot*pow(cosPhi,2)*sinTheta +
                 2.*pow(epsilon,2)*m*pow(thetadot,2)*cosTheta*sinTheta +  I1 *phidot*psidot*pow(sinPhi,2)*sinTheta +
                  I1 *phidot*cosPhi*(thetadot*sinPhi - 1.*psidot*cosPhi*sinTheta) - 1.* I1 *phidot*sinPhi*(thetadot*cosPhi + psidot*sinPhi*sinTheta) +
                 0.5*(19.62*epsilon*m*sinTheta - 2.*pow(epsilon,2)*m*pow(thetadot,2)*cosTheta*sinTheta +
                      2.* I3 *psidot*(phidot + psidot*cosTheta)*sinTheta + 2.* I1 *psidot*cosPhi*cosTheta*(thetadot*sinPhi - 1.*psidot*cosPhi*sinTheta) -
                      2.* I1 *psidot*cosTheta*sinPhi*(thetadot*cosPhi + psidot*sinPhi*sinTheta)))/
                ( I1 *pow(cosPhi,2) +  I1 *pow(sinPhi,2) - 1.*epsilon*m*mu*(R - 1.*epsilon*cosTheta)*
                                                     (-1.*ydot*cosPsi + thetadot*(-1.*R + epsilon*cosTheta) + xdot*sinPsi)*sinTheta + pow(epsilon,2)*m*pow(sinTheta,2)));



    pdot[6] = (-2.*(-0.5* I3 *pow(epsilon,3)*m*mu*phidot*pow(psidot,2) - 0.5* I3 *pow(epsilon,2)*m*mu*pow(phidot,2)*psidot*R -
                    0.5* I3 *pow(epsilon,3)*m*mu*pow(psidot,3)*cosTheta + 0.5* I3 *epsilon*m*mu*pow(phidot,2)*psidot*pow(R,2)*cosTheta +
                    0.5* I1 *pow(epsilon,3)*m*mu*pow(psidot,3)*pow(cosPhi,2)*cosTheta +
                    0.5* I1 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*pow(cosPhi,2)*cosTheta +
                    0.5* I3 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosTheta,2) + 0.5* I3 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosTheta,2) -
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosPhi,2)*pow(cosTheta,2) -
                    0.5* I1 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosPhi,2)*pow(cosTheta,2) - 0.5* I3 *pow(epsilon,2)*m*psidot*thetadot*cotTheta +
                    1.* I1 *pow(epsilon,2)*m*psidot*thetadot*pow(cosPhi,2)*cotTheta - 0.5* I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*cosPsi*cotTheta +
                    0.5* I3 *epsilon*m*mu*phidot*psidot*R*xdot*cosPsi*cotTheta +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*pow(cosPhi,2)*cosPsi*cotTheta +
                    0.5* I3 *epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*cosTheta*cotTheta -
                    0.5* I1 *epsilon*m*mu*pow(psidot,2)*R*xdot*pow(cosPhi,2)*cosPsi*cosTheta*cotTheta -
                    0.5* I3 *pow(epsilon,3)*m*mu*phidot*pow(thetadot,2)*pow(cotTheta,2) +
                    1.* I3 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cotTheta,2) -
                    2.5* I1 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2) -
                    0.5* I1 *epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2) +
                    0.5* I3 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2) -
                    1.* I1 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2) -
                    0.5* I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*cosTheta*pow(cotTheta,2) +
                    1.* I1 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*cosTheta*pow(cotTheta,2) -
                    0.5* I3 *pow(epsilon,2)*m*phidot*thetadot*(1/sinTheta) - 0.5* I3 *pow(epsilon,2)*m*mu*phidot*psidot*xdot*cosPsi*(1/sinTheta) +
                    1.* I3 *pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*cotTheta*(1/sinTheta) -
                    0.5* I3 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*cotTheta*(1/sinTheta) -
                    4.905* I1 *epsilon*m*mu*psidot*R*pow(cosPhi,2)*cotTheta*(1/sinTheta) - 4.905* I1 *m*mu*phidot*pow(R,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta) +
                    0.5* I1 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta) +
                    0.5* I1 *pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta) +
                    1.* I1 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta) +
                    0.5* I3 *pow(epsilon,2)*m*mu*phidot*thetadot*ydot*cosPsi*cotTheta*(1/sinTheta) -
                    0.5* I3 *epsilon*m*mu*psidot*R*thetadot*ydot*cosPsi*cotTheta*(1/sinTheta) +
                    1.* I1 *epsilon*m*mu*psidot*R*thetadot*ydot*pow(cosPhi,2)*cosPsi*cotTheta*(1/sinTheta) -
                    0.5* I1 *epsilon*m*mu*R*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta) -
                    0.5* I3 *epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow((1/sinTheta),2) +
                    4.905* I1 *pow(epsilon,2)*m*mu*psidot*pow(cosPhi,2)*pow((1/sinTheta),2) + 4.905* I1 *epsilon*m*mu*phidot*R*pow(cosPhi,2)*pow((1/sinTheta),2) -
                    0.5* I3 *epsilon*m*mu*phidot*R*thetadot*ydot*cosPsi*pow((1/sinTheta),2) - 0.5* I1 * I3 *psidot*thetadot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),2) +
                    1.*pow( I1 ,2)*psidot*thetadot*pow(cosPhi,4)*cotTheta*pow((1/sinTheta),2) -
                    4.905* I1 *m*mu*R*xdot*pow(cosPhi,2)*cosPsi*cotTheta*pow((1/sinTheta),2) +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosPsi*cotTheta*pow((1/sinTheta),2) -
                    0.5* I1 * I3 *phidot*thetadot*pow(cosPhi,2)*pow((1/sinTheta),3) + 4.905* I1 *epsilon*m*mu*xdot*pow(cosPhi,2)*cosPsi*pow((1/sinTheta),3) +
                    0.5* I1 *pow(epsilon,3)*m*mu*pow(psidot,3)*cosTheta*pow(sinPhi,2) +
                    0.5* I1 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*cosTheta*pow(sinPhi,2) -
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosTheta,2)*pow(sinPhi,2) -
                    0.5* I1 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosTheta,2)*pow(sinPhi,2) +
                    1.* I1 *pow(epsilon,2)*m*psidot*thetadot*cotTheta*pow(sinPhi,2) +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*cosPsi*cotTheta*pow(sinPhi,2) -
                    0.5* I1 *epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*cosTheta*cotTheta*pow(sinPhi,2) -
                    2.5* I1 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cotTheta,2)*pow(sinPhi,2) -
                    0.5* I1 *epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cotTheta,2)*pow(sinPhi,2) -
                    1.* I1 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*pow(sinPhi,2) +
                    1.* I1 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*cosTheta*pow(cotTheta,2)*pow(sinPhi,2) -
                    4.905* I1 *epsilon*m*mu*psidot*R*cotTheta*(1/sinTheta)*pow(sinPhi,2) - 4.905* I1 *m*mu*phidot*pow(R,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) +
                    0.5* I1 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) +
                    0.5* I1 *pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) +
                    1.* I1 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) +
                    1.* I1 *epsilon*m*mu*psidot*R*thetadot*ydot*cosPsi*cotTheta*(1/sinTheta)*pow(sinPhi,2) -
                    0.5* I1 *epsilon*m*mu*R*pow(thetadot,2)*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*pow(sinPhi,2) +
                    4.905* I1 *pow(epsilon,2)*m*mu*psidot*pow((1/sinTheta),2)*pow(sinPhi,2) + 4.905* I1 *epsilon*m*mu*phidot*R*pow((1/sinTheta),2)*pow(sinPhi,2) -
                    0.5* I1 * I3 *psidot*thetadot*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2) +
                    2.*pow( I1 ,2)*psidot*thetadot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2) -
                    4.905* I1 *m*mu*R*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2) +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2) -
                    0.5* I1 * I3 *phidot*thetadot*pow((1/sinTheta),3)*pow(sinPhi,2) + 4.905* I1 *epsilon*m*mu*xdot*cosPsi*pow((1/sinTheta),3)*pow(sinPhi,2) +
                    1.*pow( I1 ,2)*psidot*thetadot*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,4) -
                    0.5* I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*cotTheta*sinPsi + 0.5* I3 *epsilon*m*mu*phidot*psidot*R*ydot*cotTheta*sinPsi +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*pow(cosPhi,2)*cotTheta*sinPsi +
                    0.5* I3 *epsilon*m*mu*pow(psidot,2)*R*ydot*cosTheta*cotTheta*sinPsi -
                    0.5* I1 *epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cosPhi,2)*cosTheta*cotTheta*sinPsi -
                    0.5* I3 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cotTheta,2)*sinPsi +
                    1.* I1 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cosPhi,2)*pow(cotTheta,2)*sinPsi -
                    0.5* I3 *pow(epsilon,2)*m*mu*phidot*psidot*ydot*(1/sinTheta)*sinPsi -
                    0.5* I3 *pow(epsilon,2)*m*mu*phidot*thetadot*xdot*cotTheta*(1/sinTheta)*sinPsi +
                    0.5* I3 *epsilon*m*mu*psidot*R*thetadot*xdot*cotTheta*(1/sinTheta)*sinPsi -
                    1.* I1 *epsilon*m*mu*psidot*R*thetadot*xdot*pow(cosPhi,2)*cotTheta*(1/sinTheta)*sinPsi -
                    0.5* I1 *epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cosPhi,2)*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                    0.5* I3 *epsilon*m*mu*phidot*R*thetadot*xdot*pow((1/sinTheta),2)*sinPsi -
                    4.905* I1 *m*mu*R*ydot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),2)*sinPsi +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(thetadot,2)*ydot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),2)*sinPsi +
                    4.905* I1 *epsilon*m*mu*ydot*pow(cosPhi,2)*pow((1/sinTheta),3)*sinPsi +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*cotTheta*pow(sinPhi,2)*sinPsi -
                    0.5* I1 *epsilon*m*mu*pow(psidot,2)*R*ydot*cosTheta*cotTheta*pow(sinPhi,2)*sinPsi +
                    1.* I1 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cotTheta,2)*pow(sinPhi,2)*sinPsi -
                    1.* I1 *epsilon*m*mu*psidot*R*thetadot*xdot*cotTheta*(1/sinTheta)*pow(sinPhi,2)*sinPsi -
                    0.5* I1 *epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPhi,2)*sinPsi -
                    4.905* I1 *m*mu*R*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi +
                    0.5* I1 *pow(epsilon,2)*m*mu*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi +
                    4.905* I1 *epsilon*m*mu*ydot*pow((1/sinTheta),3)*pow(sinPhi,2)*sinPsi))/
              ( I1 *(pow(cosPhi,2) + pow(sinPhi,2))*(pow(epsilon,2)*m - 2.*pow(epsilon,2)*m*mu*R*thetadot*cotTheta -
                                                  1.*pow(epsilon,2)*m*mu*ydot*cosPsi*cotTheta + 1.*pow(epsilon,3)*m*mu*thetadot*cosTheta*cotTheta +
                                                  1.*epsilon*m*mu*pow(R,2)*thetadot*(1/sinTheta) + 1.*epsilon*m*mu*R*ydot*cosPsi*(1/sinTheta) +  I1 *pow(cosPhi,2)*pow((1/sinTheta),2) +
                                                   I1 *pow((1/sinTheta),2)*pow(sinPhi,2) + 1.*pow(epsilon,2)*m*mu*xdot*cotTheta*sinPsi - 1.*epsilon*m*mu*R*xdot*(1/sinTheta)*sinPsi));



    pdot[7]= (2.*(0. + 0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*pow(cosPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*pow(phidot,2)*psidot*pow(R,2)*pow(cosPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosPhi,2)*cosTheta +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosPhi,2)*cosTheta -
                  0.5*pow( I1 ,2)*pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosPhi,4)*cosTheta -
                  0.5*pow( I1 ,2)*epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosPhi,4)*cosTheta +
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*xdot*pow(cosPhi,2)*cosPsi*cotTheta -
                  0.5*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*xdot*pow(cosPhi,4)*cosPsi*cotTheta -
                  0.5*pow( I3 ,2)*pow(epsilon,3)*m*mu*pow(psidot,3)*pow(cotTheta,2) +
                  0.5*pow( I3 ,2)*epsilon*m*mu*pow(phidot,2)*psidot*pow(R,2)*pow(cotTheta,2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*pow(psidot,3)*pow(cosPhi,2)*pow(cotTheta,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*pow(cosPhi,2)*pow(cotTheta,2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2) +
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*pow(psidot,3)*R*cosTheta*pow(cotTheta,2) +
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*cosTheta*pow(cotTheta,2) -
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosPhi,2)*cosTheta*pow(cotTheta,2) -
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosPhi,2)*cosTheta*pow(cotTheta,2) +
                  0.5*pow( I3 ,2)*epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*pow(cotTheta,3) -
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,3) -
                  0.5*pow( I3 ,2)*pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cotTheta,4) +
                  1.* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,4) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*psidot*thetadot*pow(cosPhi,2)*(1/sinTheta) +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*psidot*R*xdot*pow(cosPhi,2)*cosPsi*(1/sinTheta) -
                  0.5*pow( I3 ,2)*pow(epsilon,3)*m*mu*phidot*pow(psidot,2)*cotTheta*(1/sinTheta) -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*pow(phidot,2)*psidot*R*cotTheta*(1/sinTheta) -
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta) -
                  0.5*pow( I1 ,2)*pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cosPhi,4)*cotTheta*(1/sinTheta) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,4)*cotTheta*(1/sinTheta) -
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*pow(cosPhi,2)*cosPsi*cotTheta*(1/sinTheta) -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*psidot*thetadot*pow(cotTheta,2)*(1/sinTheta) +
                  1.* I1 * I3 *pow(epsilon,2)*m*psidot*thetadot*pow(cosPhi,2)*pow(cotTheta,2)*(1/sinTheta) -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta) +
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*psidot*R*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2)*(1/sinTheta) -
                  0.5*pow( I3 ,2)*pow(epsilon,3)*m*mu*phidot*pow(thetadot,2)*pow(cotTheta,3)*(1/sinTheta) +
                  1.*pow( I3 ,2)*pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cotTheta,3)*(1/sinTheta) -
                  2.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,3)*(1/sinTheta) -
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,3)*(1/sinTheta) +
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*psidot*thetadot*ydot*cosPsi*pow(cotTheta,3)*(1/sinTheta) -
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*pow(cosPhi,2)*cosPsi*pow(cotTheta,3)*(1/sinTheta) +
                  0.5* I1 * I3 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*pow((1/sinTheta),2) -
                  4.905*pow( I1 ,2)*epsilon*m*mu*psidot*R*pow(cosPhi,4)*pow((1/sinTheta),2) -
                  4.905*pow( I1 ,2)*m*mu*phidot*pow(R,2)*pow(cosPhi,4)*pow((1/sinTheta),2) +
                  0.5* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*ydot*pow(cosPhi,2)*cosPsi*pow((1/sinTheta),2) -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*phidot*thetadot*cotTheta*pow((1/sinTheta),2) -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*phidot*psidot*xdot*cosPsi*cotTheta*pow((1/sinTheta),2) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*xdot*pow(cosPhi,4)*cosPsi*cotTheta*pow((1/sinTheta),2) +
                  1.*pow( I3 ,2)*pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2) -
                  0.5*pow( I3 ,2)*epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2) -
                  4.905* I1 * I3 *epsilon*m*mu*psidot*R*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) -
                  4.905* I1 * I3 *m*mu*phidot*pow(R,2)*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) +
                  1.* I1 * I3 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2) +
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*phidot*thetadot*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) -
                  0.5*pow( I3 ,2)*epsilon*m*mu*psidot*R*thetadot*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) +
                  1.* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*ydot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2) -
                  0.5* I1 * I3 *epsilon*m*mu*R*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,3)*pow((1/sinTheta),2) +
                  0.5*pow( I1 ,2)* I3 *psidot*thetadot*pow(cosPhi,4)*pow((1/sinTheta),3) -
                  4.905*pow( I1 ,2)*m*mu*R*xdot*pow(cosPhi,4)*cosPsi*pow((1/sinTheta),3) -
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*cotTheta*pow((1/sinTheta),3) +
                  4.905* I1 * I3 *pow(epsilon,2)*m*mu*psidot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),3) +
                  4.905* I1 * I3 *epsilon*m*mu*phidot*R*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),3) -
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*R*thetadot*ydot*cosPsi*cotTheta*pow((1/sinTheta),3) -
                  0.5* I1 *pow( I3 ,2)*psidot*thetadot*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),3) +
                  1.*pow( I1 ,2)* I3 *psidot*thetadot*pow(cosPhi,4)*pow(cotTheta,2)*pow((1/sinTheta),3) -
                  4.905* I1 * I3 *m*mu*R*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),3) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),3) -
                  0.5* I1 *pow( I3 ,2)*phidot*thetadot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),4) +
                  4.905* I1 * I3 *epsilon*m*mu*xdot*pow(cosPhi,2)*cosPsi*cotTheta*pow((1/sinTheta),4) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*pow(phidot,2)*psidot*pow(R,2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*cosTheta*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*cosTheta*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*pow(epsilon,2)*m*mu*pow(psidot,3)*R*pow(cosPhi,2)*cosTheta*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*pow(cosPhi,2)*cosTheta*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*cotTheta*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*xdot*pow(cosPhi,2)*cosPsi*cotTheta*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*pow(psidot,3)*pow(cotTheta,2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*pow(psidot,2)*R*pow(cotTheta,2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cotTheta,2)*pow(sinPhi,2) -
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,3)*R*cosTheta*pow(cotTheta,2)*pow(sinPhi,2) -
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*cosTheta*pow(cotTheta,2)*pow(sinPhi,2) -
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*pow(cotTheta,3)*pow(sinPhi,2) +
                  1.* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cotTheta,4)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*psidot*thetadot*(1/sinTheta)*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*psidot*R*xdot*cosPsi*(1/sinTheta)*pow(sinPhi,2) -
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cosPhi,2)*cotTheta*(1/sinTheta)*pow(sinPhi,2) -
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*cosPsi*cotTheta*(1/sinTheta)*pow(sinPhi,2) +
                  1.* I1 * I3 *pow(epsilon,2)*m*psidot*thetadot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*xdot*cosPsi*pow(cotTheta,2)*(1/sinTheta)*pow(sinPhi,2) -
                  2.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPhi,2) -
                  0.5* I1 * I3 *epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*pow(cotTheta,3)*(1/sinTheta)*pow(sinPhi,2) -
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*ydot*cosPsi*pow(cotTheta,3)*(1/sinTheta)*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  9.81*pow( I1 ,2)*epsilon*m*mu*psidot*R*pow(cosPhi,2)*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  9.81*pow( I1 ,2)*m*mu*phidot*pow(R,2)*pow(cosPhi,2)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*ydot*cosPsi*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  1.*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  4.905* I1 * I3 *epsilon*m*mu*psidot*R*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  4.905* I1 * I3 *m*mu*phidot*pow(R,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,3)*m*mu*psidot*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*phidot*R*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  1.* I1 * I3 *epsilon*m*mu*psidot*pow(R,2)*pow(thetadot,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  1.* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*ydot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2) -
                  0.5* I1 * I3 *epsilon*m*mu*R*pow(thetadot,2)*xdot*cosPsi*pow(cotTheta,3)*pow((1/sinTheta),2)*pow(sinPhi,2) +
                  1.*pow( I1 ,2)* I3 *psidot*thetadot*pow(cosPhi,2)*pow((1/sinTheta),3)*pow(sinPhi,2) -
                  9.81*pow( I1 ,2)*m*mu*R*xdot*pow(cosPhi,2)*cosPsi*pow((1/sinTheta),3)*pow(sinPhi,2) +
                  4.905* I1 * I3 *pow(epsilon,2)*m*mu*psidot*cotTheta*pow((1/sinTheta),3)*pow(sinPhi,2) +
                  4.905* I1 * I3 *epsilon*m*mu*phidot*R*cotTheta*pow((1/sinTheta),3)*pow(sinPhi,2) -
                  0.5* I1 *pow( I3 ,2)*psidot*thetadot*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2) +
                  2.*pow( I1 ,2)* I3 *psidot*thetadot*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2) -
                  4.905* I1 * I3 *m*mu*R*xdot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2) +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(thetadot,2)*xdot*cosPsi*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2) -
                  0.5* I1 *pow( I3 ,2)*phidot*thetadot*cotTheta*pow((1/sinTheta),4)*pow(sinPhi,2) +
                  4.905* I1 * I3 *epsilon*m*mu*xdot*cosPsi*cotTheta*pow((1/sinTheta),4)*pow(sinPhi,2) -
                  0.5*pow( I1 ,2)*pow(epsilon,2)*m*mu*pow(psidot,3)*R*cosTheta*pow(sinPhi,4) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*phidot*pow(psidot,2)*pow(R,2)*cosTheta*pow(sinPhi,4) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*xdot*cosPsi*cotTheta*pow(sinPhi,4) -
                  0.5*pow( I1 ,2)*pow(epsilon,2)*m*mu*psidot*R*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,4) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*phidot*pow(R,2)*pow(thetadot,2)*cotTheta*(1/sinTheta)*pow(sinPhi,4) -
                  4.905*pow( I1 ,2)*epsilon*m*mu*psidot*R*pow((1/sinTheta),2)*pow(sinPhi,4) -
                  4.905*pow( I1 ,2)*m*mu*phidot*pow(R,2)*pow((1/sinTheta),2)*pow(sinPhi,4) -
                  0.5*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*xdot*cosPsi*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,4) +
                  0.5*pow( I1 ,2)* I3 *psidot*thetadot*pow((1/sinTheta),3)*pow(sinPhi,4) -
                  4.905*pow( I1 ,2)*m*mu*R*xdot*cosPsi*pow((1/sinTheta),3)*pow(sinPhi,4) +
                  1.*pow( I1 ,2)* I3 *psidot*thetadot*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,4) +
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cosPhi,2)*cotTheta*sinPsi -
                  0.5*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cosPhi,4)*cotTheta*sinPsi +
                  0.5*pow( I3 ,2)*epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cotTheta,3)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cosPhi,2)*pow(cotTheta,3)*sinPsi +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*psidot*R*ydot*pow(cosPhi,2)*(1/sinTheta)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cosPhi,2)*cotTheta*(1/sinTheta)*sinPsi -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*psidot*R*ydot*pow(cotTheta,2)*(1/sinTheta)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*pow(cosPhi,2)*pow(cotTheta,2)*(1/sinTheta)*sinPsi -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cotTheta,3)*(1/sinTheta)*sinPsi +
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cosPhi,2)*pow(cotTheta,3)*(1/sinTheta)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*xdot*pow(cosPhi,2)*pow((1/sinTheta),2)*sinPsi -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*phidot*psidot*ydot*cotTheta*pow((1/sinTheta),2)*sinPsi -
                  0.5*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cosPhi,4)*cotTheta*pow((1/sinTheta),2)*sinPsi -
                  0.5*pow( I3 ,2)*pow(epsilon,2)*m*mu*phidot*thetadot*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi +
                  0.5*pow( I3 ,2)*epsilon*m*mu*psidot*R*thetadot*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi -
                  1.* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*xdot*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),2)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cosPhi,2)*pow(cotTheta,3)*pow((1/sinTheta),2)*sinPsi -
                  4.905*pow( I1 ,2)*m*mu*R*ydot*pow(cosPhi,4)*pow((1/sinTheta),3)*sinPsi +
                  0.5*pow( I3 ,2)*epsilon*m*mu*phidot*R*thetadot*xdot*cotTheta*pow((1/sinTheta),3)*sinPsi -
                  4.905* I1 * I3 *m*mu*R*ydot*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),3)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(thetadot,2)*ydot*pow(cosPhi,2)*pow(cotTheta,2)*pow((1/sinTheta),3)*sinPsi +
                  4.905* I1 * I3 *epsilon*m*mu*ydot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),4)*sinPsi +
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*ydot*cotTheta*pow(sinPhi,2)*sinPsi -
                  1.*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cosPhi,2)*cotTheta*pow(sinPhi,2)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*pow(psidot,2)*R*ydot*pow(cotTheta,3)*pow(sinPhi,2)*sinPsi +
                  0.5* I1 * I3 *epsilon*m*mu*phidot*psidot*R*ydot*(1/sinTheta)*pow(sinPhi,2)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*cotTheta*(1/sinTheta)*pow(sinPhi,2)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(psidot,2)*ydot*pow(cotTheta,2)*(1/sinTheta)*pow(sinPhi,2)*sinPsi +
                  1.* I1 * I3 *pow(epsilon,2)*m*mu*psidot*thetadot*xdot*pow(cotTheta,3)*(1/sinTheta)*pow(sinPhi,2)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*xdot*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi -
                  1.*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cosPhi,2)*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi -
                  1.* I1 * I3 *epsilon*m*mu*psidot*R*thetadot*xdot*pow(cotTheta,2)*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi -
                  0.5* I1 * I3 *epsilon*m*mu*R*pow(thetadot,2)*ydot*pow(cotTheta,3)*pow((1/sinTheta),2)*pow(sinPhi,2)*sinPsi -
                  9.81*pow( I1 ,2)*m*mu*R*ydot*pow(cosPhi,2)*pow((1/sinTheta),3)*pow(sinPhi,2)*sinPsi -
                  4.905* I1 * I3 *m*mu*R*ydot*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2)*sinPsi +
                  0.5* I1 * I3 *pow(epsilon,2)*m*mu*pow(thetadot,2)*ydot*pow(cotTheta,2)*pow((1/sinTheta),3)*pow(sinPhi,2)*sinPsi +
                  4.905* I1 * I3 *epsilon*m*mu*ydot*cotTheta*pow((1/sinTheta),4)*pow(sinPhi,2)*sinPsi -
                  0.5*pow( I1 ,2)*epsilon*m*mu*pow(psidot,2)*R*ydot*cotTheta*pow(sinPhi,4)*sinPsi -
                  0.5*pow( I1 ,2)*epsilon*m*mu*R*pow(thetadot,2)*ydot*cotTheta*pow((1/sinTheta),2)*pow(sinPhi,4)*sinPsi -
                  4.905*pow( I1 ,2)*m*mu*R*ydot*pow((1/sinTheta),3)*pow(sinPhi,4)*sinPsi)*pow(sinTheta,2))/
             ( I1 * I3 *(pow(cosPhi,2) + pow(sinPhi,2))*(pow(epsilon,2)*m - 2.*pow(epsilon,2)*m*mu*R*thetadot*cotTheta -
                                                   1.*pow(epsilon,2)*m*mu*ydot*cosPsi*cotTheta + 1.*pow(epsilon,3)*m*mu*thetadot*cosTheta*cotTheta +
                                                   1.*epsilon*m*mu*pow(R,2)*thetadot*(1/sinTheta) + 1.*epsilon*m*mu*R*ydot*cosPsi*(1/sinTheta) +  I1 *pow(cosPhi,2)*pow((1/sinTheta),2) +
                                                    I1 *pow((1/sinTheta),2)*pow(sinPhi,2) + 1.*pow(epsilon,2)*m*mu*xdot*cotTheta*sinPsi - 1.*epsilon*m*mu*R*xdot*(1/sinTheta)*sinPsi));

    pdot[8] = (1.*(9.81* I1 *mu*xdot*pow(cosPhi,2) + 1.* I1 *epsilon*mu*pow(thetadot,2)*xdot*pow(cosPhi,2)*cosTheta +
                   9.81* I1 *mu*xdot*pow(sinPhi,2) + 1.* I1 *epsilon*mu*pow(thetadot,2)*xdot*cosTheta*pow(sinPhi,2) -
                   9.81* I1 *mu*R*thetadot*pow(cosPhi,2)*sinPsi + 9.81* I1 *epsilon*mu*thetadot*pow(cosPhi,2)*cosTheta*sinPsi -
                   1.* I1 *epsilon*mu*R*pow(thetadot,3)*pow(cosPhi,2)*cosTheta*sinPsi +
                   1.* I1 *pow(epsilon,2)*mu*pow(thetadot,3)*pow(cosPhi,2)*pow(cosTheta,2)*sinPsi - 9.81* I1 *mu*R*thetadot*pow(sinPhi,2)*sinPsi +
                   9.81* I1 *epsilon*mu*thetadot*cosTheta*pow(sinPhi,2)*sinPsi - 1.* I1 *epsilon*mu*R*pow(thetadot,3)*cosTheta*pow(sinPhi,2)*sinPsi +
                   1.* I1 *pow(epsilon,2)*mu*pow(thetadot,3)*pow(cosTheta,2)*pow(sinPhi,2)*sinPsi +
                   9.81* I1 *epsilon*mu*psidot*pow(cosPhi,2)*cosPsi*sinTheta + 9.81* I1 *mu*phidot*R*pow(cosPhi,2)*cosPsi*sinTheta +
                   1.* I1 *pow(epsilon,2)*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*cosPsi*cosTheta*sinTheta +
                   1.* I1 *epsilon*mu*phidot*R*pow(thetadot,2)*pow(cosPhi,2)*cosPsi*cosTheta*sinTheta +
                   9.81* I1 *epsilon*mu*psidot*cosPsi*pow(sinPhi,2)*sinTheta + 9.81* I1 *mu*phidot*R*cosPsi*pow(sinPhi,2)*sinTheta +
                   1.* I1 *pow(epsilon,2)*mu*psidot*pow(thetadot,2)*cosPsi*cosTheta*pow(sinPhi,2)*sinTheta +
                   1.* I1 *epsilon*mu*phidot*R*pow(thetadot,2)*cosPsi*cosTheta*pow(sinPhi,2)*sinTheta -
                   1.* I3 *epsilon*mu*phidot*psidot*xdot*pow(sinTheta,2) - 1.* I3 *epsilon*mu*pow(psidot,2)*xdot*cosTheta*pow(sinTheta,2) +
                   1.* I1 *epsilon*mu*pow(psidot,2)*xdot*pow(cosPhi,2)*cosTheta*pow(sinTheta,2) +
                   1.* I1 *epsilon*mu*pow(psidot,2)*xdot*cosTheta*pow(sinPhi,2)*pow(sinTheta,2) +
                   1.* I3 *epsilon*mu*phidot*psidot*R*thetadot*sinPsi*pow(sinTheta,2) -
                   1.* I3 *pow(epsilon,2)*mu*phidot*psidot*thetadot*cosTheta*sinPsi*pow(sinTheta,2) +
                   1.* I3 *epsilon*mu*pow(psidot,2)*R*thetadot*cosTheta*sinPsi*pow(sinTheta,2) -
                   1.* I1 *epsilon*mu*pow(psidot,2)*R*thetadot*pow(cosPhi,2)*cosTheta*sinPsi*pow(sinTheta,2) -
                   1.* I3 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) +
                   1.* I1 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*pow(cosPhi,2)*pow(cosTheta,2)*sinPsi*pow(sinTheta,2) -
                   1.* I1 *epsilon*mu*pow(psidot,2)*R*thetadot*cosTheta*pow(sinPhi,2)*sinPsi*pow(sinTheta,2) +
                   1.* I1 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*pow(cosTheta,2)*pow(sinPhi,2)*sinPsi*pow(sinTheta,2) -
                   1.* I3 *pow(epsilon,2)*mu*phidot*pow(psidot,2)*cosPsi*pow(sinTheta,3) -
                   1.* I3 *epsilon*mu*pow(phidot,2)*psidot*R*cosPsi*pow(sinTheta,3) -
                   1.* I3 *pow(epsilon,2)*mu*pow(psidot,3)*cosPsi*cosTheta*pow(sinTheta,3) -
                   1.* I3 *epsilon*mu*phidot*pow(psidot,2)*R*cosPsi*cosTheta*pow(sinTheta,3) +
                   1.* I1 *pow(epsilon,2)*mu*pow(psidot,3)*pow(cosPhi,2)*cosPsi*cosTheta*pow(sinTheta,3) +
                   1.* I1 *epsilon*mu*phidot*pow(psidot,2)*R*pow(cosPhi,2)*cosPsi*cosTheta*pow(sinTheta,3) +
                   1.* I1 *pow(epsilon,2)*mu*pow(psidot,3)*cosPsi*cosTheta*pow(sinPhi,2)*pow(sinTheta,3) +
                   1.* I1 *epsilon*mu*phidot*pow(psidot,2)*R*cosPsi*cosTheta*pow(sinPhi,2)*pow(sinTheta,3)))/
              (-1.* I1 *pow(cosPhi,2) - 1.* I1 *pow(sinPhi,2) - 1.*epsilon*m*mu*pow(R,2)*thetadot*sinTheta - 1.*epsilon*m*mu*R*ydot*cosPsi*sinTheta +
               2.*pow(epsilon,2)*m*mu*R*thetadot*cosTheta*sinTheta + 1.*pow(epsilon,2)*m*mu*ydot*cosPsi*cosTheta*sinTheta -
               1.*pow(epsilon,3)*m*mu*thetadot*pow(cosTheta,2)*sinTheta + 1.*epsilon*m*mu*R*xdot*sinPsi*sinTheta -
               1.*pow(epsilon,2)*m*mu*xdot*cosTheta*sinPsi*sinTheta - 1.*pow(epsilon,2)*m*pow(sinTheta,2));




    pdot[9] = (-1.*(9.81* I1 *mu*ydot*pow(cosPhi,2) + 9.81* I1 *mu*R*thetadot*pow(cosPhi,2)*cosPsi +
                    1.* I1 *epsilon*mu*pow(thetadot,2)*ydot*pow(cosPhi,2)*cosTheta - 9.81* I1 *epsilon*mu*thetadot*pow(cosPhi,2)*cosPsi*cosTheta +
                    1.* I1 *epsilon*mu*R*pow(thetadot,3)*pow(cosPhi,2)*cosPsi*cosTheta -
                    1.* I1 *pow(epsilon,2)*mu*pow(thetadot,3)*pow(cosPhi,2)*cosPsi*pow(cosTheta,2) + 9.81* I1 *mu*ydot*pow(sinPhi,2) +
                    9.81* I1 *mu*R*thetadot*cosPsi*pow(sinPhi,2) + 1.* I1 *epsilon*mu*pow(thetadot,2)*ydot*cosTheta*pow(sinPhi,2) -
                    9.81* I1 *epsilon*mu*thetadot*cosPsi*cosTheta*pow(sinPhi,2) + 1.* I1 *epsilon*mu*R*pow(thetadot,3)*cosPsi*cosTheta*pow(sinPhi,2) -
                    1.* I1 *pow(epsilon,2)*mu*pow(thetadot,3)*cosPsi*pow(cosTheta,2)*pow(sinPhi,2) +
                    9.81* I1 *epsilon*mu*psidot*pow(cosPhi,2)*sinPsi*sinTheta + 9.81* I1 *mu*phidot*R*pow(cosPhi,2)*sinPsi*sinTheta +
                    1.* I1 *pow(epsilon,2)*mu*psidot*pow(thetadot,2)*pow(cosPhi,2)*cosTheta*sinPsi*sinTheta +
                    1.* I1 *epsilon*mu*phidot*R*pow(thetadot,2)*pow(cosPhi,2)*cosTheta*sinPsi*sinTheta +
                    9.81* I1 *epsilon*mu*psidot*pow(sinPhi,2)*sinPsi*sinTheta + 9.81* I1 *mu*phidot*R*pow(sinPhi,2)*sinPsi*sinTheta +
                    1.* I1 *pow(epsilon,2)*mu*psidot*pow(thetadot,2)*cosTheta*pow(sinPhi,2)*sinPsi*sinTheta +
                    1.* I1 *epsilon*mu*phidot*R*pow(thetadot,2)*cosTheta*pow(sinPhi,2)*sinPsi*sinTheta -
                    1.* I3 *epsilon*mu*phidot*psidot*ydot*pow(sinTheta,2) - 1.* I3 *epsilon*mu*phidot*psidot*R*thetadot*cosPsi*pow(sinTheta,2) -
                    1.* I3 *epsilon*mu*pow(psidot,2)*ydot*cosTheta*pow(sinTheta,2) +
                    1.* I1 *epsilon*mu*pow(psidot,2)*ydot*pow(cosPhi,2)*cosTheta*pow(sinTheta,2) +
                    1.* I3 *pow(epsilon,2)*mu*phidot*psidot*thetadot*cosPsi*cosTheta*pow(sinTheta,2) -
                    1.* I3 *epsilon*mu*pow(psidot,2)*R*thetadot*cosPsi*cosTheta*pow(sinTheta,2) +
                    1.* I1 *epsilon*mu*pow(psidot,2)*R*thetadot*pow(cosPhi,2)*cosPsi*cosTheta*pow(sinTheta,2) +
                    1.* I3 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) -
                    1.* I1 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*pow(cosPhi,2)*cosPsi*pow(cosTheta,2)*pow(sinTheta,2) +
                    1.* I1 *epsilon*mu*pow(psidot,2)*ydot*cosTheta*pow(sinPhi,2)*pow(sinTheta,2) +
                    1.* I1 *epsilon*mu*pow(psidot,2)*R*thetadot*cosPsi*cosTheta*pow(sinPhi,2)*pow(sinTheta,2) -
                    1.* I1 *pow(epsilon,2)*mu*pow(psidot,2)*thetadot*cosPsi*pow(cosTheta,2)*pow(sinPhi,2)*pow(sinTheta,2) -
                    1.* I3 *pow(epsilon,2)*mu*phidot*pow(psidot,2)*sinPsi*pow(sinTheta,3) -
                    1.* I3 *epsilon*mu*pow(phidot,2)*psidot*R*sinPsi*pow(sinTheta,3) -
                    1.* I3 *pow(epsilon,2)*mu*pow(psidot,3)*cosTheta*sinPsi*pow(sinTheta,3) -
                    1.* I3 *epsilon*mu*phidot*pow(psidot,2)*R*cosTheta*sinPsi*pow(sinTheta,3) +
                    1.* I1 *pow(epsilon,2)*mu*pow(psidot,3)*pow(cosPhi,2)*cosTheta*sinPsi*pow(sinTheta,3) +
                    1.* I1 *epsilon*mu*phidot*pow(psidot,2)*R*pow(cosPhi,2)*cosTheta*sinPsi*pow(sinTheta,3) +
                    1.* I1 *pow(epsilon,2)*mu*pow(psidot,3)*cosTheta*pow(sinPhi,2)*sinPsi*pow(sinTheta,3) +
                    1.* I1 *epsilon*mu*phidot*pow(psidot,2)*R*cosTheta*pow(sinPhi,2)*sinPsi*pow(sinTheta,3)))/
              (1.* I1 *pow(cosPhi,2) + 1.* I1 *pow(sinPhi,2) + 1.*epsilon*m*mu*pow(R,2)*thetadot*sinTheta + 1.*epsilon*m*mu*R*ydot*cosPsi*sinTheta -
               2.*pow(epsilon,2)*m*mu*R*thetadot*cosTheta*sinTheta - 1.*pow(epsilon,2)*m*mu*ydot*cosPsi*cosTheta*sinTheta +
               1.*pow(epsilon,3)*m*mu*thetadot*pow(cosTheta,2)*sinTheta - 1.*epsilon*m*mu*R*xdot*sinPsi*sinTheta +
               1.*pow(epsilon,2)*m*mu*xdot*cosTheta*sinPsi*sinTheta + 1.*pow(epsilon,2)*m*pow(sinTheta,2));
}

int TippeTopFriction::update(const double& dt)
{
    lsoda.lsoda_update(accels, 10, all_params_i, all_params_live, &t, t + dt, &istate, data);

    P.setVect({all_params_live[1],all_params_live[2],all_params_live[3],all_params_live[4],all_params_live[5]});
    P_dot.setVect({all_params_live[6],all_params_live[7],all_params_live[8],all_params_live[9],all_params_live[10]});
    if (istate <= 0)
    {
        cerr << "LSODA integrator error istate = " <<  istate << endl;
        exit(0);
    }
    return 0;
}

Vecteur4 TippeTopFriction::returnIndicators() const {
    /*
     * On retourne ici uniquement l'énergie mécanique. //TODO: possibly Jellet integral? not necessary but cool
     */
    cosTheta = cos(P[0]);
    cosPsi = cos(P[1]);
    cosPhi = cos(P[2]);
    sinTheta = cos(P[0]);
    sinPsi = cos(P[1]);
    sinPhi = sin(P[2]);
    thetadot = P_dot[0];
    psidot = P_dot[1];
    phidot = P_dot[2];
    xdot = P_dot[3];
    ydot = P_dot[4];

    return Vecteur4((2*9.81*m*(R - epsilon*cosTheta) + Ig(2,2)*pow(phidot + psidot*cosTheta,2) +
                     Ig(0,0)*pow(thetadot*sinPhi - psidot*cosPhi*sinTheta,2) +
                     Ig(0,0)*pow(thetadot*cosPhi + psidot*sinPhi*sinTheta,2) +
                     m*(pow(xdot,2) + pow(ydot,2) +
                        pow(epsilon,2)*pow(thetadot,2)*pow(sinTheta,2)))/2.,
                                0,
                                0,
                                0
            );
}

Vecteur3 TippeTopFriction::translationModel() const {
    return Vecteur3(P_dot[3],R,P_dot[4]);
}
