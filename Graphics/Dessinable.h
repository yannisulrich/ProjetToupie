//
// Created by Yannis on 28.03.20.
//

#pragma once

#include "SupportADessin.h"

class Dessinable {
protected:
SupportADessin* support;
public:
    Dessinable(SupportADessin* support): support(support) {}

    virtual void dessine() = 0;
};


