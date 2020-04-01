
#include <MathCore/Toupies/Toupie.h>
#include "Systeme.h"
#include "TextViewer.h"

void TextViewer::dessine(Toupie const & toupie) const {
    out << toupie << std::endl;
}

void TextViewer::dessine(Systeme const & sys) const {
    size_t i(1);
    for (Toupie* toupie : sys.getToupies()) {
        out << "toupie " << i << " : "  << *toupie << std::endl;
        ++i;
    }
}
