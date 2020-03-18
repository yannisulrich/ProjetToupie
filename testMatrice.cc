#include "Vecteur.h"
#include "Matrice.h"
#include <iostream>
#include <chrono>
#include "Vecteur3.h"
using namespace std;
using namespace std::chrono;
int main() {
    Matrice I;
    Matrice diag(1., 2., 3.);
    Matrice mat({ 1, 1, 1 },
    { 2, 2, 2 },
    { 3, 3, 3 });
    Matrice mat2({ 1., 2., 0. },
    { 3., 4., 0 },
    { 0., 0., 1. });
    Vecteur v(5, 6, 7);
    Vecteur v2(1,2,3);
    Matrice mat3;

    auto start = high_resolution_clock::now();

    v += 2*v2;

    auto stop = high_resolution_clock::now();
    cout << v2 << endl;
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

    //following tests all work:
    /*
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
     */
    return 0;
};