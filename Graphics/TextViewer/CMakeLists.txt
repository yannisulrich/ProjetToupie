add_library(TextViewer TextViewer.cc)
target_include_directories(TextViewer PUBLIC .. ${CMAKE_SOURCE_DIR} ../../MathCore/ ../../Interface ${Qt5Widgets_INCLUDE_DIRS})