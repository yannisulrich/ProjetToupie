#Les fichiers test de base
add_executable(TestVecteur testVecteur.cpp)
add_executable(TestMatrice testMatrice.cc)
add_executable(TestToupie testToupie.cc)
add_executable(TestIntegrateur testIntegrateur.cc)

target_link_libraries(TestVecteur PRIVATE MathCore)
target_link_libraries(TestMatrice  PUBLIC MathCore)
target_link_libraries(TestToupie  PUBLIC MathCore GraphicsCore)
target_link_libraries(TestIntegrateur PUBLIC MathCore)