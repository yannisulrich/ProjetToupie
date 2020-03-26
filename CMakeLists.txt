cmake_minimum_required(VERSION 3.5)

project(ToupieMain LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O -mavx2 -funroll-loops")

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES ToupieMain_en_150.ts)

add_executable(ToupieMain
          main.cpp
          mainwindow.cpp
          mainwindow.h
          mainwindow.ui
    ${TS_FILES}
  )
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/MathCore)
add_subdirectory(MathCore)
target_link_libraries(ToupieMain PUBLIC MathCore)


target_link_libraries(ToupieMain PRIVATE Qt5::Widgets)

#traductions
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})




