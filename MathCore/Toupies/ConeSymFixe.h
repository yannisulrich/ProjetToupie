//
// Created by Yannis on 01.04.20.
//

#pragma once
#include "ConeSimple.h"
#include "LinAlg/constantes.h"
#include <iostream>
#include <QString>
#include <QResource>

class ConeSymFixe: public ConeSimple {
public:
    ConeSymFixe(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot,
                const double &C1, const double &C2, const double &m, const QString& modelpath = "", const bool& Custom = false):
            ConeSimple(support, P, P_dot, C1, C2, m)
            {
        //Custom signifie un modèle custom. Si ce n'est pas le cas, C1 et C2 servent simplement de longueur et rayon resp.
        //Sinon, ils servent de moment d'intertie I1 et I3 resp.
        if(!Custom) {
            if (!modelpath.isEmpty()) {
                _modelScale = {float(C2), float(C1), float(C2)};
                model.loadNew("Graphics/OpenGLViewer/Models/" + modelpath, ModelLoader::RelativePath);
                _hasModel = true;
            }
        }
        else {
            if (!modelpath.isEmpty()) {
                _modelScale = {1, 1, 1};
                model.loadNew("Graphics/OpenGLViewer/Models/" + modelpath, ModelLoader::RelativePath);
                _hasModel = true;
                Ig(0,0) = C1;
                Ig(1,1) = C1;
                Ig(2,2) = C2;
            }
        }
    }

    [[nodiscard]] Vecteur5 f(const double & t) const override;
    [[nodiscard]] Vecteur5 f(const double & t, const Vecteur5& P, const Vecteur5& P_dot) const override;

    void dessine() const override {
        support->dessine(*this); }

};

