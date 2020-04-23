
#pragma once
#include <iostream>
#include "../SupportADessin.h"

class FileViewer: public SupportADessin {
private:
    std::ofstream& out;
public:
    explicit FileViewer(std::ofstream & out): out(out) {}
    ~FileViewer() override = default;

    void dessine(Toupie const&) const override; //"dessin" standard, simplement les valeurs des coordonnées et leur dérivées
    void dessine(Systeme const&) const override;

    void dessine(const double &, const Toupie& toupie) const override; //dessin avec un double au début, qui servira de temps.
    void dessine(const double &, const Systeme& systeme) const override;
};

