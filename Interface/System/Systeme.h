/*
 * Classe Systeme. Le support du système masque le support des toupies inclues dedans, c'est à dire que l'affichage d'un
 * système sera toujours fait sur le support DU SYSTEME, et pas des toupies.
 */
#pragma once

#include "Integrateurs/Integrateur.h"
#include "Toupies/Toupie.h"
#include "Toupies/ConeSymFixe.h"
#include "Toupies/TippeTopFriction.h"
#include "Toupies/TippeTopRolls.h"
#include "LinAlg/VecteurArray.h"
#include "Graphics/Dessinable.h"
#include <memory>
#include <initializer_list>
#include <iostream>
#include <QResource>

class Systeme: public Dessinable {
private:
std::vector<Toupie* > toupies;
Integrateur* integrator;


public:

    //ces deux constructeurs sont effacés car nous les utilisons pas et leur définition par défaut cause des problèmes d'accès
    //multiples sur les pointeurs dans toupies.
    Systeme() = delete;
    Systeme(const Systeme&) = delete;
    Systeme(SupportADessin* support, Integrateur* integrator): Dessinable(support), integrator(integrator) {}
    ~Systeme() {for (auto i: toupies) delete i;}



    //méthodes pour ajouter un type de toupie au système. Nous avons préféré créer des nouveaux objets spécifiquement pour la classe
    //plutôt que de permettre d'ajouter un pointeur sur une toupie déjà existante pour éviter les accès multiples. Ce n'est pas le seul moyen de l'atteindre,
    //mais cette méthode a l'avantage de donner une interface agréable à un possible utilisateur.
    void addSymCone(const Vecteur5 & P, const Vecteur5 & P_dot,
                    const double &L, const double &R, const double &m);

    void addSymModel(const Vecteur5 & P, const Vecteur5 & P_dot,
                        const double &I1, const double &I3, const double &m, const QString& path);

    void addTippeTopRolls(const Vecteur5 & P, const Vecteur5 & P_dot,
                        const double &R, const double &h, const double &m);

    void addTippeTopFriction(const Vecteur5 & P, const Vecteur5 & P_dot,
                          const double &R, const double &h, const double& mu, const double &m);


    //une méthode qui retourne des pointeurs const sur les éléments de toupies. De cette manière un utilisateur ne pourrait pas par
    //inadvertance modifier une toupie.
    [[nodiscard]] std::vector<const Toupie * > getToupies() const;

    //opérateur d'affichage complet du système, avec types des toupies etc...
    friend std::ostream& operator<<(std::ostream& out, const Systeme & systeme);


    //dessin sur un support specifique
    virtual void dessine(SupportADessin* supp) const {supp->dessine(*this);};

    //dessin sur le support appartenant à la superclasse Dessinable.
    void dessine() const override {support->dessine(*this);};

    //integration de chaque toupie, possiblement plusieurs fois (integrateMultiple)
    void integrate(const double& dt, const double& t = 0);

    void integrateMultiple(const size_t & n, const double& dt, const double& t = 0);

    void addToTraces() {for(auto i:toupies) i->addToTraces();}
};

