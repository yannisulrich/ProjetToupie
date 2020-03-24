//
// Created by Yannis on 22.03.20.
//

#pragma once
#include "Integrateur.h"

template <typename T>
class IntegrateurNewmark: public Integrateur<T> {
private:
    VecteurArray<T> q, r, s, P_n, P_dot_n; //éviter de créer un objet à chaque fois que la méthode integrate est appelée
public:
    explicit IntegrateurNewmark(const std::function<VecteurArray<T>(const double & t, const VecteurArray<T> &, const VecteurArray<T> &)> &f):
    Integrateur<T>(f),q(), r(), s(), P_n(), P_dot_n() {}

    void integrate(Toupie & toupie, const double & dt, const double & e, const double & t = 0.);
    void integrateMultiple(const unsigned int&, Toupie & toup, const double& dt, const double& e, const double & t = 0.);
};



typedef IntegrateurNewmark<std::array<double, 5>> IntegrateurNewmark5;


