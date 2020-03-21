//
// Created by tanis on 07/03/2020.
//

#include <iostream>
#include "VecteurArray.h"

using namespace std;
int main() {
// un vecteur en 3D :
    Vecteur vect1(1.0, 0.0, 0.0);

// un autre vecteur en 3D
    Vecteur vect2(0.0, 1.0,  0.0);

    Vecteur vect3(vect1);  // copie de V1
    Vecteur vect4(4);      // le vecteur nul en 4D

    cout << "Vecteur 1 : " << vect1 << endl;
    cout << "Vecteur 2 : " << vect2 << endl;
    cout << "Vecteur 3 : " << vect3 << endl;
    cout << "Vecteur 4 : " << vect4 << endl;

    cout << "Le vecteur 1 est ";
    if (vect1 == vect2) {
        cout << "égal au";
    } else {
        cout << "différent du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if (vect1 != vect3) {
        cout << "différent du";
    } else {
        cout << "égal au";
    }
    cout << " vecteur 3." << endl;
    //cout << 2*vect3 << endl;
    //vect1 += 2*vect3;
    //cout << vect1 + vect2 << endl;
    Vecteur vect5(vect1+vect2);
    //vect1[1] = 3;
    //cout << vect1 << endl;
    //cout << - vect1 << endl;
    //cout << vect5 << endl;
    cout << (vect2^vect1);
}
