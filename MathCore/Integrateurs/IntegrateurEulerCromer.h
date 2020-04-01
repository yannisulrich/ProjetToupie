//
// Created by Yannis on 12.03.20.
//

#pragma once

#include "Integrateur.h"


class IntegrateurEulerCromer: public Integrateur {
public:
    explicit IntegrateurEulerCromer() = default;

    void integrate(Toupie &toupie, const double &dt, const double & t) override;
};

