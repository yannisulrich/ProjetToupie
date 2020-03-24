//
// Created by Yannis on 12.03.20.
//

#pragma once

#include <utility>

#include "../Toupie.h"
#include "../VecteurArray.h"
template <typename T>
class Integrateur {
protected:
    const std::function<VecteurArray<T>(const double & t, const VecteurArray<T>& P, const VecteurArray<T>& P_dot)> f;
public:
    explicit Integrateur(std::function<VecteurArray<T>(const double & t, const VecteurArray<T>&, const VecteurArray<T>&)>  f_): f(std::move(f_)) {};
    virtual  void integrate(const Toupie & toup, const double& dt) {};
    virtual void integrateMultiple(Toupie & toup, const double& dt, const unsigned int&) {};
};
typedef Integrateur<std::array<double, 5> > Integrateur5;