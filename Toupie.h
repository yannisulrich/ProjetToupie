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
    Vecteur5 P;
    Vecteur5 P_dot;

    Toupie(const Vecteur5 & P_, const Vecteur5 & P_dot_, const Matrice &  I_): P(P_), P_dot(P_dot_), Ig(I_) {};
    [[nodiscard]] Vecteur5 getP() const;
    [[nodiscard]] Vecteur5 getP_dot() const;
    void setP(const Vecteur5&);
    void setP_dot(const Vecteur5&);
    [[nodiscard]] Matrice getI() const;
    [[nodiscard]] Vecteur5 f() const;
    friend std::ostream& operator<<(std::ostream& out, const Toupie &);
    std::ofstream & imprimeFichierP(std::ofstream& out);
    std::ofstream & imprimeFichierP_dot(std::ofstream &out);
};




