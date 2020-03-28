/*
 * Classe abstraite définissant un intégrateur. Ceci permet d'utiliser un polymorphisme fort dans l'utilisation d'intégrateurs
 * qui peuvent varier lors du lancement de la simulation.
 */

#pragma once

#include <utility>
#include <functional>

#include "../Toupie.h"
#include "../VecteurArray.h"
template <typename T>
class Integrateur {
protected:
    const std::function<VecteurArray<T>(const double & t, const VecteurArray<T>& P, const VecteurArray<T>& P_dot)> f;
public:
    explicit Integrateur(std::function<VecteurArray<T>(const double & t, const VecteurArray<T>&, const VecteurArray<T>&)>  f_): f(std::move(f_)) {};
    virtual void integrate(Toupie & toupie, const double& dt, const double & t) = 0;
    virtual void integrateMultiple(const unsigned int& n, Toupie & toup, const double& dt, const double& t) = 0;
};
