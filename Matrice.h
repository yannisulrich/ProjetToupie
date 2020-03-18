//
// Created by Yannis on 05.03.20.
//
#pragma once
#include <array>
#include "Vecteur.h"
#include <initializer_list>
class Matrice {
private:


    std::array<std::array<double, 3 >, 3 > m;

public:
    Matrice(): m({0,0,0,0,0,0,0,0,0}) {}
    Matrice(const std::array<double, 3> &v_0, const std::array<double, 3> &v_1, const std::array<double, 3> &v_2); //initialisation avec valeurs configurables partout
    Matrice(const double & m11, const double & m22, const double & m33); //matrices diagonales
    Matrice(const Matrice & mat2) = default;

    [[nodiscard]] double get_value(const int &, const int &) const;

    double& operator()(const unsigned & line, const unsigned & col);
    Matrice& operator+=(const Matrice &); //surcharge des opérateurs élémentaires
    Matrice& operator-=(const Matrice &);
    Matrice operator*(const Matrice &);
    friend Matrice operator*(const double &, const Matrice &);
    Vecteur operator*(const Vecteur &) const;
    [[nodiscard]] Matrice transp() const;
    [[nodiscard]] double det() const;
    Matrice inv();

    friend std::ostream& operator<<(std::ostream&, const Matrice &);
};
const Matrice operator+(Matrice mat1, const Matrice& mat2);
const Matrice operator-(Matrice mat1, const Matrice& mat2);



