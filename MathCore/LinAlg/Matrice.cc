//
// Created by Yannis on 05.03.20.
//

#include "Matrice.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
//constructeurs
Matrice::Matrice(array<double, 3> const &v_0, array<double, 3> const &v_1, array<double, 3> const &v_2):
    m{{v_0,v_1,v_2}}
{
}
Matrice::Matrice(const double & m00, const double & m11, const double & m22):
    m({m00,0,0,0,m11,0,0,0,m22})
{}


//accès en const, utilisé uniquement pour cette propriété.
double Matrice::get_value(const int &line, const int &col) const {
    return m[line][col];
}

//opérations mathématiques
//Nous utilisons ici une technique d'optimisation qui évite les méthodes d'accès des arrays et utilise des pointeurs mémoire,
//profitant de la structure array de la matrice.
//
Matrice& Matrice::operator+=(const Matrice & mat2) {
    double* matpos0 =  & m[0][0];
    const double* mat2pos0 =  & mat2.m[0][0];

    for(size_t i(0); i < 9; ++i) {
        (*matpos0++) += (*mat2pos0++);
    }

    return *this;
}
//idem +=
Matrice& Matrice::operator-=(const Matrice &mat2) {
    double* matpos0 =  & m[0][0];
    const double* mat2pos0 =  & mat2.m[0][0];

    for(size_t i(0); i < 9; ++i) {
        (*matpos0++) -= (*mat2pos0++);
    }
    return *this;
}

Matrice Matrice::operator*(const Matrice & mat2) {
    Matrice output;

    for(size_t i(0); i < 3; ++i) {
        for(size_t j(0); j < 3; ++j) {
            for(size_t k(0); k < 3; ++k) {
                output(i,j) += m[i][k] * mat2.m[k][j];
            }
        }
    }
    return output;
}
/*La fonction de multiplication d'un vecteur utilise les mêmes techniques d'optimisations que l'opérateur +=
 * Un avantage temporel est acquis ici encore acquis en calculant les trois composantes du vecteur d'un coup,
 * cet à dire que chaque valeur du vecteur et de la matrice n'est bien appelée en registre qu'une fois.
 * timing d'environ 17ns (moyenne sur 50'000 essais uniquement avec -funroll-loops, qui est possiblement redondant, et bien sûr que les défauts
 * de cache sont réduits au maximum par le compilateur).
*/
Vecteur3 Matrice::operator*(const Vecteur3 & vect) const {

    //auto start = high_resolution_clock::now();
    const double* matpos0 =  & m[0][0];
    const double* matpos1 =  & m[1][0];
    const double* matpos2 =  & m[2][0];

    double out0 = 0, out1 = 0, out2 = 0;

    const double * vectpos2 = & vect.v_[0];

    for (size_t j(0); j < 3; ++j) {
        out0 += (*matpos0++) * (*vectpos2);
        out1 += (*matpos1++) * (*vectpos2);
        out2 += (*matpos2++) * (*vectpos2++);
    }
    Vecteur3 output(out0, out1, out2);

    return output;
}

//même technique que ci dessus, les pointeurs mémoire itèrent sur les cases de l'array.
Matrice operator*(const double & scal, const Matrice & mat) {
    Matrice output;
    double * outpos = & output.m[0][0];
    const double * matpos = & mat.m[0][0];
    for(size_t i(0); i < 9; ++i) {
        *outpos++ = scal * (*matpos++);
    }
    return output;
}
double& Matrice::operator()(const unsigned & line, const unsigned & col) {
    return  m[line][col];
}
double Matrice::operator()(const unsigned &line, const unsigned &col) const {
    return m[line][col];
}
//méthode d'affichage, qui utilise setw de la bibiliothèque <iomanip> pour aligner les colonnes.
ostream& operator<<(ostream& out,const Matrice & mat) {
    out << "[[";
    out << setw(10) << mat.get_value(0,0) << setw(10) << mat.get_value(0,1) << setw(10) << mat.get_value(0,2);
    out << "]" << endl;
    out << " [";
    out << setw(10) << mat.get_value(1,0) << setw(10) << mat.get_value(1,1) << setw(10) << mat.get_value(1,2);
    out << "]" << endl;
    out << " [";
    out << setw(10) << mat.get_value(2,0) << setw(10) << mat.get_value(2,1) << setw(10) << mat.get_value(2,2);
    out << "]]" << endl;
    return out;
}
//Les calculs du déterminant et et de l'inverse sont largement suffisemment rapides aussi.
// Une optimisation est plus difficile (mais possible) ici, et pas nécessaire.
double Matrice::det() const {
    return m[0][0] * m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[1][0]*m[2][1]*m[0][2] -
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
            if(i == j) continue;
            out(i,j) = m[j][i];
        }
    }
    return out;
}














