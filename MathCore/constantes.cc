//
// Created by Yannis on 06.03.20.
//

#include "constantes.h"
#include "VecteurArray.h"

const Vecteur3 g(0.0, 0.0, -9.81);
Vecteur5 f(const double & t, const Vecteur5& P_, const Vecteur5& P_dot_) {
    Vecteur5 out(-5 * P_);
    out[0] = 0;
    return out;
}