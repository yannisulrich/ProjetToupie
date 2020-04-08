cmake_minimum_required(VERSION 3.15)
project(ToupieMain LANGUAGES CXX)



#set(CMAKE_CXX_COMPILER /usr/bin/gcc)
# Set Qt directory here

set(customQtRoot "C:\\Qt\\5.14.1\\mingw73_32")
IF(WIN32)
    message(STATUS "Will link Qt for Windows.")
    list(APPEND CMAKE_PREFIX_PATH ${customQtRoot})
ENDIF()


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops -Wshadow")

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES ToupieMain_en_150.ts)

add_executable(ToupieMain
          main.cpp
          mainwindow.cpp
          mainwindow.h
          mainwindow.ui
    ${TS_FILES}
  )

set(projectIncludes ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/MathCore
        ${CMAKE_SOURCE_DIR}/MathCore/Integrateurs
        ${CMAKE_SOURCE_DIR}/Tests
        ${CMAKE_SOURCE_DIR}/Graphics)
include_directories(${projectIncludes})

add_subdirectory(MathCore)
add_subdirectory(Tests)
add_subdirectory(Graphics)

target_link_libraries(ToupieMain PUBLIC MathCore)
target_link_libraries(ToupieMain PRIVATE Qt5::Widgets)

if(WIN32)
    # Finally, need to deploy Qt
    SET(customQtBin ${customQtRoot}\\bin)
    SET(customQtDeploy ${customQtBin}\\windeployqt)
    SET(customQtDeployLoc ${CMAKE_BINARY_DIR})
    add_custom_command(TARGET ToupieMain POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E env PATH="${customQtBin}\;C:\\Qt\\Tools\\mingw730_64\\bin"
            ${customQtDeploy} $<TARGET_FILE:ToupieMain>
            COMMENT "Calling windeployqt...")
endif()

#traductions
#qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})




