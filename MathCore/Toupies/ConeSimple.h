
#pragma once

#include "Toupie.h"
#include "Matrice.h"
#include <iostream>
#include <utility>
#include "Graphics.h"

class ConeSimple: public Toupie {
protected:
    double L;
    double R;
public:
    ConeSimple(SupportADessin* support,
               const Vecteur5 P, const Vecteur5 P_dot, const double &L, const double &R, const double &m) :
            L(L), R(R), Toupie(support, P, P_dot,
                                        Matrice(0.15 * m * (R * R + 0.25 * L * L),
                                                0.15 * m * (R * R + 0.25 * L * L),
                                                0.3 * m * R * R), m, "Conique Simple") {}
    ConeSimple(TextViewer* support, //TODO: check if these two are necessary
               const Vecteur5 P, const Vecteur5 P_dot, const double &L, const double &R, const double &m) :
            L(L), R(R), Toupie(support, P, P_dot,
                               Matrice(0.15 * m * (R * R + 0.25 * L * L),
                                       0.15 * m * (R * R + 0.25 * L * L),
                                       0.3 * m * R * R), m, "Conique Simple") {}
    ConeSimple(FileViewer* support,
               const Vecteur5 P, const Vecteur5 P_dot, const double &L, const double &R, const double &m) :
            L(L), R(R), Toupie(support, P, P_dot,
                               Matrice(0.15 * m * (R * R + 0.25 * L * L),
                                       0.15 * m * (R * R + 0.25 * L * L),
                                       0.3 * m * R * R), m, "Conique Simple") {}


    void affiche(std::ostream&) const override;

    [[nodiscard]] double getL() const;
    [[nodiscard]] double getR() const;
    [[nodiscard]] double getM() const;




};



