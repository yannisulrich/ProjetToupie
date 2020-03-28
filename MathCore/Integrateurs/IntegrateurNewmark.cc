//
// Created by Yannis on 22.03.20.
//

#include "IntegrateurNewmark.h"
#include <iostream>

template<int n>
void IntegrateurNewmark<n>::integrate(Toupie & toupie, const double & dt, const double & t) {
    P_dot_n = toupie.P_dot;
    P_n = toupie.P;
    s = toupie.f(t, P_n, P_dot_n);
    q.setVect(std::array<double, n>());
    while((P_n - q)*(P_n - q) > e_ * e_) {
        q = P_n;
        r = toupie.f(t, P_n, P_dot_n);
        P_dot_n = toupie.P_dot + dt/2*(r+s);
        P_n = toupie.P + dt *toupie.P_dot + dt*dt/3*(0.5 * r + s);
    }
    toupie.P = P_n;
    toupie.P_dot = P_dot_n;
}

template<int n>
void IntegrateurNewmark<n>::integrateMultiple(const unsigned int & k, Toupie &toup, const double &dt, const double & t) {
    for(size_t i(0); i < k; ++i) {
        integrate(toup, dt, t + i * dt);
    }
}

template class IntegrateurNewmark<5>;