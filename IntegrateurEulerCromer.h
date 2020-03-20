//
// Created by Yannis on 12.03.20.
//

#pragma once

#include "Toupie.h"
#include "Integrateur.h"
template <typename T>
class IntegrateurEulerCromer: Integrateur<T> {
public:
    explicit IntegrateurEulerCromer(const std::function<Vecteur<T>(const Vecteur<T> &, const Vecteur<T> &)> &f)
            : Integrateur<T>(f) {}

    void integrate(Toupie &toupie, const double &dt) {
        toupie.P_dot += dt * Integrateur<T>::f(toupie.P, toupie.P_dot);
        toupie.P += dt * toupie.P_dot;
    }
};
typedef IntegrateurEulerCromer<std::array<double, 5> > IntegrateurEulerCromer5;
