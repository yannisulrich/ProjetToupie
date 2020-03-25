//
// Created by Yannis on 12.03.20.
//

#pragma once

#include "Toupie.h"
#include "Integrateur.h"
template <typename T>
class IntegrateurEulerCromer: Integrateur<T> {
public:
    explicit IntegrateurEulerCromer(const std::function<VecteurArray<T>(const double & t, const VecteurArray<T> &, const VecteurArray<T> &)> &f)
            : Integrateur<T>(f) {}

    void integrate(Toupie &toupie, const double &dt, const double & t = 0);
    void integrateMultiple(const unsigned int&, Toupie & toup, const double& dt, const double & t = 0);
};


typedef IntegrateurEulerCromer<std::array<double, 5> > IntegrateurEulerCromer5;
