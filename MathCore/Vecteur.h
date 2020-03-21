//
// Created by Yannis on 27.02.20.
//
#pragma once


#include <initializer_list>
#include <memory>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <iomanip>

class VecteurN {
    friend class Matrice; //ceci sert a accélérer la multiplication matricielle
protected:
    std::vector<double> v_;
    size_t dim_;
public:
    //constructeurs
    VecteurN(const std::initializer_list<double> & input): dim_(input.size()), v_(input) {}


    explicit VecteurN(const unsigned int & d): dim_(d), v_(std::vector<double>(d)) {}

    VecteurN(const double & x, const double & y, const double & z): dim_(3), v_({x,y,z}) {}


    [[nodiscard]] std::vector<double> v() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);


    void dimcheck(const VecteurN&) const; //comparaison
    bool operator==(const VecteurN& v2) const;
    bool operator!=(const VecteurN& v2) const;

    [[nodiscard]] double norm() const;
    const VecteurN operator~() const;
    VecteurN & operator+=(const VecteurN& v2); //operations mathématiques
    VecteurN & operator-=(const VecteurN& v2);
    friend const VecteurN operator* (const double & scal, VecteurN vect);
    VecteurN& operator*=(const double &);
    double operator*(const VecteurN& v2) const;
    const VecteurN operator-() const;
    VecteurN operator^(const VecteurN & vect2) const;

    double& operator[](size_t coord);
    friend std::ostream& operator<<(std::ostream& out, const VecteurN & vect);
};




