

#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
#set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")


#include_directories(.. ../MathCore ../Interface)
#add_subdirectory(.. cmake-build-debug)
#add_subdirectory(../MathCore ../Interface)
#Ceci sert à choisir quel fichier test doit être exécuté.
include_directories(..)
add_executable(TestSysA ExerciceP9a.cc)

add_executable(TestSysB ExerciceP9b.cc)

target_link_libraries(TestSysA PUBLIC System MathCore GraphicsCore TextViewer FileViewer OpenGLViewer)
target_link_libraries(TestSysB PUBLIC System MathCore GraphicsCore TextViewer FileViewer OpenGLViewer)

