
#pragma once
#include <iostream>
#include "SupportADessin.h"

class FileViewer: public SupportADessin {
private:
    std::ofstream& out;
public:
    explicit FileViewer(std::ofstream & out): out(out) {}
    ~FileViewer() override = default;

    void dessine(Toupie const&) const override;
    void dessine(Systeme const&) const override;
};

