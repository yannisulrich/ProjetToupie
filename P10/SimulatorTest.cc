/*
 * Nous avions déjà quasiment fait l'interface graphique lors de l'apparition de la question P10 (nous les avons pas à
 * l'avance). Voici donc un exemple d'utilisation fait lors de la semaine du problème P10.
 */

#include <iostream>
#include "MathCore.h"
#include "Simulator/Simulator.h"
#include "FileViewer/FileViewer.h"
#include "TextViewer/TextViewer.h"
using namespace std;


int main() {
    IntegrateurRungeKutta5 integR;
    IntegrateurNewmark5 integN(0.001);
    ofstream file("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Interface/SimOut.txt", ios::out);
    auto outFile = new FileViewer(file);
    auto outText = new TextViewer(cout);

    vector<SupportADessin*> v{};
    Simulator simulator(true, &integR, 60, 100, v, 1);
    simulator.system->addSymCone(Vecteur5(0.01, 0, 0, 0, 0), Vecteur5(0, 0, 0, 0, 0), 2, 0.9, 4000);
    //simulator.system->addSymCone(Vecteur5(0.2, 0, 0, 4, 4), Vecteur5(0, 0, 90, 0, 0), 4.0, 1.0, 10.27);
    //simulator.system->addSymModel(Vecteur5(0.5, 0, 0, 4, 4), Vecteur5(0, 0, 90, 0, 0), 0.6, 1.2, 4, "BakuMeaGan.DAE");
    //simulator.system->addTippeTopRolls(Vecteur5(0.1, 0.01, 0.01, 0, 0), Vecteur5(0.01, -10, 40, 0, 0), 1, 0.5, 2000);
    //simulator.system->addTippeTopFriction(Vecteur5(0.03,0,0,0,0),Vecteur5(0,0,90,0,0), 0.02, 0.0036186, 0.5, 0.13387373);
    //simulator.system->addSymConeGlisse(Vecteur5(0.05, 0, 0.00000, 0, 0), Vecteur5(0, 0, 100, 0, 0.09), 0.03, 0.02, 0.008, 0.01);
    //simulator.system->addTippeTopRolls(Vecteur5(0.1, 0.01, 0.01, 0, 0), Vecteur5(0.01, 0.01, 60, 0, 0), 0.001, 0.0005, 0.007);

    simulator.runNewApp();


}
