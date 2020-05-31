/*
 * Equations pour une toupie glissante. Attention! le fichier .cc fait presque 3000 lignes (chez moi c'est un peu lent).
 * Les équations sont adaptées et modifiées, mais faites à partir de https://rotations.berkeley.edu/the-poisson-top-with-friction/#Equations_of_motion.
 * Les indicateurs sont correctement implémentés par rapport à ce site.
 */

#pragma once

#include "ConeSimple.h"
#include "../Integrateurs/LSODA/LSODA.h"
#include <vector>
class ConeSymGlisse: public ConeSimple {
private:
    double t = 0;
    double m, muk, L3, r, lambdaa, lambdat;
    double data[5];
    int istate = 1;

    LSODA lsoda;
    vector<double> all_params_i;
    vector<double> all_params_live;
public:
    ConeSymGlisse(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot,
    const double &r, const double &L3, const double &m, const double &muk, const QString& modelpath = "", const bool& external = false):
    ConeSimple(support, P, P_dot, L3, r, m), m(m),  muk(muk), L3(L3), r(r), lambdaa(0.5*m*r*r), lambdat(0.25*m*r*r), data{m, muk, L3, lambdaa, lambdat}
    {
        all_params_i = {P.getCoord(0),P.getCoord(1),P.getCoord(2),P.getCoord(3),P.getCoord(4) , P_dot.getCoord(0),P_dot.getCoord(1),P_dot.getCoord(2),P_dot.getCoord(3),P_dot.getCoord(4)};
        _type = "Cone Glissant";

        if (!modelpath.isEmpty()) {
            _modelScale = {float(r), float(L3), float(r)};
            if (external) model.loadNew(modelpath, ModelLoader::AbsolutePath);
            else model.loadNew("Graphics/OpenGLViewer/Models/" + modelpath, ModelLoader::RelativePath);
            _hasModel = true;
        }
        Ig(0,0) = lambdat;
        Ig(1,1) = lambdat;
        Ig(2,2) = lambdaa;

    }

    static void accels( double t, double* p, double* pdot, void* data);
    int update(const double&);

    void affiche(std::ostream&) const override;


    [[nodiscard]] Vecteur5 f(const double &) const override {return Vecteur5(0,0,0,0,0);};
    [[nodiscard]] Vecteur5 f(const double &, const Vecteur5&, const Vecteur5&) const override {return Vecteur5(0,0,0,0,0);};

    void dessine() const override {
        support->dessine(*this); }

    Vecteur4 returnIndicators() const override;
    
    

};


