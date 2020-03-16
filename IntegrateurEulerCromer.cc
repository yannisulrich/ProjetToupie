//
// Created by Yannis on 12.03.20.
//

#include "IntegrateurEulerCromer.h"

void IntegrateurEulerCromer::integrate(Toupie & toupie, const double & dt) {
    toupie.P_dot += dt * f(toupie.P, toupie.P_dot);
    toupie.P += dt*toupie.P_dot;
}
