//
// Created by Yannis on 22.03.20.
//

#include "IntegrateurNewmark.h"
#include "Toupies/Toupie.h"


template<>
void IntegrateurNewmark<5>::integrate(Toupie & toupie, const double & dt, const double & t) {
    P_dot_n = toupie.P_dot;
    P_n = toupie.P;
    s = toupie.f(t, P_n, P_dot_n);
    q.setVect(std::array<double, 5>());
    while((P_n - q)*(P_n - q) > e_ * e_) {
        q = P_n;
        r = toupie.f(t, P_n, P_dot_n);
        P_dot_n = toupie.P_dot + dt/2*(r+s);
        P_n = toupie.P + dt *toupie.P_dot + dt*dt/3*(0.5 * r + s);
    }
    toupie.P = P_n;
    toupie.P_dot = P_dot_n;
}

template class IntegrateurNewmark<5>;