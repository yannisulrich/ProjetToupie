//
// Created by Yannis on 06.03.20.
//



#pragma once
#include "VecteurArray.h"
#include <vector>
#include <array>

extern const Vecteur3 g;
template <class T>
VecteurArray<T> sinus(const double & t, const VecteurArray<T>& P, const VecteurArray<T>& P_dot) {
    VecteurArray<T> out(- P);
    return out;
}
