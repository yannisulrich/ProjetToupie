//
// Created by Yannis on 12.03.20.
//

#pragma once

#include "Toupie.h"
#include "Integrateur.h"


class IntegrateurEulerCromer: Integrateur {
public:
    explicit IntegrateurEulerCromer() = default;

    void integrate(Toupie &toupie, const double &dt, const double & t = 0) override;
    void integrateMultiple(const unsigned int&, Toupie & toup, const double& dt, const double & t = 0) override;
};

