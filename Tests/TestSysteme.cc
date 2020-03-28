//
// Created by Yannis on 28.03.20.
//
#include "MathCore.h"
#include "Graphics.h"
#include "Systeme.h"
#include <iostream>
#include <memory>
using namespace std;
int main() {

    auto cone1 = new ConeSimple(f, Vecteur5(0,1,0,0,0),Vecteur5(1,3,0,0,0), 1.0, 1.0, 0.127);
    auto cone2 = new ConeSimple(f, Vecteur5(0,2,0,0,0),Vecteur5(1,3,0,0,0), 1.0, 1.0, 0.127);

    Systeme systeme({cone1, cone2});
    //Systeme systeme({new ConeSimple(f, Vecteur5(0, 1, 0, 0, 0), Vecteur5(1, 3, 0, 0, 0), 1.0, 1.0, 0.127), new ConeSimple(f, Vecteur5(0, 1, 0, 0, 0), Vecteur5(1, 3, 0, 0, 0), 1.0, 1.0, 0.127)});

    cout << systeme << endl;

    //cone1.P[0] = 1;

    cout << systeme << endl;


}