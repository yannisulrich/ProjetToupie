//
// Created by Yannis on 27.02.20.
//

#include "Vecteur.h"
#include <stdexcept>
#include <iostream>
#include<string>
#include<cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

//constructeurs conditionnels suivant le type de v_


template <> Vecteur<vector<double> >::Vecteur(const unsigned int &d) {
    dim_ = d;
    v_ = vector<double>(d);
}

template<> Vecteur<array<double, 3>>::Vecteur(const array<double, 3> & input) {
    dim_ = input.size();
    v_ = array<double, 3>(input);
}
template<> Vecteur<array<double, 5>>::Vecteur(const array<double, 5> & input) {
    dim_ = input.size();
    v_ = array<double, 5>(input);
}
//accès attributs.
template <class T>
T Vecteur<T>::v() const{
    return v_;
}

template <class T>
void Vecteur<T>::setVect(const T & input) {
    v_ = input;
}

template <class T>
unsigned int Vecteur<T>::dim() const {
    return dim_;
}
/*
template <>
void Vecteur<vector<double> >::augmente(const double & value) {
    v_.push_back(value);
    dim_ += 1;
} not currently implemented
 */
template <class T>
double Vecteur<T>::getCoord(const size_t & Coord) const {
    if(Coord > (v_.size()-1)) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v_[Coord];
}
template <class T>
void Vecteur<T>::set_coord(const size_t & coord, const double & value) {
    if(coord < 0) throw invalid_argument( "received negative value" );
    v_[coord] = value;
}


//operations basiques utiles
template <class T>
void Vecteur<T>::dimcheck(const Vecteur<T>& v2) const {
    if (dim_ != v2.dim_){
        throw invalid_argument( "dimensions do not match" );
    }
}
template <class T>
bool Vecteur<T>::operator==(const Vecteur<T>& v2) const {
    dimcheck(v2);
    for(size_t i(0); i < v_.size(); ++i) {
        if (abs((v_)[i] - (v2.v_)[i]) > 1e-10) {
            return false;
        }
    }
    return true;
}
template <class T>
bool Vecteur<T>::operator!=(const Vecteur<T>& v2) const {
    return not (v_ == v2.v());
}
//op. mathématiques
template <class T>
Vecteur<T> & Vecteur<T>::operator+=(const Vecteur<T>& v2) {

    dimcheck(v2);

    double * vect1pos(& v_[0]);
    const double * vect2pos(& v2.v_[0]);

    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) += (*vect2pos++);
        //(*v_)[i] += (*v2.v_)[i];
    }
    return *this;
}
template <class T>
Vecteur<T> & Vecteur<T>::operator-=(const Vecteur<T>& v2) {
    dimcheck(v2);
    double * vect1pos(& v_[0]);
    const double * vect2pos(&v2.v_[0]);
    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) -= (*vect2pos++);
        //(*v_)[i] -= (*v2.v_)[i];
    }
    return *this;
}
template <class T>
Vecteur<T>& Vecteur<T>::operator*=(const double & scal) {
    for(double& i : v_) {
        i *= scal;
    }
    return *this;
}
template <class T>
const Vecteur<T> Vecteur<T>::operator-() const {
    return -1 * *this;
}
template <class T>
const Vecteur<T> operator*(const double & scal, Vecteur<T> vect) {
    vect *= scal;
    return vect;
}
template <class T>
double Vecteur<T>::operator*(const Vecteur<T>& v2) const {
    dimcheck(v2);
    double output(0);
    for(size_t i(0); i < dim_; ++i) {
        output += v_[i] * v2.v_[i];
    }
    return output;
}

template <>
Vecteur<array<double, 3> > Vecteur<array<double, 3> >::operator^(const Vecteur<array<double, 3> >& vect2) const {
    if (dim_ != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim_) + ")");
    if (vect2.dim_ != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.dim_) +")");
    Vecteur<array<double, 3> > output(array<double, 3>({0.0,0.0,0.0}));
    (output.v_)[0] = (v_)[1] * (vect2.v_)[2] - (v_)[2]*(vect2.v_)[1];
    (output.v_)[1] = (v_)[2]*(vect2.v_)[0] - (v_)[0]*(vect2.v_)[2];
    (output.v_)[2] = (v_)[0]*(vect2.v_)[1] - (v_)[1]*(vect2.v_)[0];
    return output;
}

template <class T>
double &Vecteur<T>::operator[](size_t coord) { //read-write access
    return (double &)(v_)[coord];
}

template class Vecteur<vector<double>>;
template class Vecteur<array<double, 3>>;
template class Vecteur<array<double, 5>>;






