cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(TestSys)

set(CMAKE_CXX_STANDARD 17)
set(VERBOSE 1)



#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/../MathCore ${CMAKE_CURRENT_SOURCE_DIR}/../Graphics)
include_directories(.. ../MathCore ../Graphics)
add_subdirectory(.. cmake-build-debug)
#add_subdirectory(../MathCore ../Graphics)
#Ceci sert à choisir quel fichier test doit être exécuté.


add_executable(TestSys testSysteme.cc ../Systeme.h ../Systeme.cc)

target_link_libraries(TestSys PUBLIC MathCore)
#target_link_libraries(TestSys PUBLIC  Graphics)