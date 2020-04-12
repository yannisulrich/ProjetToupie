set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops -Wshadow")

find_package(Threads REQUIRED)

add_library(MathCore Matrice.cc VecteurArray.cc Toupies/Toupie.cc Toupies/ConeSimple.cc Vecteur.cc
        Integrateurs/IntegrateurEulerCromer.cc constantes.cc Integrateurs/IntegrateurNewmark.cc Integrateurs/IntegrateurRungeKutta.cc Toupies/ConeSymFixe.cc Toupies/ConeSymFixe.h Toupies/TippeTopRolls.cc Toupies/TippeTopRolls.h Toupies/TippeTopFriction.cc Toupies/TippeTopFriction.h Integrateurs/LSODA/LSODA.cpp)
set_target_properties(MathCore PROPERTIES COMPILE_FLAGS "-O2" LINK_FLAGS "-pthread")
include_directories(../Graphics)
add_subdirectory(Tests)

#target_link_libraries(MathCore Graphics)