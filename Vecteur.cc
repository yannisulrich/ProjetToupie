//
// Created by Yannis on 27.02.20.
//

#include "Vecteur.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>

using namespace std;
//constructeurs
Vecteur::Vecteur(std::initializer_list<double> const& input) {
    v = input;
    dim = v.size();
}

//accès attributs.
vector<double> Vecteur::getVect() const{
    return v;
}
void Vecteur::setVect(const vector<double> & input) {
    v = input;
}

unsigned int Vecteur::getDim() const {
    return dim;
}
void Vecteur::augmente(const double & value) {
    v.push_back(value);
    dim += 1;
}

double Vecteur::getCoord(const size_t & Coord) const {
    if(Coord > v.size()-1) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v[Coord];
}
void Vecteur::set_coord(const size_t & coord, const double & value) {
    if(coord < 0) throw invalid_argument( "received negative value" );
    v[coord] = value;
}


//operations basiques utiles
void Vecteur::affiche() const {
    for(double i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void Vecteur::dimcheck(const Vecteur& v2) const {
    if (v.size() != v2.getDim()){
        throw invalid_argument( "dimensions do not match" );
    }
}

bool Vecteur::operator==(const Vecteur& v2) const {
    dimcheck(v2);
    for(size_t i(0); i < v.size(); ++i) {
        if (abs(v[i]- v2.getVect()[i]) > 1e-10) {
            ++i;
            return false;
        }
    }
    return true;
}

bool Vecteur::operator!=(const Vecteur& v2) const {
    return not (v == v2.getVect());
}

//op. mathématiques

Vecteur & Vecteur::operator+=(const Vecteur& v2) {
    dimcheck(v2);
    for(size_t i = 0; i < dim; ++ i) {
        v[i] += v2.v[i];
    }
    return *this;
}

Vecteur & Vecteur::operator-=(const Vecteur& v2) {
    dimcheck(v2);
    for(size_t i = 0; i < dim; ++ i) {
        v[i] -= v2.v[i];
    }
    return *this;
}
Vecteur& Vecteur::operator*=(const double & scal) {
    for(double& i : v) {
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
    for(size_t i(0); i < dim; ++i) {
        output += v[i] * v2.v[i];
    }
    return output;
}
Vecteur Vecteur::operator^(const Vecteur& vect2) const {
    if (dim != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim) + ")");
    if (vect2.getDim() != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.getDim()) +")");
    Vecteur output({0,0,0});
    output.v[0] = v[1]*vect2.v[2] - v[2]*vect2.v[1];
    output.v[1] = v[2]*vect2.v[0] - v[0]*vect2.v[2];
    output.v[2] = v[0]*vect2.v[1] - v[1]*vect2.v[0];
    return output;
}

double &Vecteur::operator[](size_t coord) { //read-write access
    return this->v[coord];
}

ostream& operator<<(ostream& out, const Vecteur & vect) {
    for(double i : vect.getVect()) {
        out  << i << setw(10);
    }
    out << setw(-10);
    return out;
}



