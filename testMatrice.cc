#include "Vecteur.h"
#include "Matrice.h"
#include <iostream>
using namespace std;
int main() {
        Matrice I;
        Matrice diag(1., 2., 3.);
        Matrice mat({ 1.1, 1.2, 1.3 },
        { 2.1, 2.2, 2.3 },
        { 3.1, 3.2, 3.3 });
        Matrice mat2({ 1., 2., 0. },
        { 3., 4., 0 },
        { 0., 0., 1. });
        Vecteur v(5.5, 6.6, 7.7);

        cout << I.det()    << " "
        << diag.det() << " "
        << mat.det()  << " "
        << mat2.det() << endl;
        cout << I.inv()    << endl
        << diag.inv() << endl
        << mat.inv()  << endl
        << mat2.inv() << endl;

        cout << mat + mat << endl;
        cout << mat - mat << endl;
        cout << diag-I << endl;
        cout << 4.4 * diag << endl;
        cout << 2. * mat << endl;
        cout << mat * v << endl;
        cout << mat * mat << endl;
        cout << mat2 * mat2.inv() << endl;
        cout << mat.transp() << endl;
        return 0;
};