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

    ofstream file("/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Interface/SimOut.txt", ios::out);
    auto outFile = new FileViewer(file);
    auto outText = new TextViewer(cout);

    vector<SupportADessin*> v{outFile, outText};
    Simulator simulator(true, &integR, 60, 20, v);
    simulator.system->addSymCone(Vecteur5(0.5, 0, 0, 0, 0), Vecteur5(0, 0, 90, 0, 0), 2.0, 1.0, 10.27);
    //simulator.system->addSymModel(Vecteur5(0.5, 0, 0, 0, 0), Vecteur5(0, 0, 90, 0, 0), 0.6, 1.2, 4, "BakuMeaGan.dae");
    simulator.run();
}
