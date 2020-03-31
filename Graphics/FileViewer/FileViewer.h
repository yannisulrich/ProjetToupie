//
// Created by Yannis on 30.03.20.
//
#pragma once
#include <iostream>
#include "SupportADessin.h"
class Toupie;
class Systeme;

class FileViewer: public SupportADessin {
private:
    std::ofstream& out;;
public:
    explicit FileViewer(std::ofstream & out): out(out) {}

    ~FileViewer() override = default;

    void dessine(Toupie const&) override;
    void dessine(Systeme const&) override;
};

