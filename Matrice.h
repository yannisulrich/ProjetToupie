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

    [[nodiscard]] double get_value(const int & line, const int & col) const;

    double& operator()(const unsigned & line, const unsigned & col);
    Matrice operator+(Matrice & mat2); //surcharge des opérateurs élémentaires
    Matrice operator-(Matrice & mat2);
    Matrice operator*(const Matrice &);
    friend Matrice operator*(const double & scal, const Matrice & mat);
    Vecteur operator*(const Vecteur & vect) const;
    [[nodiscard]] Matrice transp() const;
    [[nodiscard]] double det() const;
    Matrice inv();

    friend ostream& operator<<(ostream& out, const Matrice & mat);




};



