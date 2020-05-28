add_library(QCustomPlot qcustomplot.cpp)
target_include_directories(QCustomPlot PUBLIC ..)
IF(APPLE)
    target_link_libraries(QCustomPlot Qt5::Core Qt5::OpenGL "-framework OpenGL")
ENDIF()

IF(WIN32)
    target_link_libraries(QCustomPlot Qt5::Core Qt5::OpenGL)
ENDIF()