//
// Created by Yannis on 22.03.20.
//

#include "Integrateur.h"
#pragma once
template <typename T>
class IntegrateurRungeKutta: public Integrateur<T> {
private:
    VecteurArray<T> k1, k2, k3, k4, k1p, k2p, k3p, k4p, P_n, P_dot_n; //éviter de créer un objet à chaque fois que la méthode integrate est appelée
public:
    explicit IntegrateurRungeKutta(const std::function<VecteurArray<T>(const double & t, const VecteurArray<T> &, const VecteurArray<T> &)> &f):
            Integrateur<T>(f), k1(), k2(), k3(), k4(), k1p(), k2p(), k3p(), k4p(), P_n(), P_dot_n() {}

    void integrate(Toupie &, const double & dt, const double & t = 0);
    void integrateMultiple(const unsigned int& n, Toupie & toupie, const double& dt,const double& t = 0);

};

typedef IntegrateurRungeKutta<std::array<double, 5> > IntegrateurRungeKutta5;



