
add_library( lsoda ${CMAKE_CURRENT_SOURCE_DIR}/LSODA.cpp)




target_link_libraries(benchmark_lsoda ${CMAKE_THREAD_LIBS_INIT})
