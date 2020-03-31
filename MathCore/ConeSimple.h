//
// Created by Yannis on 06.03.20.
//

#pragma once

#include "Toupie.h"
#include "Matrice.h"
#include <iostream>
#include <utility>
#include "Graphics.h"

class ConeSimple: public Toupie {
private:
    double L;
    double R;
    double m;
public:
    ConeSimple(TextViewer* support, std::function<Vecteur5(const double & t, const Vecteur5& P, const Vecteur5& P_dot)> f, const Vecteur5 & P_,
            const Vecteur5 & P_dot_, const double &L_, const double &R_, const double &m_) :
    L(L_), R(R_), m(m_), Toupie(support, std::move(f), P_, P_dot_,
            Matrice(0.15 * m_ * (R_ * R_ + 0.25 * L_ * L_),
                    0.15 * m_ * (R_ * R_ + 0.25 * L_ * L_),
                         0.3 * m_ * R_ * R_), "Conique Simple") {}

    virtual void dessine() override
    { support->dessine(*this); }


    double getL() const;
    double getR() const;
    double getM() const;

    void afficheFile(std::ostream&) const override;

    void affiche(std::ostream&) const override;

    void afficheSimple(std::ostream&) const override;

};



