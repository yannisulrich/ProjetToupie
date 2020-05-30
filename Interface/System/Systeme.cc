
#include "Systeme.h"

#include <utility>


using namespace std;
std::ostream& operator<<(std::ostream& out, const Systeme & systeme) {
    std::vector<const Toupie* > toupies = systeme.getToupies();
    for(size_t i(0); i < toupies.size(); ++i) {
        out << "==== Toupie " << i + 1 << " :" << endl;
        out << toupies[i]->type() << endl;
        out << *toupies[i] << endl;
    }
    out << "===============" << endl;
    return out;
}

std::vector<const Toupie *> Systeme::getToupies() const {
    std::vector<const Toupie *> out;
    const Toupie* p;
    for(Toupie* toupie: toupies) {
        p = toupie;
        out.push_back(p);
    }
    return out;
}

void Systeme::addSymCone(const Vecteur5 &P, const Vecteur5 &P_dot, const double &L, const double &R,
                         const double &m, const QString& modelpath) {
    if(modelpath.isEmpty()) toupies.push_back(new ConeSymFixe(support, P, P_dot, L, R, m, "cone.dae"));
    else toupies.push_back(new ConeSymFixe(support, P, P_dot, L, R, m, modelpath, true));
}
/*
void Systeme::addSymModel(const Vecteur5 &P, const Vecteur5 &P_dot, const double &I1, const double &I3, const double &m,
                          const QString &path) {
    toupies.push_back(new ConeSymFixe(support, P, P_dot, I1, I3, m, path, true));
}
 */
void Systeme::addTippeTopRolls(const Vecteur5 &P, const Vecteur5 &P_dot, const double &R, const double &h, const double &m, const QString& modelpath) {
    if(modelpath.isEmpty()) toupies.push_back(new TippeTopRolls(support, P, P_dot, R, h, m, "tippetophollow.DAE"));
    else toupies.push_back(new TippeTopRolls(support, P, P_dot, R, h, m, modelpath, true));
}
void Systeme::addTippeTopFriction(const Vecteur5 &P, const Vecteur5 &P_dot, const double &R, const double &epsilon, const double & mu, const double &m, const QString& modelpath) {
    if(modelpath.isEmpty()) toupies.push_back(new TippeTopFriction(support, P, P_dot, R, epsilon, mu, m, "tippetophollow.DAE"));
    else toupies.push_back(new TippeTopFriction(support, P, P_dot, R, epsilon, mu, m, modelpath, true));
}
void Systeme::addSymConeGlisse(const Vecteur5 &P, const Vecteur5 &P_dot, const double &r, const double &L3, const double &m, const double & muk, const QString& modelpath) {
    if(modelpath.isEmpty()) toupies.push_back(new ConeSymGlisse(support, P, P_dot,r, L3, m, muk, "cone.dae"));
    else toupies.push_back(new ConeSymGlisse(support, P, P_dot,r, L3, m, muk, modelpath, true));
}
void Systeme::integrate(const double& dt, const double& t) {
    for(auto i : toupies) {
        if(i->type() == "Tippe Top Inverseur") {
            try {
                dynamic_cast<TippeTopFriction &>(*i).update(dt);
            }
            catch(std::bad_cast& bc) {
                std::cerr << "bad_cast caught: " << bc.what() << endl;
                std::cerr << "Est-ce que vous avez essayé de manuellement donner le type 'Tippe Top Inverseur' à une toupie?" << endl;
            }
        }
        else if(i->type() == "Cone Glissant") {
            cout << "yappadoodle" << endl;
            try {
                dynamic_cast<ConeSymGlisse &>(*i).update(dt);
            }
            catch(std::bad_cast& bc) {
                std::cerr << "bad_cast caught: " << bc.what() << endl;
                std::cerr << "Est-ce que vous avez essayé de manuellement donner le type 'Cone Glissant' à une toupie?" << endl;
            }
        }
        else integrator->integrate(*i, dt, t);
    }
}

void Systeme::integrateMultiple(const size_t & n, const double & dt, const double &t) {
    for(auto i : toupies) {
        if(i->type() == "Tippe Top Inverseur") {
            try {
                dynamic_cast<TippeTopFriction &>(*i).update(n*dt);
            }
            catch(std::bad_cast& bc) {
                std::cerr << "bad_cast caught: " << bc.what() << endl;
                std::cerr << "Est-ce que vous avez essayé de manuellement donner le type 'Tippe Top Inverseur' à une toupie?" << endl;
            }
        }
        else if(i->type() == "Cone Glissant") {
            try {
                dynamic_cast<ConeSymGlisse &>(*i).update(n*dt);
            }
            catch(std::bad_cast& bc) {
                std::cerr << "bad_cast caught: " << bc.what() << endl;
                std::cerr << "Est-ce que vous avez essayé de manuellement donner le type 'Cone Glissant' à une toupie?" << endl;
            }
        }
        else integrator->integrateMultiple(n, *i, dt, t);
    }
}

void Systeme::setPlotsForTop(int index, const bool &p1, const bool &p2, const bool &p3, const bool &p4) {
    if(index < toupies.size()) {
        toupies[index]->setPlots(p1, p2, p3, p4);
    }
    else {
        std::cerr << "setPlots: index is larger than amount of tops. (count starts at 0)" << endl;
    }
}






