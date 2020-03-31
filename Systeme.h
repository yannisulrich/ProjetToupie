//
// Created by Yannis on 28.03.20.
//

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
    Systeme(const Systeme&) = delete;
    Systeme & operator=(const Systeme&) = delete;
    Systeme(const std::initializer_list<Toupie* >& toupies, SupportADessin* support): Dessinable(support), toupies(toupies) {}

    void addToupie(Toupie &);
    [[nodiscard]] std::vector<Toupie * > getToupies() const;
    friend std::ostream& operator<<(std::ostream& out, const Systeme & systeme);



    virtual void dessine() override
    {support->dessine(*this);}

    void integrate(Integrateur*, const double& dt, const double& t);
};

