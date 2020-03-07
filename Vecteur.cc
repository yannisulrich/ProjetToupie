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

//accès attributs
vector<double> Vecteur::getVect() const{
    return v;
}
unsigned int Vecteur::getDim() const {
    return dim;
}
double Vecteur::getCoord(const size_t & Coord) const {
    if(Coord > v.size()-1) {
        throw invalid_argument( "requested coord non-existant" );
    }
    return v[Coord];
}
void Vecteur::setVect(const vector<double> & input) {
    v = input;
}
//operations basiques
void Vecteur::augmente(const double & value) {
    v.push_back(value);
    dim += 1;
}
void Vecteur::set_coord(const size_t & coord, const double & value) {
    if(coord < 0) throw invalid_argument( "received negative value" );
    v[coord] = value;
}
void Vecteur::affiche() const {
    for(double i : v) {
        cout << i << " ";
    }
    cout << endl;
}

bool Vecteur::operator==(Vecteur const& v2) {
    if ( v.size() != v2.getDim()) {
        return false;
    }
    for(int i(0); i < v.size(); ++i) {
        if (abs(v[i]- v2.getVect()[i]) > 1e-10) {
            ++i;
            return false;
        }
    }
    return true;
}

//bool Vecteur::operator!=(Vecteur const& v2) {
    //return not (v == v2);
//}

//op. mathématiques
Vecteur Vecteur::addition(const Vecteur & vect2) const {
    Vecteur output({});
    output.setVect(v);
    for(size_t i = 0; i < dim; ++ i) {
        output.v[i] += vect2.v[i];
    }
    return output;
}
Vecteur Vecteur::soustraction(const Vecteur & vect2) const {
    Vecteur output({});
    output.setVect(v);
    for(size_t i = 0; i < dim; ++ i) {
        output.v[i] -= vect2.v[i];
    }
    return output;
}
Vecteur Vecteur::oppose() const {
    Vecteur output({});
    for(double i : v) {
        output.v.push_back(- i);
    }
    return output;
}
Vecteur Vecteur::mult(const double & scalar) const {
    Vecteur output({});
    for(double i : v) {
        output.v.push_back(scalar * i);
    }

    return output;
}
double Vecteur::prod_scal(const Vecteur & vect2) const {
    if (v.size() != vect2.getVect().size()) throw invalid_argument( "dimension of input does not equal dimension of vector" );
    double output(0);
    for(size_t i(0); i < dim; ++i) {
        output += v[i] * vect2.getVect()[i];
    }
    return output;
}
Vecteur Vecteur::prod_vect(const Vecteur & vect2) const {
    if (dim != 3) throw std::invalid_argument("dimension of vector is not 3 (" + to_string(dim) + ")");
    if (vect2.getDim() != 3) throw std::invalid_argument("dimension of input is not 3 (" + to_string(vect2.getDim()) +")");
    Vecteur output({0,0,0});
    output.v[0] = v[1]*vect2.v[2] - v[2]*vect2.v[1];
    output.v[1] = v[2]*vect2.v[0] - v[0]*vect2.v[2];
    output.v[2] = v[0]*vect2.v[1] - v[1]*vect2.v[0];
    return output;
}

double &Vecteur::operator[](size_t coord) {
    return this->v[coord];
}
ostream& operator<<(ostream& out, const Vecteur & vect) {
    for(double i : vect.getVect()) {
        out  << i << setw(10);
    }
    out << setw(-10);
    return out;
}