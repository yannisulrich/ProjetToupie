//
// Created by Yannis on 12.03.20.
//
#include "All_Integrateurs.h"
#include "MathCore/Toupies/ConeSimple.h"
#include "VecteurArray.h"
#include "constantes.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


Vecteur5 sinus(const double & t, const Vecteur5& P_, const Vecteur5& P_dot_) {
    Vecteur5 out(-5*P_);
    out[0] = 0;
    return out;
}
int main() {


    FILE* gnuplotPipe = popen("gnuplot -persist","w");
    ofstream sortie;
    double dt = 0.001;
    double T = 4;
    double e = 0.001;
    unsigned int n = 0.05/dt;

    IntegrateurEulerCromer integEC;
    IntegrateurNewmark5 integN(e);
    IntegrateurRungeKutta5 integR;

    sortie.open("gnuplotdata.txt", ios::out);
    ConeSimple cone(f, Vecteur5(0,1,0,0,0),Vecteur5(1,3,0,0,0), 1.0, 1.0, 0.127);
    Vecteur5 v(0,1,1,0,0);
    auto start = high_resolution_clock::now();

    for(int t(0); t < T/(n*dt); ++t) {
        integR.integrateMultiple(n, cone, dt);
        //cout << cone << endl;
        cone.imprimeFichierP(sortie);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    //gnuplot

    fprintf(gnuplotPipe, "plot 'gnuplotdata.txt' using 1:2 w lp \n");
    fflush(gnuplotPipe);
    fprintf(gnuplotPipe,"exit \n");   // exit gnuplot
    pclose(gnuplotPipe);

}
