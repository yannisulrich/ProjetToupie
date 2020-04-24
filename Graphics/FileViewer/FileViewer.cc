
#include "FileViewer.h"
#include <Toupies/Toupie.h>
#include "System/Systeme.h"

void FileViewer::dessine(Toupie const & toupie) const {
    toupie.afficheFile(out);
    out << std::endl;

}

void FileViewer::dessine(Systeme const & sys) const {
    size_t i(1);
    for (const Toupie* toupie : sys.getToupies()) {
        toupie->afficheFile(out);
        out << " # " << i << std::endl;
        ++i;
    }
}

void FileViewer::dessine(const double & t, const Toupie &toupie) const {
    out << t << " ";
    toupie.afficheFile(out);
    out << std::endl;
}

void FileViewer::dessine(const double & t, const Systeme &sys) const {
    size_t i(1);
    for (const Toupie* toupie : sys.getToupies()) {
        out << t << " ";
        toupie->afficheFile(out);
        out << " # " << i << std::endl;
        ++i;
    }
}
