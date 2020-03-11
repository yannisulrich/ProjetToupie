cmake_minimum_required(VERSION 3.15)
#project(TestVecteur)
#project(TestMatrice)
project(TestToupie)

set(CMAKE_CXX_STANDARD 17)
#SET(CMAKE_CXX_COMPILER /usr/bin/clang)


#add_executable(TestVecteur Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h vecteurtest.cpp)
#add_executable(TestMatrice Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h testMatrice.cc)
add_executable(TestToupie Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h testToupie.cc)

