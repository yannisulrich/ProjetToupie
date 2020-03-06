//
// Created by Yannis on 27.02.20.
//
#pragma once


#include <initializer_list>
#include <vector>
using namespace std;
class Vecteur {
private:
    std::vector<double> v;
    unsigned int dim;
public:
    Vecteur(std::initializer_list<double> const& input); //constructeurs
    explicit Vecteur(const unsigned int & d): dim(d), v(d) {}
    Vecteur(const double & x, const double & y, const double & z): dim(3), v({x,y,z}) {}

    std::vector<double> getVect() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    unsigned int getDim() const;
    double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques
    void set_coord(const size_t & coord, const double & value);
    void affiche() const;
    bool compare(const Vecteur & v2, const double & Precision) const;

    Vecteur addition(const Vecteur & vect2) const; //operation mathématiques
    Vecteur soustraction(const Vecteur& vect2) const;
    Vecteur oppose() const;
    Vecteur mult(const double & scalar) const;
    double prod_scal(const Vecteur & vect2) const;
    Vecteur prod_vect(const Vecteur & vect2) const;

    double& operator[](size_t coord);
    friend ostream& operator<<(ostream& out, const Vecteur & vect);


};



