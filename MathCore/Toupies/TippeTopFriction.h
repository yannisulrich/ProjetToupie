
//tippe top de http://www.becher.itp.unibe.ch/tippetop/TippeTop.pdf
#pragma once

#include "Toupie.h"
#include "../Integrateurs/LSODA/LSODA.h"
#include <vector>
#include <initializer_list>
class TippeTopFriction: public Toupie {
private:
    double t = 0;

    double R;
    double epsilon;
    double mu;
    int istate = 1;


    double data[6];

    LSODA lsoda;
    vector<double> all_params_i;
    vector<double> all_params_live;

public:

    TippeTopFriction(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot, const double& R, const double& epsilon, const double& mu, const double& m):
    Toupie(support, P, P_dot,
            Matrice(m/5*(2 - 5*(3*epsilon*epsilon/(4*R*(R + epsilon)))*(3*epsilon*epsilon/(4*R*(R + epsilon))))*R*R + 0.45*m*epsilon*epsilon*(epsilon - R)/(epsilon + R),
    m/5*(2 - 5*(3*epsilon*epsilon/(4*R*(R + epsilon)))*(3*epsilon*epsilon/(4*R*(R + epsilon))))*R*R + 0.45*m*epsilon*epsilon*(epsilon - R)/(epsilon + R),
    ((m*(2*R - epsilon)*(3*epsilon*epsilon + 3*epsilon*R + 2*R*R))/(10*(epsilon + R)))),
    m,
    "Tippe Top Inverseur"),R(R), epsilon(epsilon), mu(mu),
    data{R, epsilon, mu, m, Ig(0,0), Ig(2,2)}
    {
        all_params_i = {P.getCoord(0),P.getCoord(1),P.getCoord(2),P.getCoord(3),P.getCoord(4) , P_dot.getCoord(0),P_dot.getCoord(1),P_dot.getCoord(2),P_dot.getCoord(3),P_dot.getCoord(4)};
        if(epsilon >= 2*R) std::__throw_invalid_argument("Attempted to initialize Tippe Top  with epsilon > R");
    }

    static void accels( double t, double* p, double* pdot, void* data);
    int update(const double&);

    void affiche(std::ostream&) const override;
    [[nodiscard]] Vecteur5 f(const double &) const override {return Vecteur5(0,0,0,0,0);};
    [[nodiscard]] Vecteur5 f(const double &, const Vecteur5&, const Vecteur5&) const override {return Vecteur5(0,0,0,0,0);};

    Vecteur4 returnIndicators() const override;

    Vecteur3 translationModel() const override;

    void dessine() const override {
        support->dessine(*this); }
};



