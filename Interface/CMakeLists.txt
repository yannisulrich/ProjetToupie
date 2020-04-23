set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_library(Simulator Simulator/Simulator.cc)
add_library(System System/Systeme.cc)
target_link_libraries(System MathCore)
target_link_libraries(Simulator System GraphicsCore FileViewer TextViewer OpenGLViewer)
#target_include_directories(GraphicsCore PRIVATE .)
target_include_directories(Simulator PUBLIC . FileViewer TextViewer OpenGLViewer)



find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)
find_package(Qt5OpenGL REQUIRED)

add_executable(SimTest SimulatorTest.cc)
target_link_libraries(SimTest PUBLIC Simulator System OpenGLViewer FileViewer TextViewer MathCore)

