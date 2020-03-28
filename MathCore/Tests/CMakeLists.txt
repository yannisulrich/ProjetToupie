#SET(CMAKE_CXX_COMPILER /usr/local/bin/icpc)
#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
#set( CMAKE_CXX_FLAGS "-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk -mavx2 -O3 -D NOFUNCCALL -qopt-report=1 -qopt-report-phase=vec")
#set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")
#set(CMAKE_CXX_FLAGS "")

#Ceci sert à choisir quel fichier test doit être exécuté.

#add_executable(TestVecteur testVecteur.cpp)
#add_executable(TestMatrice testMatrice.cc)
#add_executable(TestToupie testToupie.cc)
add_executable(TestIntegrateur testIntegrateur.cc)

#target_link_libraries(TestVecteur PUBLIC MathCore)
#target_link_libraries(TestMatrice  PUBLIC MathCore)
#target_link_libraries(TestToupie  PUBLIC MathCore)
target_link_libraries(TestIntegrateur  PUBLIC MathCore)