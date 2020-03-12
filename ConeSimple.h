//
// Created by Yannis on 06.03.20.
//

#pragma once

#include "Toupie.h"
#include "Matrice.h"
#include <iostream>

class ConeSimple: public Toupie {
private:
    double L;
    double R;
    double m;
public:
    ConeSimple(const Vecteur & P_,const Vecteur & P_dot_, const double &L_, const double &R_, const double &m_) :
    L(L_), R(R_), m(m_), Toupie(P_, P_dot_,
            Matrice(0.15 * m_ * (R_ * R_ + 0.25 * L_ * L_),
                    0.15 * m_ * (R_ * R_ + 0.25 * L_ * L_),
                         0.3 * m_ * R_ * R_)) {};

    friend void operator<<(std::ostream&, const ConeSimple &);

};



