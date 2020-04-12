
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

configure_file(ads_fragment.vert ads_fragment.vert COPYONLY)
configure_file(ads_fragment.frag ads_fragment.frag COPYONLY)
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

add_library(OpenGLViewer
        model.cpp
        modelloader.cpp
        scene.cpp
        window.cpp
        )
target_link_libraries(OpenGLViewer PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)


#set(ASSIMP_LIBRARY_DIRS "lib/assimp/build/code")
#link_directories(${ASSIMP_LIBRARY_DIRS})


#target_link_libraries(PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)





