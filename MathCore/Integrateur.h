//
// Created by Yannis on 12.03.20.
//

#pragma once

#include <utility>

#include "Toupie.h"
#include "VecteurArray.h"
template <typename T>
class Integrateur {
protected:

    const std::function<VecteurArray<T>(const VecteurArray<T>&, const VecteurArray<T>&)> f;
public:
    explicit Integrateur(std::function<VecteurArray<T>(const VecteurArray<T>&, const VecteurArray<T>&)>  f_): f(std::move(f_)) {};
    //virtual void integrate(const Toupie & toup, const double& dt) {};
};
typedef Integrateur<std::array<double, 5> > Integrateur5;