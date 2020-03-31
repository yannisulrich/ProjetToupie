//
// Created by Yannis on 29.03.20.
//

#include <MathCore/Toupie.h>
#include "Systeme.h"
#include "TextViewer.h"

void TextViewer::dessine(Toupie const & toupie) {
    out << toupie << std::endl;
}

void TextViewer::dessine(Systeme const & sys) {
    size_t i(1);
    for (Toupie* toupie : sys.getToupies()) {
        out << "toupie " << i << " : "  << *toupie << std::endl;
        ++i;
    }
}
