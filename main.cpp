#include <iostream>
#include "Vecteur.h"
using namespace std;
int main() {
    Vecteur vect1({1.0, 2.0, -1.0});
    Vecteur vect2({1.2, 2.0, -1.0});
    Vecteur vect3(vect1.prod_vect(vect2));


    cout << "Vecteur 1 : "; vect1.affiche();
    cout << endl;
    cout << "Vecteur 2 : "; vect2.affiche();
    cout << endl;
    cout << "Vecteur 3 : "; vect3.affiche();
    cout << endl;
    cout << "Le vecteur 1 est ";
    if (vect1.compare(vect2, 0.1)) {
        cout << "égal au"; }
    else {
        cout << "différent du"; }
    cout << " vecteur 2," << endl << "et est ";
    if (vect1.compare(vect3, 0.1)) {
        cout << "égal au"; }
    else {
        cout << "différent du"; }
    cout << " vecteur 3." << endl;

}
