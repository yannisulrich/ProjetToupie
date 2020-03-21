cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)
#project(TestVecteur)
#project(TestMatrice)
#project(TestToupie)
project(TestIntegrateur)

set(CMAKE_CXX_STANDARD 17)
set(VERBOSE 1)



#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")


include_directories(.. ../..)
add_subdirectory(.. cmake-build-debug)
#add_executable(TestIntegrateur testIntegrateur.cc ../Matrice.h)

#add_executable(TestVecteur Matrice.cc Matrice.h VecteurArray.cc VecteurArray.h Toupie.cc Toupie.h vecteurtest.cpp Integrateur.cc Integrateur.h IntegrateurEulerCromer.cc IntegrateurEulerCromer.h)
#add_executable(TestMatrice Matrice.cc Matrice.h VecteurArray.cc VecteurArray.h testMatrice.cc Vecteur.h Vecteur.cc)
#add_executable(TestToupie Matrice.cc Matrice.h VecteurArray.cc VecteurArray.h Toupie.cc Toupie.h testToupie.cc ConeSimple.h ConeSimple.cc)
add_executable(TestIntegrateur testIntegrateur.cc)

target_link_libraries(TestIntegrateur PUBLIC MathCore)