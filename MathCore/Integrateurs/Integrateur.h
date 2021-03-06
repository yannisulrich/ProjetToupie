/*
 * Classe abstraite définissant un intégrateur. Ceci permet d'utiliser un polymorphisme fort dans l'utilisation d'intégrateurs
 * qui peuvent varier lors du lancement de la simulation.
 */

#pragma once

#include <utility>
#include <functional>

class Toupie;

class Integrateur {
public:
    Integrateur() = default;
    virtual void integrate(Toupie & toupie, const double& dt, const double & t) = 0;

    virtual void integrateMultiple(const size_t & n, Toupie & toupie, const double& dt, const double& t) {
        for(size_t i(0); i < n; ++i) {
            integrate(toupie, dt, t + i*dt);
        }
    };
};
