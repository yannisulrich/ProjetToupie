
cmake_minimum_required(VERSION 3.16)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)
find_package(OpenGL REQUIRED)

set(projectIncludes ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/MathCore
        ${CMAKE_SOURCE_DIR}/MathCore/Integrateurs
        ${CMAKE_SOURCE_DIR}/Tests
        ${CMAKE_SOURCE_DIR}/Interface
        ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer
        ${Qt5Widgets_INCLUDE_DIRS}
        )
include_directories(${projectIncludes})

add_library(OpenGLViewer
        model.cpp
        modelloader.cpp
        scene.cpp
        GLWindow.cc shaders.qrc models.qrc)

target_include_directories(OpenGLViewer PUBLIC ${projectIncludes})
IF(APPLE)
    target_link_libraries(OpenGLViewer PUBLIC System MathCore System Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL /usr/local/lib/libassimp.dylib "-framework OpenGL")

ENDIF()

IF(WIN32) #TODO assimp from folder
    target_link_libraries(OpenGLViewer PUBLIC MathCore System Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)
ENDIF()
