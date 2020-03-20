
/*
Classe Matrice
Cette classe enveloppe une array 3x3 deux dimensionnelle de doubles, qu'on appelle m. Cet attribut est privé, afin d'uniquement le manipuler
avec les méthodes prévues.

Des constructeurs sont fournis pour initialiser à base de:
Rien, construit une matrice vide.
Toutes valeurs configurables
Trois valeurs, qui définissent alors les valeurs de la diagonale. Le reste est mis à 0.

get_value sert à accéder les valeurs, et est déclaré const. Cet attribut est privé car il ne sert que dans l'écriture de methodes internes, et
l'utilisateur de la classe peut utiliser l'opérateur() surchargé:

L'opérateur () est surchargé pour accéder aux valeurs en read/write. Il prend comme argument la ligne et la colonne (dans cet ordre)
 souhaitée et retourne une référence sur double (double&).

Les operateurs += et -= sont surchargés et font ce à quoi on s'attend.
Les operateurs +, -, * sont aussi implémentés. + et - utilisent les définitions de += et -=.

La multiplication d'une matrice par un scalaire (double) est possible par opérateur * surchargé. Cette fonction est un friend
 pour garder le scalaire à gauche.

La multiplication d'un vecteur par un objet matrice est possible (Matrice * Vecteur, dans cet ordre).

Il est possible de calculer la transposée, le déterminant, et l'inverse d'une matrice, avec retour d'un nouvel objet pour
l'inverse et la transposée.

Enfin, l'opérateur d'affichage << est surchargé.

Afin d'éviter le plus d'erreurs possibles, cette classe essaie d'être le plus "const-correct" possible, et utilise [[nodiscard]].
*/


#pragma once
#include <array>
#include "Vecteur.h"
#include <initializer_list>
class Matrice {
private:
    std::array<std::array<double, 3 >, 3 > m;
    [[nodiscard]] double get_value(const int &, const int &) const; //accès en read-only i.i. const
public:
    //constructeurs
    Matrice(): m({0,0,0,0,0,0,0,0,0}) {} //Matrice vide
    Matrice(const std::array<double, 3> &v_0, const std::array<double, 3> &v_1, const std::array<double, 3> &v_2); //initialisation avec valeurs configurables partout
    Matrice(const double & m11, const double & m22, const double & m33); //matrices diagonales

    double& operator()(const unsigned & line, const unsigned & col); //accès aux éléments read write

    Matrice& operator+=(const Matrice &); //surcharge des opérateurs élémentaires
    Matrice& operator-=(const Matrice &);
    [[nodiscard]] Matrice operator*(const Matrice &);

    friend Matrice operator*(const double &, const Matrice &);

    [[nodiscard]] Vecteur<std::array<double, 3>> operator*(const Vecteur<std::array<double, 3>> &) const;
    [[nodiscard]] Vecteur<std::vector<double>> operator*(const Vecteur<std::vector<double> > & vect) const;

    [[nodiscard]] Matrice transp() const;
    [[nodiscard]] double det() const;
    [[nodiscard]] Matrice inv();

    friend std::ostream& operator<<(std::ostream&, const Matrice &);
};

[[nodiscard]] inline const Matrice operator+(Matrice mat1, const Matrice& mat2) { //TODO: find way to put these functions in source file
    mat1 += mat2;
    return mat1;
};

[[nodiscard]] inline const Matrice operator-(Matrice mat1, const Matrice& mat2) {
    mat1 -= mat2;
    return mat1;
};



