//
// Created by Yannis on 28.03.20.
//

#include "Systeme.h"

#include <utility>


using namespace std;
std::ostream& operator<<(std::ostream& out, const Systeme & systeme) {
    std::vector<Toupie* > toupies = systeme.getToupies();

    for(size_t i(0); i < toupies.size(); ++i) {
        out << "==== Toupie " << i + 1 << " :" << endl;
        out << toupies[i]->getType() << endl;
        out << *toupies[i] << endl;
    }
    out << "===============" << endl;
    return out;
}

std::vector<Toupie* > Systeme::getToupies() const {
    return toupies;
}

void Systeme::addConeSymFixe(const Vecteur5 &P, const Vecteur5 &P_dot, const double &L, const double &R,
                             const double &m) {
    toupies.push_back(new ConeSymFixe(support, P, P_dot, L, R, m));

}
void Systeme::addTippeTopRolls(const Vecteur5 &P, const Vecteur5 &P_dot, const double &R, const double &h, const double &m) {
    toupies.push_back(new TippeTopRolls(support, P, P_dot, R, h, m));
}
void Systeme::addTippeTopFriction(const Vecteur5 &P, const Vecteur5 &P_dot, const double &R, const double &h, const double & mu, const double &m) {
    toupies.push_back(new TippeTopFriction(support, P, P_dot, R, h, mu, m));
}

void Systeme::integrate(Integrateur * integrateur, const double& dt, const double& t) {
    for(auto i : toupies) {
        integrateur->integrate(*i, dt, t);
    }
}

void Systeme::integrateMultiple(const size_t & n, Integrateur * integrateur, const double & dt, const double &t) {
    for(size_t i(0); i < n; ++i) {
        integrate(integrateur, dt, t + i*dt);
    }
}

