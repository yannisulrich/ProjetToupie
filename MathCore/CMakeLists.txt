set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops -Wshadow")
add_library(MathCore Matrice.cc VecteurArray.cc Toupies/Toupie.cc Toupies/ConeSimple.cc Vecteur.cc
        Integrateurs/IntegrateurEulerCromer.cc constantes.cc Integrateurs/IntegrateurNewmark.cc Integrateurs/IntegrateurRungeKutta.cc Toupies/ConeSymFixe.cc Toupies/ConeSymFixe.h Toupies/TippeTopRolls.cc Toupies/TippeTopRolls.h Toupies/TippeTopFriction.cc Toupies/TippeTopFriction.h)
include_directories(../Graphics)
add_subdirectory(Tests)

#target_link_libraries(MathCore Graphics)