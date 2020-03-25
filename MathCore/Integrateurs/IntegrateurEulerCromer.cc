//
// Created by Yannis on 12.03.20.
//

#include "IntegrateurEulerCromer.h"
#include "../Toupie.h"

//TODO: see if ever used
template <class T>
void IntegrateurEulerCromer<T>::integrate(Toupie &toupie, const double & dt,const double & t) {
    toupie.P_dot += dt * this->f(t, toupie.P, toupie.P_dot);
    toupie.P += dt * toupie.P_dot;
}

template<typename T>
void IntegrateurEulerCromer<T>::integrateMultiple(const unsigned int & n, Toupie &toupie, const double &dt, const double & t) {
    for(size_t i(0); i < n; ++i) {
        integrate( toupie, dt, t + i*dt);
    }
}

template class IntegrateurEulerCromer<std::array<double, 5>>;