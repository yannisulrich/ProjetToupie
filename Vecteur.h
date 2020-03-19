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
template <class T>
class Vecteur {
    friend class Matrice; //ceci sert a accélérer la multiplication matricielle
private:
    T* v_ {};
    size_t dim_;
    double * beg;
public:


    //constructeurs
    explicit Vecteur(const std::vector<double> &input);
    explicit Vecteur(const std::array<double, 3> & input);
    explicit Vecteur(const std::array<double, 5> & input);

    explicit Vecteur(const unsigned int & d);


    Vecteur(const double & x, const double & y, const double & z): dim_(3), v_(new T({x,y,z})), beg(&(*v_)[0]) {}
    Vecteur(const Vecteur<T> & vect2) noexcept: v_(new T(*vect2.v_)), dim_(vect2.dim_), beg(&(*v_)[0]) {}
    //Vecteur(Vecteur<T>&& vect2) noexcept: v_(vect2.v_), dim_(vect2.dim_), beg(&(*v_)[0]) {}

    //copy assignment constructor
    /*
    Vecteur<T> & operator=(const Vecteur<T>& vect2) {v_ = new T(*vect2.v_);
    dim_ = vect2.dim_;
    std::cout << "copy assing." << std::endl;
    return *this;
    }
    */
    //move assignment constructor
    //Vecteur<T> & operator=(Vecteur<T>&& vect2) noexcept {v_ = vect2.v_; dim_ = vect2.dim_; return *this;};

    [[nodiscard]] T v() const; //accès aux attributs
    void setVect(const T & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);


    void dimcheck(const Vecteur<T>&) const; //comparaison
    bool operator==(const Vecteur<T>& v2) const;
    bool operator!=(const Vecteur<T>& v2) const;


    Vecteur<T> & operator+=(const Vecteur<T>& v2); //operations mathématiques
    Vecteur<T> & operator-=(const Vecteur<T>& v2);
    friend const Vecteur<T> operator* (const double & scal, Vecteur<T> vect) {
        vect *= scal;
        return vect;
    }
    Vecteur<T>& operator*=(const double &);
    double operator*(const Vecteur<T>& v2) const;
    const Vecteur<T> operator-() const;
    Vecteur<T> operator^(const Vecteur<T> & vect2) const;

    double& operator[](size_t coord);
    friend std::ostream& operator<<(std::ostream& out, const Vecteur<T> & vect) {
        for(double i : *vect.v_) out  << i << std::setw(15);
        out << std::setw(-15);
        return out;};
};
/*
template <class T>
const Vecteur<T> operator*(const double & scal, Vecteur<T>); */
/*
template<> class Vecteur<std::vector<double> > {
public:

};*/

template <class T>
const Vecteur<T> operator+(Vecteur<T> v1, const Vecteur<T>& v2) {
    v1.dimcheck(v2);
    v1 += v2;
    return v1;
};
template <class T>
const Vecteur<T> operator-(Vecteur<T> v1, const Vecteur<T>& v2) {
    v1.dimcheck(v2);
    v1 -= v2;
    return v1;
};





