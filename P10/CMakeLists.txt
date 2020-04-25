
add_executable(SimTest SimulatorTest.cc)
target_link_libraries(SimTest PRIVATE Simulator System OpenGLViewer FileViewer TextViewer MathCore)
