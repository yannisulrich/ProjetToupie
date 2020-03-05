//
// Created by Yannis on 27.02.20.
//
#pragma once
#ifndef PROJETTOUPIE_VECTEUR_H
#define PROJETTOUPIE_VECTEUR_H

#include <initializer_list>
#include <vector>

class Vecteur {
private:
    std::vector<double> v;
    int dim;
public:
    Vecteur(std::initializer_list<double> const& input); //constructeurs
    explicit Vecteur(const int & d): dim(d), v(d) {}
    Vecteur(const double & x, const double & y, const double & z): dim(3), v({x,y,z}) {}

    std::vector<double> getVect() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    int getDim() const;

    void augmente(const double & value); //operations basiques
    void set_coord(const int & coord, const double & value);
    void affiche() const;
    bool compare(const Vecteur & v2) const;

    Vecteur addition(const Vecteur & vect2) const; //operation mathématiques
    Vecteur soustraction(const Vecteur& vect2) const;
    Vecteur oppose() const;
    Vecteur mult(const double & scalar) const;
    double prod_scal(const Vecteur & vect2) const;
    Vecteur prod_vect(const Vecteur & vect2) const;



};


#endif //PROJETTOUPIE_VECTEUR_H
