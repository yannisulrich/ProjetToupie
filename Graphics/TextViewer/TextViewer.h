
#pragma once
#include "SupportADessin.h"
#include <iostream>

class TextViewer: public SupportADessin {
private:
    std::ostream& out;
public:
    explicit TextViewer(std::ostream &out): out(out) {}
    ~TextViewer() override = default;

    void dessine(Toupie const&) const override;
    void dessine(Systeme const&) const override;
};


