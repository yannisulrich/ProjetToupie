//
// Created by Yannis on 27.02.20.
//

#ifndef PROJETTOUPIE_VECTEUR_H
#define PROJETTOUPIE_VECTEUR_H

#include <vector>
using namespace std;
class Vecteur {
private:
    vector<double> v;
    int dim;
public:
    explicit Vecteur(const vector<double> &input); //constructeurs
    Vecteur(const Vecteur &input);

    vector<double> getVect() const; //accès aux attributs
    void setVect(const vector<double> & input);
    int getDim() const;

    void augmente(double value); //operations basiques
    void set_coord(int coord, double value);
    void affiche() const;
    bool compare(const Vecteur & v2) const;

    Vecteur addition(const Vecteur & vect2) const; //operation mathématiques
    Vecteur soustraction(const Vecteur& vect2) const;
    Vecteur oppose() const;
    Vecteur mult(const double & scalar) const;
    double prod_scal(const Vecteur & vect2) const;
    Vecteur prod_vect(Vecteur vect2) const;



};


#endif //PROJETTOUPIE_VECTEUR_H
