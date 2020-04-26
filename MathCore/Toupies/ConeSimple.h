
#pragma once

#include "Toupie.h"
#include "LinAlg/Matrice.h"
#include <iostream>
#include <utility>

class ConeSimple : public Toupie {
protected:
    double L;
    double R;
public:
    ConeSimple(SupportADessin* support,
               const Vecteur5 P, const Vecteur5 P_dot, const double &L, const double &R, const double &m) :
            Toupie(support, P, P_dot,
                                        Matrice(0.15 * m * (R * R + 0.25 * L * L),
                                                0.15 * m * (R * R + 0.25 * L * L),
                                                0.3 * m * R * R), m, "Conique Simple"), L(L), R(R) {}


    void affiche(std::ostream&) const override;

    [[nodiscard]] double getL() const;
    [[nodiscard]] double getR() const;
    [[nodiscard]] double getM() const;

    Vecteur4 returnIndicators() const override;

    QVector3D translationModel() const override;

    void addToTraces() override;
};



