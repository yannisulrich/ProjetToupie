//
// Created by Yannis on 27.02.20.
//
#pragma once


#include <initializer_list>
#include <vector>
#include <iostream>
class Vecteur {
    friend class Matrice;
private:
    std::vector<double> v;
    unsigned int dim;
public:
    Vecteur(std::initializer_list<double> const& input); //constructeurs
    explicit Vecteur(const unsigned int & d): dim(d), v(d) {}
    Vecteur(const double & x, const double & y, const double & z): dim(3), v({x,y,z}) {}
    [[nodiscard]] std::vector<double> getVect() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    [[nodiscard]] unsigned int getDim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);
    void affiche() const;
    void dimcheck(const Vecteur& vect2) const;
    bool operator==(const Vecteur& v2) const;
    bool operator!=(const Vecteur& v2) const;
    Vecteur & operator+=(const Vecteur& v2);
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





