//
// Created by Yannis on 12.03.20.
//
#include "IntegrateurEulerCromer.h"
#include "ConeSimple.h"
#include "VecteurArray.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

Vecteur5 f(const Vecteur5&, const Vecteur5&) {
    return Vecteur5({0,-9.81,0,0,0});
}
int main() {
    FILE* gnuplotPipe = popen("gnuplot -persist","w");
    ofstream sortie;
    double dt = 0.001;
    sortie.open("gnuplotdata.txt", ios::out);
    ConeSimple cone(Vecteur5({0,1,0,0,0}),Vecteur5({1,3,0,0,0}), 1.0, 1.0, 0.127);
    cout << cone;
    cout << endl;
    IntegrateurEulerCromer5 integ(f);
    auto start = high_resolution_clock::now();
    for(int t(0); t < 1.0/dt; ++t) {
        integ.integrate(cone, dt);
        //cout << cone << endl;
        cone.imprimeFichierP(sortie);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;


    fprintf(gnuplotPipe, "plot 'gnuplotdata.txt' using 1:2 w lp \n");

    fflush(gnuplotPipe);
    fprintf(gnuplotPipe,"exit \n");   // exit gnuplot
    pclose(gnuplotPipe);
}
