/*
 * Classe abstraite définissant un intégrateur. Ceci permet d'utiliser un polymorphisme fort dans l'utilisation d'intégrateurs
 * qui peuvent varier lors du lancement de la simulation.
 */

#pragma once

#include <utility>
#include <functional>

#include "../Toupie.h"
#include "../VecteurArray.h"

class Integrateur {
public:
    Integrateur() = default;
    virtual void integrate(Toupie & toupie, const double& dt, const double & t) = 0;
    virtual void integrateMultiple(const unsigned int& n, Toupie & toup, const double& dt, const double& t) = 0;
};
