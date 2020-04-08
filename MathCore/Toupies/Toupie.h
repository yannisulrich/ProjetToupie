//
// Created by Yannis on 06.03.20.
//
#pragma once
#include "VecteurArray.h"
#include "Matrice.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <functional>
#include "Graphics/Graphics.h"
#include "Graphics/Dessinable.h"
#include "Graphics/SupportADessin.h"


class Toupie: public Dessinable {
protected:

    Matrice Ig;

    double m;
public:
    const std::string type;
    Vecteur5 P;
    Vecteur5 P_dot;

    Toupie(SupportADessin* support,
           const Vecteur5 P, const Vecteur5 P_dot, const Matrice &  Ig, const double& m, std::string  type):
           Dessinable(support), P(P), P_dot(P_dot), Ig(Ig),m(m), type(std::move(type)) {};

    virtual ~Toupie() = default;

    [[nodiscard]] Matrice getIg() const;
    [[nodiscard]] std::string getType() const;

    virtual void affiche(std::ostream&) const = 0;
    void afficheFile(std::ostream&) const;
    void afficheSimple(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream& out, const Toupie & toupie) {toupie.afficheSimple(out); return out;};

    [[nodiscard]] virtual Vecteur5 f(const double &t, const Vecteur5& P, const Vecteur5& P_dot) const = 0;

    [[nodiscard]] virtual Vecteur5 f(const double &t) const = 0;


};




