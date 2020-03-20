cmake_minimum_required(VERSION 3.15)
#project(TestVecteur)
#project(TestMatrice)
#project(TestToupie)
project(TestIntegrateur)

set(CMAKE_CXX_STANDARD 20)
set(VERBOSE 1)

#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")


#add_executable(TestVecteur Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h vecteurtest.cpp Integrateur.cc Integrateur.h IntegrateurEulerCromer.cc IntegrateurEulerCromer.h)
#add_executable(TestMatrice Matrice.cc Matrice.h Vecteur.cc Vecteur.h testMatrice.cc)
#add_executable(TestToupie Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h testToupie.cc ConeSimple.h ConeSimple.cc)
add_executable(TestIntegrateur Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h ConeSimple.h ConeSimple.cc Integrateur.cc Integrateur.h IntegrateurEulerCromer.h IntegrateurEulerCromer.cc testIntegrateur.cc constantes.h constantes.cc)

