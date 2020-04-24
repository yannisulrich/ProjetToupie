

#include "Toupies/Toupie.h"
#include "System/Systeme.h"
#include "TextViewer.h"

void TextViewer::dessine(Toupie const & toupie) const {
    out << toupie << std::endl;
}

void TextViewer::dessine(Systeme const & sys) const {
    size_t i(1);
    for (const Toupie* toupie : sys.getToupies()) {
        out << "toupie " << i << " : "  << *toupie << std::endl;
        ++i;
    }
}

void TextViewer::dessine(const double &t, Toupie const & toupie) const {
    out <<"t: " << t << " ";
    out << toupie << std::endl;
}

void TextViewer::dessine(const double &t, Systeme const & sys) const {
    size_t i(1);
    out <<"t: " << t << std::endl;
    for (const Toupie* toupie : sys.getToupies()) {
        out << "toupie " << i << " : "  << *toupie << std::endl;
        ++i;
    }
}
