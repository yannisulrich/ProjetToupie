add_library(MathCore Matrice.cc VecteurArray.cc Toupie.cc ConeSimple.cc Vecteur.cc
        Integrateurs/Integrateur.cc Integrateurs/IntegrateurEulerCromer.cc constantes.cc Integrateurs/IntegrateurNewmark.cc Integrateurs/IntegrateurRungeKutta.cc)

add_subdirectory(Tests)