//
// Created by Yannis on 01.04.20.
//

#pragma once
#include "ConeSimple.h"
#include <iostream>
#include <QString>
#include <QResource>

class ConeSymFixe: public ConeSimple {
public:
    ConeSymFixe(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot,
                const double &L, const double &R, const double &m, const QString& modelpath = "", const bool& external = false):
            ConeSimple(support, P, P_dot, L, R, m)
            {

        if (!modelpath.isEmpty()) {
            _modelScale = {float(R), float(L), float(R)};
            if (external) model.loadNew(modelpath, ModelLoader::RelativePath);
            else model.loadNew("Graphics/OpenGLViewer/Models/" + modelpath, ModelLoader::RelativePath);
            _hasModel = true;
        }
    }

    [[nodiscard]] Vecteur5 f(const double & t) const override;
    [[nodiscard]] Vecteur5 f(const double & t, const Vecteur5& P, const Vecteur5& P_dot) const override;

    Vecteur4 returnIndicators() const override;

    void dessine() const override {
        support->dessine(*this); }

};

