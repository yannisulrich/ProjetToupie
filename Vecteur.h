//
// Created by Yannis on 27.02.20.
//
#pragma once


#include <initializer_list>
#include <vector>
#include <iostream>
using namespace std;
class Vecteur {
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
    bool operator==(Vecteur const& v2) const;
    bool operator!=(Vecteur const& v2) const;
    Vecteur & operator+=(Vecteur const& v2);
    void operator-=(Vecteur const& v2) const;
    void operator-(Vecteur const& v2) const;
    friend const Vecteur operator*(const double &, Vecteur);
    Vecteur& operator*=(const double &);
    void operator*(Vecteur const& v2) const;
    void operator^(Vecteur const& v2) const;


    [[nodiscard]] Vecteur addition(const Vecteur & vect2) const; //operation mathématiques
    [[nodiscard]] Vecteur soustraction(const Vecteur& vect2) const;
    [[nodiscard]] Vecteur oppose() const;
    [[nodiscard]] Vecteur mult(const double & scalar) const;
    [[nodiscard]] double prod_scal(const Vecteur & vect2) const;
    [[nodiscard]] Vecteur prod_vect(const Vecteur & vect2) const;

    double& operator[](size_t coord);
    friend ostream& operator<<(ostream& out, const Vecteur & vect);


};



