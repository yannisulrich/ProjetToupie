#include "Vecteur.h"
#include "Matrice.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main() {

    typedef Vecteur<vector<double> > VecteurN;
    typedef Vecteur<array<double, 3> > Vecteur3;
    Matrice I;
    Matrice diag(1., 2., 3.);
    Matrice mat({ 1.01, 0.02, 0.03 },
    { 0.02, 0.021, 0.031 },
    { 0.052, 0.02, 0.013 });

    Matrice mat2({ 1, 0.02, 0.02 },
    { 0.03, 1., 0.01 },
    { 0.10, 0.02, 1.045 });

    Vecteur3 v(5, 6, 7);
    Vecteur3 v2(0.1,0.2,0.3);
    v2 = mat*v2;
    auto start = high_resolution_clock::now();
    start = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();
    cout << mat << endl;
    //cout << v2 << endl;
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

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