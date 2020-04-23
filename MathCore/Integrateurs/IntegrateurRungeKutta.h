//
// Created by Yannis on 22.03.20.
//
#pragma once

#include "Integrateur.h"
#include "LinAlg/VecteurArray.h"

template <int n>
class IntegrateurRungeKutta: public Integrateur {
private:
    VecteurArray<std::array<double, n> > k1, k2, k3, k4, k1p, k2p, k3p, k4p, P_n, P_dot_n; //éviter de créer un objet à chaque fois que la méthode integrate est appelée
public:
    explicit IntegrateurRungeKutta():
            Integrateur(), k1(), k2(), k3(), k4(), k1p(), k2p(), k3p(), k4p(), P_n(), P_dot_n() {}

    void integrate(Toupie &, const double & dt, const double & t) override;
};

typedef IntegrateurRungeKutta<5> IntegrateurRungeKutta5;



