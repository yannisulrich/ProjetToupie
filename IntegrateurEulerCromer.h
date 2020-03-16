//
// Created by Yannis on 12.03.20.
//

#pragma once

#include "Toupie.h"
#include "Integrateur.h"
class IntegrateurEulerCromer: public Integrateur {
public:
    IntegrateurEulerCromer(const std::function<Vecteur(const Vecteur&, const Vecteur&)> & f): Integrateur(f) {};
    void integrate(Toupie&, const double&);
};



