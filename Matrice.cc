//
// Created by Yannis on 05.03.20.
//

#include "Matrice.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

Matrice::Matrice(std::initializer_list<double> const &v_0, std::initializer_list<double> const &v_1,
                 std::initializer_list<double> const &v_2) {
    m = {{0,0,0},{0,0,0},{0,0,0}};
    m[0] = v_0;
    m[1] = v_1;
    m[2] = v_2;
}
Matrice::Matrice(const double & m00, const double & m11, const double & m22) {
    m = {{0,0,0},{0,0,0},{0,0,0}};
    m[0][0] = m00;
    m[1][1] = m11;
    m[2][2] = m22;
}

double Matrice::get_value(const int &line, const int &col) const {
    return m[line][col];
}

Matrice& Matrice::operator+=(const Matrice & mat2) {
    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            m[i][j] += mat2.get_value(i,j);
        }
    }
    return *this;
}
Matrice& Matrice::operator-=(const Matrice &mat2) {
    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            m[i][j] += mat2.get_value(i,j);
        }
    }
    return *this;
}
Matrice Matrice::operator*(const Matrice & mat2) {
    Matrice output;
    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            for(size_t k(0); k < 3; ++k) {
                output(i,j) += m[i][k] * mat2.get_value(k,j);
            }
        }
    }
    return *this;
}
Vecteur Matrice::operator*(const Vecteur & vect) const {
    Vecteur output({m[0][0]*vect.getCoord(0)+m[0][1]*vect.getCoord(1)+m[0][2]*vect.getCoord(2),m[1][0]*vect.getCoord(0)+m[1][1]*vect.getCoord(1)+
                                                                                               m[1][2]*vect.getCoord(2),m[2][0]*vect.getCoord(0)+m[2][1]*vect.getCoord(1)+m[2][2]*vect.getCoord(2)});
    return output;
}
Matrice operator*(const double & scal, const Matrice & mat) {
    Matrice output;
    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            output(i,j) = mat.get_value(i,j) * scal;
        }
    }
    return output;
}
double& Matrice::operator()(const unsigned & line, const unsigned & col) {
    return this->m[line][col];
}
ostream& operator<<(ostream& out,const Matrice & mat) {
    out << "[";
    out << "[";
    out << mat.get_value(0,0) << setw(10) << mat.get_value(0,1) << setw(10) << mat.get_value(0,2);
    out << "]" << endl;
    out << " [";
    out << mat.get_value(1,0) << setw(10) << mat.get_value(1,1) << setw(10) << mat.get_value(1,2);
    out << "]" << endl;
    out << " [";
    out << mat.get_value(2,0) << setw(10) << mat.get_value(2,1) << setw(10) << mat.get_value(2,2);
    out << "]]" << endl;
    return out;
}
const Matrice operator+(Matrice mat1, const Matrice& mat2) {
    mat1 += mat2;
    return mat1;
}
const Matrice operator-(Matrice mat1, const Matrice& mat2) {
    mat1 -= mat2;
    return mat1;
}
double Matrice::det() const {
    return m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[1][0]*m[2][1]*m[0][2] -
            m[0][2]*m[1][1]*m[2][0] - m[0][1]*m[1][0]*m[2][2] - m[0][0]*m[2][1]*m[1][2];
}
Matrice Matrice::inv() {
    Matrice out;
    double det(this->det());
    if (abs(det) < 1e-5) return out;

    out(0, 0) = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) / det;
    out(0, 1) = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    out(0, 2) = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    out(1, 0) = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
    out(1, 1) = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    out(1, 2) = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) / det;
    out(2, 0) = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) / det;
    out(2, 1) = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) / det;
    out(2, 2) = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) / det;

    return out;
}
Matrice Matrice::transp() const {
    Matrice out;
    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            out(i,j) = m[j][i];
        }
    }
    return out;
}












