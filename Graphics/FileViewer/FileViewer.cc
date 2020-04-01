
#include "FileViewer.h"
#include <MathCore/Toupies/Toupie.h>
#include "Systeme.h"

void FileViewer::dessine(Toupie const & toupie) const {
    toupie.afficheFile(out);
    out << std::endl;

}

void FileViewer::dessine(Systeme const & sys) const {
    size_t i(1);
    for (Toupie* toupie : sys.getToupies()) {
        toupie->afficheFile(out);
        out << " # " << i << std::endl;
        ++i;
    }

}
