//
// Created by Yannis on 27.02.20.
//
#pragma once
/*
 * Voir le fichier VecteurArray.h pour de plus amples explications sur la structure des différentes classes vecteur.
 * Cette classe enveloppe un std::vector<double> et comporte les méthodes d'accès et de calcul nécessitées au projet.
 * Les méthodes sont identiques à celles de VecteurArray, à l'exception de la méthode "augmente" qui ajoute une valeur double
 * à la fin du vecteur. Les constructeurs sont propres, et leur fonctionnement présenté ci-dessous.
 */

#include <initializer_list>
#include <memory>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <iomanip>

class VecteurN {
protected:
    size_t dim_;
    std::vector<double> v_;

public:
    //constructeurs
    VecteurN(const std::initializer_list<double> & input): dim_(input.size()), v_(input) {} //valeurs quelconques


    explicit VecteurN(const unsigned int & d): dim_(d), v_(std::vector<double>(d)) {} //d = dimension, initialisation des valeurs à 0

    VecteurN(const double & x, const double & y, const double & z): dim_(3), v_({x,y,z}) {} //vecteur à 3 dimensions


    [[nodiscard]] std::vector<double> v() const; //accès aux attributs
    void setVect(const std::vector<double> & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    void augmente(const double & value); //operations basiques


    void dimcheck(const VecteurN&) const; //comparaison
    bool operator==(const VecteurN& v2) const;
    bool operator!=(const VecteurN& v2) const;

    [[nodiscard]] double norm() const;
    const VecteurN operator~() const;
    VecteurN & operator+=(const VecteurN& v2); //operations mathématiques
    VecteurN & operator-=(const VecteurN& v2);
    friend const VecteurN operator+(VecteurN v1, const VecteurN& v2);
    friend const VecteurN operator-(VecteurN v1, const VecteurN& v2);
    friend const VecteurN operator* (const double & scal, VecteurN vect);
    VecteurN& operator*=(const double &);
    double operator*(const VecteurN& v2) const;
    const VecteurN operator-() const;
    VecteurN operator^(const VecteurN & vect2) const;

    double& operator[](const size_t& coord); //accès en read-write
    const double& operator[](const size_t& coord) const; //accès en read only (const overload)

    friend std::ostream& operator<<(std::ostream& out, const VecteurN & vect);
};




