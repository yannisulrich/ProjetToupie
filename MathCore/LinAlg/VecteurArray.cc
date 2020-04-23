//
// Created by Yannis on 27.02.20.
//

#include "VecteurArray.h"
#include <stdexcept>
#include <iostream>
#include<string>
#include<cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;


//accès attributs.
template <class T>
T VecteurArray<T>::v() const{
    return v_;
}

template <class T>
void VecteurArray<T>::setVect(const T & input) {
    v_ = input;
}

template <class T>
unsigned int VecteurArray<T>::dim() const {
    return dim_;
}

template <class T>
double VecteurArray<T>::getCoord(const size_t & Coord) const {
    if(Coord > (v_.size()-1)) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v_[Coord];
}


//operations basiques utiles

template <class T>
bool VecteurArray<T>::operator==(const VecteurArray<T>& v2) const {
    for(size_t i(0); i < v_.size(); ++i) {
        if (abs((v_)[i] - (v2.v_)[i]) > 1e-10) {
            return false;
        }
    }
    return true;
}
template <class T>
bool VecteurArray<T>::operator!=(const VecteurArray<T>& v2) const {
    return not (v_ == v2.v());
}
//op. mathématiques
template <class T>
VecteurArray<T> & VecteurArray<T>::operator+=(const VecteurArray<T>& v2) {

    double * vect1pos(& v_[0]);
    const double * vect2pos(& v2.v_[0]);

    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) += (*vect2pos++);
        //(*v_)[i] += (*v2.v_)[i];
    }
    return *this;
}
template <class T>
VecteurArray<T> & VecteurArray<T>::operator-=(const VecteurArray<T>& v2) {
    double * vect1pos(& v_[0]);
    const double * vect2pos(&v2.v_[0]);
    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) -= (*vect2pos++);
        //(*v_)[i] -= (*v2.v_)[i];
    }
    return *this;
}
template <class T>
VecteurArray<T>& VecteurArray<T>::operator*=(const double & scal) {
    for(double& i : v_) {
        i *= scal;
    }
    return *this;
}
template <class T>
const VecteurArray<T> VecteurArray<T>::operator-() const {
    return -1 * *this;
}
template <class T>
const VecteurArray<T> operator*(const double & scal, VecteurArray<T> vect) {
    vect *= scal;
    return vect;
}
template <class T>
double VecteurArray<T>::operator*(const VecteurArray<T>& v2) const {
    double output(0);
    for(size_t i(0); i < dim_; ++i) {
        output += v_[i] * v2.v_[i];
    }
    return output;
}
template <class T>
double VecteurArray<T>::norm() const {
    return sqrt(*this * *this);
}
template <class T>
const VecteurArray<T> VecteurArray<T>::operator~() const {
    if(norm() < 1e-10) throw invalid_argument("vector to normalise has too small norm");
    return 1/norm() * *this;
};

Vecteur3 Vecteur3::operator^(const Vecteur3& vect2) const {
    if (dim_ != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim_) + ")");
    if (vect2.dim_ != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.dim_) +")");
    Vecteur3 output(0.0, 0.0, 0.0);
    (output.v_)[0] = (v_)[1] * (vect2.v_)[2] - (v_)[2]*(vect2.v_)[1];
    (output.v_)[1] = (v_)[2]*(vect2.v_)[0] - (v_)[0]*(vect2.v_)[2];
    (output.v_)[2] = (v_)[0]*(vect2.v_)[1] - (v_)[1]*(vect2.v_)[0];
    return output;
}

template <class T>
double & VecteurArray<T>::operator[](size_t coord) { //read-write access
    return v_[coord];
}



template class VecteurArray<array<double, 2>>;
template class VecteurArray<array<double, 3>>;
template class VecteurArray<array<double, 5>>;






