//
// Created by Yannis on 27.02.20.
//

#include "Vecteur.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;
//constructeurs
Vecteur::Vecteur(initializer_list<double> const& input) {
    dim_ = input.size();

    v_ = new vector<double>(dim_);
    *v_ = input;
}
/*
Vecteur &Vecteur::operator=(const Vecteur &vect2) {
    if(this == &vect2) return *this;
    delete v_;
    v_ = make_unique<vector<double>>(vect2.dim_);
    v_ = move(vect2.v_);
    dim_ = vect2.dim_;
    //cout << "copy assignment" << endl;
    return *this;
}

Vecteur::Vecteur(Vecteur &&vect2) {
    v = vect2.v;
    dim = vect2.dim;
    vect2.v = nullptr;
    vect2.dim = 0;
    //cout << "move!" << endl;

}
Vecteur &Vecteur::operator=(Vecteur &&vect2) {
    if(this == &vect2) return *this;
    delete v;
    v = vect2.v;
    dim = vect2.dim;
    vect2.v = nullptr;
    vect2.dim = 0;
    //cout << "move assignment!" << endl;
    return *this;
}
*/
//accès attributs.
 vector<double> Vecteur::v() const{
    return (*v_);
}
void Vecteur::setVect(const vector<double> & input) {
    *v_ = input;
}

unsigned int Vecteur::dim() const {
    return dim_;
}
void Vecteur::augmente(const double & value) {
    v_->push_back(value);
    dim_ += 1;
}

double Vecteur::getCoord(const size_t & Coord) const {
    if(Coord > v_->size()-1) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return (*v_)[Coord];
}
void Vecteur::set_coord(const size_t & coord, const double & value) {
    if(coord < 0) throw invalid_argument( "received negative value" );
    (*v_)[coord] = value;
}


//operations basiques utiles

void Vecteur::dimcheck(const Vecteur& v2) const {
    if (dim_ != v2.dim_){
        throw invalid_argument( "dimensions do not match" );
    }
}
bool Vecteur::operator==(const Vecteur& v2) const {
    dimcheck(v2);
    for(size_t i(0); i < v_->size(); ++i) {
        if (abs((*v_)[i] - (*v2.v_)[i]) > 1e-10) {
            ++i;
            return false;
        }
    }
    return true;
}
bool Vecteur::operator!=(const Vecteur& v2) const {
    return not (*v_ == v2.v());
}
ostream& operator<<(ostream& out, const Vecteur & vect) {
    for(double i : *vect.v_) {
        out  << i << setw(10);
    }
    out << setw(-10);
    return out;
}

//op. mathématiques

Vecteur & Vecteur::operator+=(const Vecteur& v2) {

    dimcheck(v2);

    double * vect1pos(beg);
    double * vect2pos(v2.beg);

    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) += (*vect2pos++);
        //(*v_)[i] += (*v2.v_)[i];
    }
    return *this;
}

Vecteur & Vecteur::operator-=(const Vecteur& v2) {
    dimcheck(v2);
    double * vect1pos(beg);
    double * vect2pos(v2.beg);
    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) -= (*vect2pos++);
        //(*v_)[i] -= (*v2.v_)[i];
    }
    return *this;
}
Vecteur& Vecteur::operator*=(const double & scal) {
    for(double& i : *v_) {
        i *= scal;
    }
    return *this;
}
const Vecteur Vecteur::operator-() const {
    return -1 * *this;
}
const Vecteur operator*(const double & scal, Vecteur vect) {
    vect *= scal;
    return vect;
}
const Vecteur operator+(Vecteur v1, const Vecteur& v2) {
    v1.dimcheck(v2);
    v1 += v2;
    return v1;
}
const Vecteur operator-(Vecteur v1, const Vecteur& v2) {
    v1.dimcheck(v2);
    v1 -= v2;
    return v1;
}

double Vecteur::operator*(const Vecteur& v2) const {
    dimcheck(v2);
    double output(0);
    for(size_t i(0); i < dim_; ++i) {
        output += (*v_)[i] * (*v2.v_)[i];
    }
    return output;
}
Vecteur Vecteur::operator^(const Vecteur& vect2) const {
    if (dim_ != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim_) + ")");
    if (vect2.dim_ != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.dim_) +")");
    Vecteur output({0,0,0});
    (*output.v_)[0] = (*v_)[1] * (*vect2.v_)[2] - (*v_)[2]*(*vect2.v_)[1];
    (*output.v_)[1] = (*v_)[2]*(*vect2.v_)[0] - (*v_)[0]*(*vect2.v_)[2];
    (*output.v_)[2] = (*v_)[0]*(*vect2.v_)[1] - (*v_)[1]*(*vect2.v_)[0];
    return output;
}

double &Vecteur::operator[](size_t coord) { //read-write access
    return (double &)(*v_)[coord];
}








