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
    Matrice I;
public:
    Toupie(const Vecteur & P_,const Vecteur & P_dot_, Matrice  I_): P(P_), P_dot(P_dot_), I(std::move(I_)) {};
    Vecteur getP() const;
    Vecteur getP_dot() const;
    Matrice getI() const;
    Vecteur f() const;
    friend std::ostream& operator<<(std::ostream& out, const Toupie & mat);
};



