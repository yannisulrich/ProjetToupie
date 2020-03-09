//
// Created by Yannis on 05.03.20.
//
#pragma once
#include <vector>
#include "Vecteur.h"
#include <initializer_list>
class Matrice {
private:
    std::vector<std::vector<double > > m;

public:
    Matrice(): m({{0,0,0},{0,0,0},{0,0,0}}) {}
    Matrice(std::initializer_list<double> const& v_0,std::initializer_list<double> const& v_1,
            std::initializer_list<double> const& v_2); //initialisation avec valeurs configurables partout
    Matrice(const double & m11, const double & m22, const double & m33); //matrices diagonales

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

    friend ostream& operator<<(ostream&, const Matrice &);




};



