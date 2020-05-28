cmake_minimum_required(VERSION 3.15)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14" CACHE STRING "Minimum OS X deployment version" FORCE)
project(ToupieMain LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-O2 -mavx2 -funroll-loops -Wall")

set(STATIC_BUILD 1)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set Qt directory here
if(NOT STATIC_BUILD)
    set(customQtRoot "C:\\Qt\\5.14.2\\mingw73_32")
endif()
if(STATIC_BUILD)
    set(customQtRoot "C:\\Qt\\Qt-5.14.2")
endif()

IF(WIN32)
    message(STATUS "Will link Qt for Windows.")
    list(APPEND CMAKE_PREFIX_PATH ${customQtRoot})
ENDIF()

list(APPEND CMAKE_MODULE_PATH /usr/local/Qt-5.14.2/lib/cmake/)
find_package(Qt5Widgets PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5Widgets/ NO_DEFAULT_PATHS REQUIRED)
find_package(Qt5OpenGL PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5OpenGL/ NO_DEFAULT_PATHS REQUIRED)
find_package(Qt5Xml PATHS /usr/local/Qt-5.14.2/lib/cmake/Qt5Xml/ NO_DEFAULT_PATHS REQUIRED)

#test
add_subdirectory(MathCore)
add_subdirectory(P9)
add_subdirectory(P10)
add_subdirectory(Interface)
add_subdirectory(Graphics)

set(projectIncludes ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/MathCore
        ${CMAKE_SOURCE_DIR}/MathCore/Integrateurs
        ${CMAKE_SOURCE_DIR}/Tests
        ${CMAKE_SOURCE_DIR}/Interface
        ${Qt5Widgets_INCLUDE_DIRS}
        )
include_directories(${projectIncludes})


add_executable(ToupieMain
          main.cpp
          mainwindow.cpp
        XMLReader.cc XMLReader.h)

target_include_directories(ToupieMain PRIVATE ${projectIncludes})
target_link_libraries(ToupieMain PRIVATE Qt5::Widgets Qt5::Xml MathCore OpenGLViewer Simulator)

if(NOT STATIC_BUILD)
    if(WIN32)
        # Finally, need to deploy Qt
        SET(customQtBin ${customQtRoot}\\bin)
        SET(customQtDeploy ${customQtBin}\\windeployqt)
        SET(customQtDeployLoc ${CMAKE_BINARY_DIR})
        add_custom_command(TARGET ToupieMain POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E env PATH="${customQtBin}"
                ${customQtDeploy} $<TARGET_FILE:ToupieMain>
                COMMENT "Calling windeployqt...")
    endif()
endif()







