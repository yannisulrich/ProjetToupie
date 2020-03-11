cmake_minimum_required(VERSION 3.15)
project(ProjetToupie)

set(CMAKE_CXX_STANDARD 17)
#SET(CMAKE_CXX_COMPILER /usr/bin/clang)

add_executable(ProjetToupie Matrice.cc Matrice.h Vecteur.cc Vecteur.h Toupie.cc Toupie.h vecteurtest.cpp)