//
// Created by Yannis on 28.03.20.
//
#include "Integrateurs/All_Integrateurs.h"
#include "FileViewer/FileViewer.h"
#include "TextViewer/TextViewer.h"
#include "System/Systeme.h"
#include <iostream>
#include <memory>
#include <chrono>
#include <typeinfo>
using namespace std;
using namespace std::chrono;
int main() {
    
    ofstream file("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt", ios::out);
    //file.open("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt", ios::app);

    FILE* gnuplotPipe = popen("gnuplot -persist","w");
    double dt = 0.01;
    double T = 10;
    double e = 0.0001;
    unsigned int n = 0.01/dt;

    IntegrateurEulerCromer integEC;
    IntegrateurNewmark5 integN(e);
    IntegrateurRungeKutta5 integR;


    auto outFile = new FileViewer(file);
    auto outText = new TextViewer(cout);

    TippeTopRolls test(outText, Vecteur5(0.5, 0, 0, 0, 0), Vecteur5(0.05, 0.01, 60, 0, 0), 2.0, 1.0, 0.127);


    Systeme systeme(outFile, &integN);

    systeme.addSymCone(Vecteur5(0.5, 0, 0, 0, 0), Vecteur5(0.05, 0, 60, 0, 0), 1.0, 1.0, 0.127);
    systeme.addTippeTopFriction(Vecteur5(0.1,0,0,0,0),Vecteur5(0,0,60,0,0), 0.02, 0.0036186, 0.5, 0.13387373);

    //cout << systeme.getToupies()[0]->getIg() << endl;

    cout << systeme;

    cout << "start" << endl;
    auto start = high_resolution_clock::now();

    for(int t(0); t < T/(n*dt); ++t) {
        systeme.integrateMultiple(n, dt);
        systeme.dessine();
        //systeme.dessine(outText);
    }
    auto stop = high_resolution_clock::now();

    cout << systeme;


    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    //gnuplot
    system("grep ' # 1' /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt "
           "> /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep1.txt");
    system("grep ' # 2' /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt "
           "> /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep2.txt");

    fprintf(gnuplotPipe, "plot '/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep2.txt' using ($0/100.):1 w lp");
    //fprintf(gnuplotPipe, ",'/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep1.txt' using ($0/1000.):1 w lp");
    fprintf(gnuplotPipe, "\n");
    fflush(gnuplotPipe);
    fprintf(gnuplotPipe,"exit \n");   // exit gnuplot
    pclose(gnuplotPipe);

    return 0;
}