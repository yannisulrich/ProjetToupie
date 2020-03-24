cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(Tests)

set(CMAKE_CXX_STANDARD 17)
set(VERBOSE 1)



#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")


include_directories(.. ../..)
include_directories(.. ../Integrateurs)
add_subdirectory(.. cmake-build-debug)

#Ceci sert à choisir quel fichier test doit être exécuté.

#add_executable(Tests testVecteur.cpp)
add_executable(Tests testMatrice.cc)
#add_executable(Tests testToupie.cc)
#add_executable(Tests testIntegrateur.cc)

target_link_libraries(Tests PUBLIC MathCore)