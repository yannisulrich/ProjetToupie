//
// Created by Yannis on 12.03.20.
//
#include "IntegrateurEulerCromer.h"
#include "ConeSimple.h"
#include <iostream>
#include <fstream>

using namespace std;
Vecteur f(const Vecteur&, const Vecteur&) {
    return Vecteur({0,-9.81});
}
int main() {
    FILE* gnuplotPipe = popen("gnuplot -persist","w");
    ofstream sortie;
    double dt = 0.01;
    sortie.open("gnuplotdata.txt", ios::out);
    ConeSimple cone(Vecteur({0,1}),Vecteur({1,3}), 1.0, 1.0, 0.127);
    cout << cone;
    cout << endl;
    IntegrateurEulerCromer integ(f);
    for(int t(0); t < 1.0/dt; ++t) {
        integ.integrate(cone, dt);
        cout << cone << endl;
        cone.imprimeFichierP(sortie);
    }

    fprintf(gnuplotPipe, "plot 'gnuplotdata.txt'\n");

    fflush(gnuplotPipe);
    fprintf(gnuplotPipe,"exit \n");   // exit gnuplot
    pclose(gnuplotPipe);
}
