#include "VecteurArray.h"
#include "Vecteur.h"
#include "Matrice.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main() {

    Matrice I;
    Matrice diag(1., 2., 3.);
    Matrice mat({ 1.002, 0.002, 0.003 },
    { 0.002, 1.001, 0.0031 },
    { 0.0052, 0.002, 1.0013 });

    Matrice mat2({ 1, 0.02, 0.02 },
    { 0.03, 1., 0.01 },
    { 0.10, 0.02, 1.045 });

    Vecteur3 v(0., 1., 0.);
    Vecteur5 v2(1,2,3,4,5);
    VecteurN v3({1,2,2});
    Vecteur3 v4(1,0,0);
    VecteurArray<array<double, 4> > v5({1,2,3,4});
    cout << (v^v4) << endl;
    v4[1]=2;
    cout << v4;
    //cout << v3.norm() << "     " << v2.norm() << endl;
    /*
    cout << ~v << endl;
    cout << 2*v3 << endl;
    cout << v << endl;
     */
    //Vecteur5 v2({0.00000001,0.00000002,0.0000003,1,2});
    //v2 = 2*v2;
    //cout << v2 << endl;

    /*
    int n = 50000;
    auto start = high_resolution_clock::now();
    start = high_resolution_clock::now();
    for(size_t i(0); i <n; ++i) {
        v2 = mat*v2;
    }

    auto stop = high_resolution_clock::now();
    cout << v2 << endl;
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count()/double(n) << " nanoseconds" << endl;
    */
    //following tests all work as of 19/03, last major changes
    /*
    cout << I.det()    << " "
    << diag.det() << " "
    << mat.det()  << " "
    << mat2.det() << endl;
    cout << I.inv()    << endl
    << diag.inv() << endl
    << mat.inv()  << endl
    << mat2.inv() << endl;

    //Matrice mat3(mat+mat);
    //cout << mat3 << endl;
    cout << "mat + mat" << endl;
    cout << mat + mat << endl;
    cout << "mat - mat" << endl;
    cout << mat - mat << endl;
    cout << "diag - I" << endl;
    cout << diag-I << endl;
    cout << "4.4 * diag" << endl;
    cout << 4.4 * diag << endl;
    cout << "2 * mat" << endl;
    cout << 2. * mat << endl;
    cout << "mat * v" << endl;
    cout << mat * v << endl;
    cout << "mat * mat" << endl;
    cout << mat * mat << endl;
    cout << "mat2 * mat2.inv()" << endl;
    cout << mat2 * mat2.inv() << endl;
    cout << "mat transp" << endl;
    cout << mat.transp() << endl;
    */
    return 0;
};