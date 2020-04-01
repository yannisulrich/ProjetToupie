//
// Created by Yannis on 01.04.20.
//

#pragma once
#include "ConeSimple.h"
#include "constantes.h"

class ConeSymFixe: public ConeSimple {
public:
    ConeSymFixe(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot,
            const double &L, const double &R, const double &m):
            ConeSimple(support, P, P_dot, L, R, m) {}

    [[nodiscard]] Vecteur5 f(const double & t) const override;
    [[nodiscard]] Vecteur5 f(const double & t, const Vecteur5& P, const Vecteur5& P_dot) const override;

    void dessine() const override {
        support->dessine(*this); }

};

