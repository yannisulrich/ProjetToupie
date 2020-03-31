//
// Created by Yannis on 30.03.20.
//

#include "FileViewer.h"
#include <MathCore/Toupie.h>
#include "Systeme.h"

void TextViewer::dessine(Toupie const & toupie) {
    toupie.afficheFile(out);
    out << std::endl;

}

void TextViewer::dessine(Systeme const & sys) {
    size_t i(1);
    for (Toupie* toupie : sys.getToupies()) {
        out << i << ": ";
        toupie->dessine();
        ++i;
    }

}
