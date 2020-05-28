set(CMAKE_CXX_FLAGS "-O2 -mavx2 -funroll-loops")
cmake_minimum_required(VERSION 3.16)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(QCustomPlot)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



message("1")
message(${Qt5Widgets_INCLUDE_DIRS})


find_package(Qt5Widgets PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5Widgets NO_DEFAULT_PATH REQUIRED)
find_package(Qt5Core PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5Core NO_DEFAULT_PATH REQUIRED)
find_package(Qt5OpenGL PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5OpenGL NO_DEFAULT_PATH REQUIRED)
find_package(Qt5Gui PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5Gui NO_DEFAULT_PATH REQUIRED)
find_package(OpenGL REQUIRED)

set(projectIncludes ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/MathCore
        ${CMAKE_SOURCE_DIR}/MathCore/Integrateurs
        ${CMAKE_SOURCE_DIR}/Tests
        ${CMAKE_SOURCE_DIR}/Interface
        ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer
        ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/QCustomPlot
        ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles
        ${Qt5Widgets_INCLUDE_DIRS}
        )
include_directories(${projectIncludes})

add_library(OpenGLViewer
        model.cpp
        modelloader.cpp
        scene.cpp
        GLWindow.cc shaders.qrc models.qrc QCustomPlot/PlotWindow.cc)


target_include_directories(OpenGLViewer PUBLIC ${projectIncludes})
IF(APPLE)
    target_link_libraries(OpenGLViewer PUBLIC System MathCore System QCustomPlot Qt5::Widgets Qt5::OpenGL Qt5::Gui ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libassimpmac.a
    ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libIrrXMLmac.a ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libzlibstaticmac.a)
    #target_link_libraries(OpenGLViewer PUBLIC System MathCore System QCustomPlot ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimp/libassimp.5.0.1.dylib)
ENDIF()

IF(WIN32)
    target_link_libraries(OpenGLViewer PUBLIC MathCore System Qt5::Core QCustomPlot Qt5::Widgets Qt5::OpenGL opengl32 ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libassimpwin.a
            ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libIrrXMLwin.a ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libzlibstaticwin.a)
ENDIF()
