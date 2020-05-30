/*
 * classe virtuelle principale des toupies.
 */



#pragma once
#include "LinAlg/VecteurArray.h"
#include "LinAlg/Matrice.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <functional>
#include <QVector3D>
#include "Graphics/Dessinable.h"
#include "Graphics/SupportADessin.h"
#include "Graphics/OpenGLViewer/model.h"


class Toupie: public Dessinable {
    friend class Scene;
    friend class IntegrateurEulerCromer;
    template <int n>
    friend class IntegrateurNewmark;
    template <int n>
    friend class IntegrateurRungeKutta;


protected:

    mutable double cosTheta = 0, sinTheta = 0, sinPsi = 0, cosPsi = 0,sinPhi = 0, cosPhi = 0, thetadot = 0, psidot = 0, phidot = 0, xdot = 0, ydot = 0; //utilisé pour le calcul des indicateurs
    //Ils sont mutable car modifiés pendant le calcul des indicateurs.
    Vecteur5 P; //paramètres (theta, psi, phi, x, y)
    Vecteur5 P_dot; //dérivée des paramètres

    Matrice Ig; //matrice d'intertie en G
    double m; //masse

    bool _hasModel = false; //la toupie a-t-elle un modèle 3D?
    QVector3D _modelScale {0,0,0}; //comment "Scale" le modèle en fonction des paramètres


    std::string _type; //le type de toupie

    mutable Model model; //le modèle

    std::vector<bool> plots = {false,false,false,false}; //indique quels graphiques des indicateurs constants doivent être affiché
public:



    Toupie(SupportADessin* support,
           const Vecteur5 P, const Vecteur5 P_dot, const Matrice &  Ig, const double& m, std::string  type):
           Dessinable(support), P(P), P_dot(P_dot), Ig(Ig),m(m), _type(std::move(type)), model(QString("blankmodel.dae"), ModelLoader::RelativePath)
           {}

    virtual ~Toupie() = default;

    bool hasModel() const {return _hasModel;} //accesseurs triviaux
    const QVector3D modelScale() const {return _modelScale;}
    std::string type() const {return _type;}

    [[nodiscard]] Matrice getIg() const;

    virtual void affiche(std::ostream&) const = 0; //affichages apropriés à chaque support
    void afficheFile(std::ostream&) const;
    void afficheSimple(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream& out, const Toupie & toupie) {toupie.afficheSimple(out); return out;}; //affichage complet

    [[nodiscard]] virtual Vecteur5 f(const double &t, const Vecteur5& P, const Vecteur5& P_dot) const = 0; //fonction d'évolution, en fonction de paramètres arbitraires

    [[nodiscard]] virtual Vecteur5 f(const double &t) const = 0; //idem, paramètres de la toupie

    virtual Vecteur4 returnIndicators() const = 0; //les indicateurs constants (ou non) du support mathématique

    virtual QVector3D translationModel() const = 0; //vecteur de translation pour la représentation en 3D, propre au type de toupie

    virtual Vecteur3 getGTrace() const = 0; //les traces de A et G
    virtual Vecteur3 getATrace() const = 0;

    void setPlots(const bool& p1, const bool& p2, const bool& p3, const bool& p4) {plots = {p1, p2, p3, p4};} //définit quels graphiques il faut montrer dans l'application principale
    std::vector<bool> getPlots() const {return plots;}
};




