

#pragma once

#include "Toupie.h"
class TippeTopFriction: public Toupie {
private:
    double R;
    double h;
    double alpha;
    double mu;

public:

    TippeTopFriction(SupportADessin* support, const Vecteur5& P, const Vecteur5& P_dot, const double& R, const double& h, const double& mu, const double& m):
    R(R), h(h), mu(mu),alpha(3*h*h/(4*R*(R + h))),
    Toupie(support, P, P_dot, Matrice(m/5*(2 - 5*(3*h*h/(4*R*(R + h)))*(3*h*h/(4*R*(R + h))))*R*R + 0.45*m*h*h*(h - R)/(h + R),
    m/5*(2 - 5*(3*h*h/(4*R*(R + h)))*(3*h*h/(4*R*(R + h))))*R*R + 0.45*m*h*h*(h - R)/(h + R),
    ((m*(2*R - h)*(3*h*h + 3*h*R + 2*R*R))/(10*(h + R)))
    ), m, "Tippe Top") {
        if(h >= 2*R) std::__throw_invalid_argument("Attempted to initialize Tippe Top  with h > R");
    }

    [[nodiscard]] Vecteur5 f(const double & t) const override;
    [[nodiscard]] Vecteur5 f(const double & t, const Vecteur5& P, const Vecteur5& P_dot) const override;

    void affiche(std::ostream&) const override;




    void dessine() const override {
        support->dessine(*this); }
};



