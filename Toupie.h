//
// Created by Yannis on 06.03.20.
//
#pragma once
#include "Vecteur.h"
#include "Matrice.h"
#include <fstream>
#include <iostream>

class Toupie {
protected:
    Matrice Ig;
public:
    Vecteur P;
    Vecteur P_dot;

    Toupie(const Vecteur & P_, const Vecteur & P_dot_, const Matrice &  I_): P(P_), P_dot(P_dot_), Ig(I_) {};
    [[nodiscard]] Vecteur getP() const;
    [[nodiscard]] Vecteur getP_dot() const;
    void setP(const Vecteur&);
    void setP_dot(const Vecteur&);
    [[nodiscard]] Matrice getI() const;
    [[nodiscard]] Vecteur f() const;
    friend std::ostream& operator<<(std::ostream& out, const Toupie &);
    std::ofstream & imprimeFichierP(std::ofstream& out);
    std::ofstream & imprimeFichierP_dot(std::ofstream &out);
};




