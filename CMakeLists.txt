cmake_minimum_required(VERSION 3.15)
project(ToupieMain LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "C:\\Qt\\5.14.1\\mingw73_32")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")

find_package(Qt5 COMPONENTS Core Gui Widgets LinguistTools REQUIRED)

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
        ${CMAKE_SOURCE_DIR}/MathCore/Integrateurs)
include_directories(${projectIncludes})

add_subdirectory(MathCore)
target_link_libraries(ToupieMain PUBLIC MathCore)
target_link_libraries(ToupieMain PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

#traductions
#qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})




