//
// Created by Yannis on 12.03.20.
//

#pragma once

#include <utility>

#include "Toupie.h"
#include "Vecteur.h"
class Integrateur {
protected:
    const std::function<Vecteur(const Vecteur&, const Vecteur&)> f;
public:
    Integrateur(std::function<Vecteur(const Vecteur&, const Vecteur&)>  f_): f(std::move(f_)) {};
    void integrate(const Toupie & toup, const double& dt);
};
