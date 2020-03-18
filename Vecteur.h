//
// Created by Yannis on 27.02.20.
//
#pragma once


#include <initializer_list>
#include <memory>
#include <vector>
#include <iostream>
#include <memory>

class Vecteur {
    friend class Matrice; //ceci sert a accélérer la multiplication matricielle
private:
    std::vector<double>  *v_ {};
    size_t dim_;
    double * beg;
public:
    Vecteur(std::initializer_list<double> const& input); //constructeurs
    explicit Vecteur(const unsigned int & d): dim_(d), v_(new std::vector<double> (d)), beg(&(*v_)[0]) {}
    Vecteur(const double & x, const double & y, const double & z): dim_(3), v_(new std::vector<double>({x,y,z})), beg(&(*v_)[0]) {}
    Vecteur(const Vecteur & vect2) noexcept: v_(new std::vector<double>(*vect2.v_)), dim_(vect2.dim_), beg(&(*v_)[0]) {std::cout << "warning copy" << std::endl;}
    Vecteur(Vecteur&& vect2) noexcept: v_(vect2.v_), dim_(vect2.dim_), beg(&(*v_)[0]) {std::cout << "warning move" << std::endl;}

    //copy assignment constructor

    Vecteur & operator=(const Vecteur& vect2) {v_ = new std::vector<double>(*vect2.v_);
    dim_ = vect2.dim_;
    std::cout << "copy assing." << std::endl;
    return *this;
    }

    //move assignment constructor
    Vecteur & operator=(Vecteur&& vect2) noexcept {v_ = vect2.v_; dim_ = vect2.dim_;std::cout << "warning move assign." << std::endl; return *this;};

    [[nodiscard]] std::vector<double> v() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);


    void dimcheck(const Vecteur& vect2) const; //comparaison
    bool operator==(const Vecteur& v2) const;
    bool operator!=(const Vecteur& v2) const;


    Vecteur & operator+=(const Vecteur& v2); //operations mathématiques
    Vecteur & operator-=(const Vecteur& v2);
    friend const Vecteur operator*(const double &, Vecteur);
    Vecteur& operator*=(const double &);
    double operator*(const Vecteur& v2) const;
    const Vecteur operator-() const;
    Vecteur operator^(const Vecteur & vect2) const;

    double& operator[](size_t coord);
    friend std::ostream& operator<<(std::ostream& out, const Vecteur & vect);
};
const Vecteur operator*(const double & scal, Vecteur vect);
const Vecteur operator+(Vecteur v1, const Vecteur& v2);
const Vecteur operator-(Vecteur v1, const Vecteur& v2);





