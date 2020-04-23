//
// Created by Yannis on 11.03.20.
//

#include "ConeSymFixe.h"
#include <iostream>
using namespace std;


int main() {
    SupportVide suppvide;
    ConeSymFixe cone1(&suppvide,Vecteur5(1,2,3,4,5), Vecteur5(6,7,8,9,10), 3, 4, 5);

    //cout << toupie1 << endl;
    //cout << "test";
    cout << cone1;


    return 0;
}
