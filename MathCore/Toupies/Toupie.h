
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
    Vecteur5 P;
    Vecteur5 P_dot;

    Matrice Ig;
    double m;

    bool _hasModel = false; //la toupie a-t-elle un modèle 3D?
    QVector3D _modelScale {0,0,0}; //comment "Scale" le modèle en fonction des paramètres


    const std::string _type;

    mutable Model model;
public:



    Toupie(SupportADessin* support,
           const Vecteur5 P, const Vecteur5 P_dot, const Matrice &  Ig, const double& m, std::string  type):
           Dessinable(support), P(P), P_dot(P_dot), Ig(Ig),m(m), _type(std::move(type)), model(QString("blankmodel.dae"), ModelLoader::RelativePath)
           {}

    virtual ~Toupie() = default;

    bool hasModel() const {return _hasModel;}
    const QVector3D modelScale() const {return _modelScale;}
    std::string type() const {return _type;}

    [[nodiscard]] Matrice getIg() const;

    virtual void affiche(std::ostream&) const = 0;
    void afficheFile(std::ostream&) const;
    void afficheSimple(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream& out, const Toupie & toupie) {toupie.afficheSimple(out); return out;};

    [[nodiscard]] virtual Vecteur5 f(const double &t, const Vecteur5& P, const Vecteur5& P_dot) const = 0;

    [[nodiscard]] virtual Vecteur5 f(const double &t) const = 0;

    virtual Vecteur4 returnIndicators() const = 0;

    virtual Vecteur3 translationModel() const = 0;
};




