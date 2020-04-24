add_library(FileViewer FileViewer.cc)
target_include_directories(FileViewer PUBLIC .. ${CMAKE_SOURCE_DIR} ../../MathCore/ ../../Interface ${Qt5Widgets_INCLUDE_DIRS})