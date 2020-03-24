//
// Created by Yannis on 22.03.20.
//

#include "IntegrateurRungeKutta.h"

template <typename T>
void IntegrateurRungeKutta<T>::integrate(Toupie & toupie, const double & dt, const double & t) {
    k1 = toupie.P_dot;
    k1p = this->f(t, toupie.P, toupie.P_dot);
    k2 = toupie.P_dot + dt/2 * k1p;
    k2p = this->f(t + dt/2, toupie.P+dt/2*k1, toupie.P_dot + dt/2 * k1p);
    k3 = toupie.P_dot + dt/2*k2p;
    k3p = this->f(t+dt/2, toupie.P + dt/2 * k2, toupie.P_dot + dt/2 * k2p);
    k4 = toupie.P_dot + dt * k3p;
    k4p = this->f(t + dt, toupie.P + dt * k3, toupie.P_dot + dt * k3p);

    toupie.P += dt/6 * (k1 + 2*k2 + 2*k3 + k4);
    toupie.P_dot += dt/6 * (k1p + 2*k2p + 2*k3p + k4p);
}
template <typename T>
void IntegrateurRungeKutta<T>::integrateMultiple(const unsigned int& n, Toupie & toupie, const double& dt,const double& t) {
    for(size_t i(0); i < n; ++i) {
        integrate(toupie, dt, t + i*dt);
    }
}
template class IntegrateurRungeKutta<std::array<double, 5> >;