
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
#include "Trace.h"



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


    std::string _type;

    mutable Model model;

    Trace<200> TraceG;
    Trace<200> TraceA;
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

    virtual void addToTraces() = 0; //ajouter les points A et G aux traces




};




