//
// Created by Yannis on 22.03.20.
//

#pragma once
#include "Integrateur.h"

template <int n>
class IntegrateurNewmark: public Integrateur {
private:
    VecteurArray<std::array<double, n> > q, r, s, P_n, P_dot_n; //éviter de créer un objet à chaque fois que la méthode integrate est appelée
    double e_;
public:
    explicit IntegrateurNewmark(const double & e):
    Integrateur(),q(), r(), s(), P_n(), P_dot_n(), e_(e) {}

    double & e() {return e_;}
    void integrate(Toupie & toupie, const double & dt, const double & t = 0.);
    void integrateMultiple(const unsigned int&, Toupie & toup, const double& dt, const double & t = 0.);
};



typedef IntegrateurNewmark<5> IntegrateurNewmark5;


