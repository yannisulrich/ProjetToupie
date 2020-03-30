//
// Created by Yannis on 29.03.20.
//

#include <MathCore/Toupie.h>
#include "TextViewer.h"

void TextViewer::dessine(Toupie const & toupie) {
    out << "Paramètre: " << toupie.P << ", Dérivée: " << toupie.P_dot << std::endl;
}
