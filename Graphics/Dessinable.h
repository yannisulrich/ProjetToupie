//
// Created by Yannis on 28.03.20.
//

#pragma once

#include "SupportADessin.h"


class Dessinable {
protected:
SupportADessin* support;
public:
    explicit Dessinable(SupportADessin* support): support(support) {}
//TODO: virtual destructor?
    virtual void dessine() const = 0;
};


