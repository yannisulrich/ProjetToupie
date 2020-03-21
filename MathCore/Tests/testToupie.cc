//
// Created by Yannis on 11.03.20.
//

#include "ConeSimple.h"
#include <iostream>
using namespace std;


int main() {
    Vecteur x({1,2,3});
    Toupie toupie1(Vecteur({0,0,0}), Vecteur({0,0,0}), Matrice(1,1,1));
    ConeSimple cone1(Vecteur({0,0,0}), Vecteur({0,0,0}), 3, 4, 5);

    //cout << toupie1 << endl;
    //cout << "test";
    cout << cone1;


    return 0;
}
