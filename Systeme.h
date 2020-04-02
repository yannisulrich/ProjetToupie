/*
 * Classe Systeme. Le support du système masque le support des toupies inclues dedans, c'est à dire que l'affichage d'un
 * système sera toujours fait sur le support DU SYSTEME, et pas des toupies.
 */
#pragma once

#include "MathCore.h"
#include "Dessinable.h"
#include <memory>
#include <initializer_list>
#include <iostream>
class Systeme:Dessinable {
private:
std::vector<Toupie* > toupies;
public:
    //ces deux constructeurs sont effacés car nous les utilisons pas et leur définition par défaut cause des problèmes d'accès
    //multiples sur les pointeurs dans toupies.
    Systeme(const Systeme&) = delete;
    Systeme & operator=(const Systeme&) = delete;


    explicit Systeme(SupportADessin* support): Dessinable(support) {}
    ~Systeme() {for (auto i: toupies) delete i;}

    void addConeSymFixe(const Vecteur5 & P, const Vecteur5 & P_dot,
            const double &L, const double &R, const double &m);

    void addTippeTopRolls(const Vecteur5 & P, const Vecteur5 & P_dot,
                        const double &R, const double &h, const double &m);

    void addTippeTopFriction(const Vecteur5 & P, const Vecteur5 & P_dot,
                          const double &R, const double &h, const double& mu, const double &m);

    [[nodiscard]] std::vector<Toupie * > getToupies() const;
    friend std::ostream& operator<<(std::ostream& out, const Systeme & systeme);



    virtual void dessine(SupportADessin* supp) const {supp->dessine(*this);};

    void dessine() const override {support->dessine(*this);};


    void integrate(Integrateur*, const double& dt, const double& t = 0);

    void integrateMultiple(const size_t & n, Integrateur*, const double& dt, const double& t = 0);
};

