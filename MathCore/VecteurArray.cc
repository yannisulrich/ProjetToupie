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

//constructeurs conditionnels suivant le type de v_

template<> VecteurArray<array<double, 3>>::VecteurArray(const double & a, const double & b, const double & c) {
    dim_ = 3;
    v_ = array<double, 3>({a,b,c});
}
template<> VecteurArray<array<double, 5>>::VecteurArray(const double & a, const double & b, const double & c, const double & d, const double & e) {
    dim_ = 5;
    v_ = array<double, 5>({a,b,c,d,e});
}

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

template <>
void VecteurArray<vector<double> >::augmente(const double & value) {
    v_.push_back(value);
    dim_ += 1;
}

template <class T>
double VecteurArray<T>::getCoord(const size_t & Coord) const {
    if(Coord > (v_.size()-1)) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v_[Coord];
}
template <class T>
void VecteurArray<T>::set_coord(const size_t & coord, const double & value) {
    if(coord < 0) throw invalid_argument( "received negative value" );
    v_[coord] = value;
}


//operations basiques utiles
template <class T>
void VecteurArray<T>::dimcheck(const VecteurArray<T>& v2) const {
    if (dim_ != v2.dim_){
        throw invalid_argument( "dimensions do not match" );
    }
}
template <class T>
bool VecteurArray<T>::operator==(const VecteurArray<T>& v2) const {
    dimcheck(v2);
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
VecteurArray<T> & VecteurArray<T>::operator-=(const VecteurArray<T>& v2) {
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
    dimcheck(v2);
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
template <>
VecteurArray<array<double, 3> > VecteurArray<array<double, 3> >::operator^(const VecteurArray<array<double, 3> >& vect2) const {
    if (dim_ != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim_) + ")");
    if (vect2.dim_ != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.dim_) +")");
    VecteurArray<array<double, 3> > output(0.0, 0.0, 0.0);
    (output.v_)[0] = (v_)[1] * (vect2.v_)[2] - (v_)[2]*(vect2.v_)[1];
    (output.v_)[1] = (v_)[2]*(vect2.v_)[0] - (v_)[0]*(vect2.v_)[2];
    (output.v_)[2] = (v_)[0]*(vect2.v_)[1] - (v_)[1]*(vect2.v_)[0];
    return output;
}

template <class T>
double &VecteurArray<T>::operator[](size_t coord) { //read-write access
    return (double &)(v_)[coord];
}

template class VecteurArray<array<double, 3>>;
template class VecteurArray<array<double, 5>>;






