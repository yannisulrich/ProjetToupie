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
template <typename T>
class VecteurArray {
    friend class Matrice; //ceci sert a accélérer la multiplication matricielle
protected:
    T v_;
    size_t dim_;
public:
    //constructeurs
    explicit VecteurArray(const T &input): dim_(input.size()), v_(input) {}

    VecteurArray(const double &, const double &, const double &);
    VecteurArray(const double &, const double &, const double &, const double &, const double &);

    //explicit VecteurArray(const unsigned int & d);

    //VecteurArray(const double & x, const double & y, const double & z): dim_(3), v_(T({x,y,z})) {}
    VecteurArray(const VecteurArray<T> & vect2) noexcept: v_(T(vect2.v_)), dim_(vect2.dim_) {}

    [[nodiscard]] T v() const; //accès aux attributs
    void setVect(const T & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);


    void dimcheck(const VecteurArray<T>&) const; //comparaison
    bool operator==(const VecteurArray<T>& v2) const;
    bool operator!=(const VecteurArray<T>& v2) const;

    [[nodiscard]] double norm() const;
    const VecteurArray<T> operator~() const;
    VecteurArray<T> & operator+=(const VecteurArray<T>& v2); //operations mathématiques
    VecteurArray<T> & operator-=(const VecteurArray<T>& v2);
    friend const VecteurArray<T> operator* (const double & scal, VecteurArray<T> vect) {
        vect *= scal;
        return vect;
    }
    VecteurArray<T>& operator*=(const double &);
    double operator*(const VecteurArray<T>& v2) const;
    const VecteurArray<T> operator-() const;
    VecteurArray<T> operator^(const VecteurArray<T> & vect2) const;

    double& operator[](size_t coord);
    friend std::ostream& operator<<(std::ostream& out, const VecteurArray<T> & vect) {
        for(double i : vect.v_) out  << i << std::setw(15);
        out << std::setw(-15);
        return out;};
};

template <class T>
const VecteurArray<T> operator+(VecteurArray<T> v1, const VecteurArray<T>& v2) {
    v1.dimcheck(v2);
    v1 += v2;
    return v1;
};
template <class T>
const VecteurArray<T> operator-(VecteurArray<T> v1, const VecteurArray<T>& v2) {
    v1.dimcheck(v2);
    v1 -= v2;
    return v1;
};

//typedef VecteurArray<std::vector<double> > VecteurN;
typedef VecteurArray<std::array<double, 3> > Vecteur3;
typedef VecteurArray<std::array<double, 5> > Vecteur5;



