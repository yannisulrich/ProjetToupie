add_library(MathCore Matrice.cc VecteurArray.cc Toupie.cc ConeSimple.cc Vecteur.cc
        Integrateurs/IntegrateurEulerCromer.cc constantes.cc Integrateurs/IntegrateurNewmark.cc Integrateurs/IntegrateurRungeKutta.cc)
include_directories(../Graphics)
add_subdirectory(Tests)
#target_link_libraries(MathCore Graphics)