/*
 *
 * Dans ce projet, une classe vecteur était nécessaire à la simulation. La donnée nous demandant de l'implémenter cela avec
 * un vector<double> de taille variable, nous avons fait cela, et cette classe se trouve dans les fichiers Vecteur.h/.cc
 * Néanmoins, les vecteurs ne varieront pas de taille au fil du programme, et donc à des fins d'optimisation nous avons créé une classe
 * VecteurArray pouvant stocker n'importe quel type d'objet ayant les manières d'accès d'un array. Ceci présente une énorme
 * flexibilité, aussi pour des projets à l'avenir. Nous l'avons fait avec une classe template.
 * Dans notre cas, ceci optimise car nous pouvons utiliser des arrays au lieu de vectors.
 * L'accélération, surtout en lecture/écriture "aléatoire" est bien meilleure (la multiplication matricielle a été accélérée par un facteur
 * de presque 10).
 *
 * Les operations mathématiques possibles entres vecteurs sont implémentés (même le produit vectoriel pour les vecteurs de dim 3),
 * ainsi que toutes les méthodes demandées par la donnée. Les opérateurs + et - utilisent les opérateurs += et -=.
 * La multiplication par un double est possible.
 *L'opérateur ~ dénote une méthode qui retourne le vecteur unitaire de même direction et sens que l'objet.
 *
 * L'opérateur [] est surchargé pour permettre l'accès (rw) à une valeur.
 * L'affichage est fait au moyen d'une méthode friend.
 *
 * Des typedef sont faits pour les VecteurArray contenant des arrays de taille 3 et 5: on peut utiliser Vecteur3 et Vecteur5.
 *
 * Enfin, cette classe est "amie" avec la classe matrice pour accélérer l'accès aux valeurs lors de la multiplication matricielle.
 *
 */
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
    friend class Matrice; //ceci sert a accélérer la multiplication matricielle.
protected:
    T v_;
    size_t dim_;
public:
    //constructeurs
    explicit VecteurArray(const T &input): dim_(input.size()), v_(input) {} //construction pour tailles quelconques
    VecteurArray():v_(T()), dim_(v_.size())   {} //const avec valeurs à 0
    VecteurArray(const double &, const double &, const double &); //const. pour 3 valeurs
    VecteurArray(const double &, const double &, const double &, const double &, const double &); //const. pour 5 valeurs

    [[nodiscard]] T v() const; //accès aux attributs
    void setVect(const T & input);
    [[nodiscard]] unsigned int dim() const;
    [[nodiscard]] double getCoord(const size_t & coord) const;

    bool operator==(const VecteurArray<T>& v2) const;
    bool operator!=(const VecteurArray<T>& v2) const;

    [[nodiscard]] double norm() const;
    const VecteurArray<T> operator~() const; // vecteur unitaire pointant dans la même direction et le même sens
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
        for(double i : vect.v_) out << std::setw(10) << i;
        return out;};
};

template <class T>
const VecteurArray<T> operator+(VecteurArray<T> v1, const VecteurArray<T>& v2) {
    v1 += v2;
    return v1;
};
template <class T>
const VecteurArray<T> operator-(VecteurArray<T> v1, const VecteurArray<T>& v2) {
    v1 -= v2;
    return v1;
};

typedef VecteurArray<std::array<double, 3> > Vecteur3;
typedef VecteurArray<std::array<double, 5> > Vecteur5;



