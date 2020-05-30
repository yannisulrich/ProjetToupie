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
using namespace std;
using namespace std::chrono;
int main() {

    ofstream file("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt", ios::out);
    //file.open("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutput.txt", ios::app);

    FILE* gnuplotPipe = popen("gnuplot -persist","w");
    ofstream sortie;
    double dt = 0.001;
    double T = 10;
    double e = 0.001;
    unsigned int n = 0.05/dt;

    IntegrateurEulerCromer integEC;
    IntegrateurNewmark5 integN(e);
    IntegrateurRungeKutta5 integR;


    auto outFile = new FileViewer(file, false);
    auto outText = new TextViewer(cout);

    ConeSymFixe test(outText, Vecteur5(0.5,0,0,0,0),Vecteur5(0,0,60,0,0), 1.0, 1.0, 0.127);
    cout << test.getIg() << endl;
    Systeme systeme(outFile, &integR);

    systeme.addSymCone(Vecteur5(0.5, 0, 0, 0, 0), Vecteur5(0, 0, 60, 0, 0), 1.0, 1.0, 0.127);

    //cout << systeme.getToupies()[0]->getIg() << endl;

    cout << systeme;

    cout << "start" << endl;
    auto start = high_resolution_clock::now();

    for(int t(0); t < T/(n*dt); ++t) {
        systeme.integrateMultiple(n, dt);
        systeme.dessine();
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

    fprintf(gnuplotPipe, "plot '/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep1.txt' "
                         "using ($0/20.):1 w lp, '/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/P9/SystemeOutputGrep1.txt' using ($0/20.):2 w lp \n");
    fflush(gnuplotPipe);
    fprintf(gnuplotPipe,"exit \n");   // exit gnuplot
    pclose(gnuplotPipe);

    return 0;
}