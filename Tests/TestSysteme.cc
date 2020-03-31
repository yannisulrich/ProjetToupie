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

    auto output = new TextViewer(cout);

    auto cone1 = new ConeSimple(output, f, Vecteur5(0,1,0,0,0),Vecteur5(1,3,0,0,0), 1.0, 1.0, 0.127);
    auto cone2 = new ConeSimple(output, f, Vecteur5(0,2,0,0,0),Vecteur5(1,3,0,0,0), 1.0, 1.0, 0.127);

    Systeme systeme({cone1, cone2}, output);
    //Systeme systeme({new ConeSimple(f, Vecteur5(0, 1, 0, 0, 0), Vecteur5(1, 3, 0, 0, 0), 1.0, 1.0, 0.127), new ConeSimple(f, Vecteur5(0, 1, 0, 0, 0), Vecteur5(1, 3, 0, 0, 0), 1.0, 1.0, 0.127)});

    systeme.dessine();

    cone1->P[0] = 1;

    systeme.dessine();
    cone1->dessine();
}