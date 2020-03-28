//
// Created by Yannis on 28.03.20.
//
#pragma once

#include "MathCore.h"

class SupportADessin {
public:
    virtual ~SupportADessin() {}
    SupportADessin(const SupportADessin&) = delete;
    virtual void dessine(ConeSimple const&) = 0;
    //virtual void dessine(Systeme const&) = 0;
};


