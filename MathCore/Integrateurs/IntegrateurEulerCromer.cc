//
// Created by Yannis on 12.03.20.
//

#include "IntegrateurEulerCromer.h"
#include "../Toupie.h"

//TODO: see if ever used

void IntegrateurEulerCromer::integrate(Toupie &toupie, const double & dt,const double & t) {
    toupie.P_dot += dt * toupie.f(t);
    toupie.P += dt * toupie.P_dot;
}


void IntegrateurEulerCromer::integrateMultiple(const unsigned int & n, Toupie &toupie, const double &dt, const double & t) {
    for(size_t i(0); i < n; ++i) {
        integrate( toupie, dt, t + i*dt);
    }
}

