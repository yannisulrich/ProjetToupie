//
// Created by tanis on 07/03/2020.
//

#include <iostream>
#include "Vecteur.h"
#include "VecteurArray.h"

using namespace std;
int main() {
// un vecteur en 3D :
    VecteurN vect1(1.0, 0.0, 0.0);

// un autre vecteur en 3D
    VecteurN vect2(0.0, 1.0,  0.0);

    VecteurN vect3(vect1);  // copie de V1
    VecteurN vect4(4);      // le vecteur nul en 4D

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
    VecteurN vect5(vect1+vect2);
    //vect1[1] = 3;
    //cout << vect1 << endl;
    //cout << - vect1 << endl;
    //cout << vect5 << endl;
    cout << (vect2^vect1) << endl;

    cout << "Maintenant la même chose avec la classe VecteurArray: " << endl;

    // un vecteur en 3D :
    Vecteur3 vect6(1.0, 0.0, 0.0);

// un autre vecteur en 3D
    Vecteur3 vect7(0.0, 1.0,  0.0);

    Vecteur3 vect8(vect6);  // copie de V1
    Vecteur3 vect9;      // le vecteur nul en 3D
    const Vecteur3 vect10;
    cout << vect10[3] << endl; //test du lecteur const
    cout << "Vecteur 6 : " << vect6 << endl;
    cout << "Vecteur 7 : " << vect7 << endl;
    cout << "Vecteur 8 : " << vect8 << endl;
    cout << "Vecteur 9 : " << vect9 << endl;

    cout << "Le vecteur 6 est ";
    if (vect6 == vect7) {
        cout << "égal au";
    } else {
        cout << "différent du";
    }
    cout << " vecteur 7," << endl << "et est ";
    if (vect6 != vect8) {
        cout << "différent du";
    } else {
        cout << "égal au";
    }
    cout << " vecteur 8." << endl;
    //cout << 2*vect3 << endl;
    //vect1 += 2*vect3;
    //cout << vect1 + vect2 << endl;
    Vecteur3 vect10(vect6+vect7);
    //vect1[1] = 3;
    //cout << vect1 << endl;
    //cout << - vect1 << endl;
    //cout << vect5 << endl;
    cout << (vect7^vect6);
}
