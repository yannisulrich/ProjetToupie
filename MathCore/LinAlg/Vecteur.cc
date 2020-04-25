//
// Created by Yannis on 27.02.20.
//

#include "Vecteur.h"
#include <stdexcept>
#include<string>
#include<cmath>


using namespace std;
using namespace std::chrono;


//accès attributs.

vector<double> VecteurN::v() const{
    return v_;
}


void VecteurN::setVect(const vector<double> & input) {
    v_ = input;
}


unsigned int VecteurN::dim() const {
    return dim_;
}


void VecteurN::augmente(const double & value) {
    v_.push_back(value);
    dim_ += 1;
}


double VecteurN::getCoord(const size_t & Coord) const {
    if(Coord > (v_.size()-1)) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v_[Coord];
}


//operations basiques utiles

void VecteurN::dimcheck(const VecteurN& v2) const {
    if (dim_ != v2.dim_){
        throw invalid_argument( "dimensions do not match" );
    }
}

bool VecteurN::operator==(const VecteurN& v2) const {
    dimcheck(v2);
    for(size_t i(0); i < v_.size(); ++i) {
        if (abs((v_)[i] - (v2.v_)[i]) > 1e-10) {
            return false;
        }
    }
    return true;
}

bool VecteurN::operator!=(const VecteurN& v2) const {
    return not (v_ == v2.v());
}
//op. mathématiques

VecteurN & VecteurN::operator+=(const VecteurN& v2) {

    dimcheck(v2);

    double * vect1pos(& v_[0]);
    const double * vect2pos(& v2.v_[0]);

    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) += (*vect2pos++);
        //(*v_)[i] += (*v2.v_)[i];
    }
    return *this;
}

VecteurN & VecteurN::operator-=(const VecteurN& v2) {
    dimcheck(v2);
    double * vect1pos(& v_[0]);
    const double * vect2pos(&v2.v_[0]);
    for(size_t i = 0; i < dim_; ++ i) {
        (*vect1pos++) -= (*vect2pos++);
    }
    return *this;
}
const VecteurN operator+(VecteurN v1, const VecteurN& v2) {
    v1 += v2;
    return v1;
};
const VecteurN operator-(VecteurN v1, const VecteurN& v2) {
    v1 -= v2;
    return v1;
};

VecteurN& VecteurN::operator*=(const double & scal) {
    for(double& i : v_) {
        i *= scal;
    }
    return *this;
}

const VecteurN VecteurN::operator-() const {
    return -1 * *this;
}

const VecteurN operator*(const double & scal, VecteurN vect) {
    vect *= scal;
    return vect;
}

double VecteurN::operator*(const VecteurN& v2) const {
    dimcheck(v2);
    double output(0);
    for(size_t i(0); i < dim_; ++i) {
        output += v_[i] * v2.v_[i];
    }
    return output;
}
double VecteurN::norm() const {
    return sqrt(*this * *this);
}
const VecteurN VecteurN::operator~() const {
    if(norm() < 1e-10) throw invalid_argument("vector to normalise has too small norm");
    return 1/norm() * *this;
};
VecteurN VecteurN::operator^(const VecteurN & vect2) const {
    if (dim_ != 3) throw invalid_argument("dimension of vector is not 3 (" + to_string(dim_) + ")");
    if (vect2.dim_ != 3) throw invalid_argument("dimension of input is not 3 (" + to_string(vect2.dim_) +")");
    VecteurN output(0.0, 0.0, 0.0);
    (output.v_)[0] = (v_)[1] * (vect2.v_)[2] - (v_)[2]*(vect2.v_)[1];
    (output.v_)[1] = (v_)[2]*(vect2.v_)[0] - (v_)[0]*(vect2.v_)[2];
    (output.v_)[2] = (v_)[0]*(vect2.v_)[1] - (v_)[1]*(vect2.v_)[0];
    return output;
}


double & VecteurN::operator[](const size_t& coord) { //read-write access
    return  (v_)[coord];
}

std::ostream& operator<<(std::ostream& out, const VecteurN & vect) {
    for(double i : vect.v_) out  << i << std::setw(15);
    out << std::setw(-15);
    return out;
}

const double& VecteurN::operator[](const size_t& coord) const {
    return v_[coord];
}









