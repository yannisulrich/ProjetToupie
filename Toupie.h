//
// Created by Yannis on 06.03.20.
//
#pragma once
#include "Vecteur.h"
#include "Matrice.h"

class Toupie {
protected:
    Vecteur P;
    Vecteur P_dot;
    Matrice Ig;
public:
    Toupie(const Vecteur & P_, const Vecteur & P_dot_, const Matrice &  I_): P(P_), P_dot(P_dot_), Ig(I_) {};
    [[nodiscard]] Vecteur getP() const;
    [[nodiscard]] Vecteur getP_dot() const;
    [[nodiscard]] Matrice getI() const;
    [[nodiscard]] Vecteur f() const;
    friend std::ostream& operator<<(std::ostream& out, const Toupie & mat);
};



