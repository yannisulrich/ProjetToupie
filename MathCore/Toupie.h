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
#include "../Graphics/Graphics.h"
#include "../Graphics/Dessinable.h"
#include "../Graphics/SupportADessin.h"

class Toupie: public Dessinable {
protected:
    Matrice Ig;
    const std::function<Vecteur5(const double & t, const Vecteur5& P, const Vecteur5& P_dot)> f_;
    std::string type;
public:
    Vecteur5 P;
    Vecteur5 P_dot;
    //TODO: think about wether these two should be public
    Toupie(SupportADessin* support_, std::function<Vecteur5(const double & t, const Vecteur5& P, const Vecteur5& P_dot)>  f,
            const Vecteur5 & P_, const Vecteur5 & P_dot_, const Matrice &  I_, std::string  type_): Dessinable(support_),
            f_(std::move(f)), P(P_), P_dot(P_dot_), Ig(I_), type(std::move(type_)) {};

    virtual ~Toupie() {};
    [[nodiscard]] Vecteur5 getP() const;
    [[nodiscard]] Vecteur5 getP_dot() const;
    void setP(const Vecteur5&);
    void setP_dot(const Vecteur5&);

    [[nodiscard]] Matrice getI() const;
    [[nodiscard]] std::string getType() const;

    [[nodiscard]]Vecteur5 f(const double & t,const Vecteur5& P_, const Vecteur5& P_dot_) const;
    [[nodiscard]] Vecteur5 f(const double & t) const;
    virtual void affiche(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Toupie & toupie) {toupie.affiche(out); return out;};
    std::ofstream & imprimeFichierP(std::ofstream& out);
    std::ofstream & imprimeFichierP_dot(std::ofstream &out);

};




