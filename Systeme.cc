//
// Created by Yannis on 28.03.20.
//

#include "Systeme.h"
using namespace std;
std::ostream& operator<<(std::ostream& out, const Systeme & systeme) {
    std::vector<Toupie* > toupies = systeme.getToupies();

    for(size_t i(0); i < toupies.size(); ++i) {
        out << "==== Toupie " << i + 1 << " :" << endl;
        out << toupies[i]->getType() << endl;
        out << *toupies[i] << endl;
    }
    return out;
}

std::vector<Toupie* > Systeme::getToupies() const {
    return toupies;
}

/*
void Systeme::addToupie(Toupie & toupie) {
    toupies.push_back(static_cast<const std::unique_ptr<Toupie>>(&toupie));
}
*/