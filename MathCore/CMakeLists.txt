set(CMAKE_CXX_FLAGS "-O2 -mavx2 -funroll-loops")

find_package(Threads REQUIRED)
#find_package(OpenGL REQUIRED)

#find_package(Qt5 COMPONENTS Gui REQUIRED)
add_subdirectory(Tests)

add_library(MathCore LinAlg/Matrice.cc LinAlg/VecteurArray.cc Toupies/Toupie.cc Toupies/ConeSimple.cc LinAlg/Vecteur.cc
        Integrateurs/IntegrateurEulerCromer.cc LinAlg/constantes.cc Integrateurs/IntegrateurNewmark.cc
        Integrateurs/IntegrateurRungeKutta.cc Toupies/ConeSymFixe.cc Toupies/ConeSymFixe.h
        Toupies/TippeTopRolls.cc Toupies/TippeTopRolls.h Toupies/TippeTopFriction.cc Toupies/TippeTopFriction.h
        Integrateurs/LSODA/LSODA.cpp
        ../Graphics/OpenGLViewer/models.qrc Toupies/ConeSymGlisse.cc Toupies/ConeSymGlisse.h)

target_link_libraries(MathCore PUBLIC GraphicsCore OpenGLViewer)

target_include_directories(MathCore PUBLIC LinAlg Toupies Integrateurs)# ${Qt5Gui_INCLUDE_DIRS})
#include_directories(.. ../Interface Toupies P9)
set_target_properties(MathCore PROPERTIES COMPILE_FLAGS "-O2" LINK_FLAGS "-pthread") #pour la bibliothèque LSODA
