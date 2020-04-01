//
// Created by Yannis on 12.03.20.
//

#include "IntegrateurEulerCromer.h"
#include "Toupies/Toupie.h"
#include <iostream>

void IntegrateurEulerCromer::integrate(Toupie &toupie, const double & dt,const double & t) {
    //std::cout << toupie.P << std::endl;
    toupie.P_dot += dt * toupie.f(t);
    toupie.P += dt * toupie.P_dot;
    //std::cout << toupie.P << std::endl;
}



