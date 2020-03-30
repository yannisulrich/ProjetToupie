//
// Created by Yannis on 29.03.20.
//
#pragma once

#include "SupportADessin.h"
#include <iostream>

class TextViewer: public SupportADessin {
private:
    std::ostream& out;
public:
    explicit TextViewer(std::ostream &out)
            : out(out)
    {}
    virtual ~TextViewer() {}

    virtual void dessine(Toupie const&) override;
};


