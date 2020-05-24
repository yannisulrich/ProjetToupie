set(CMAKE_EXE_LINKER_FLAGS "--verbose")
add_executable(SimTest SimulatorTest.cc)
target_link_libraries(SimTest PRIVATE Simulator System OpenGLViewer FileViewer TextViewer MathCore)
        #${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libassimp.a
        #${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libIrrXML.a ${CMAKE_SOURCE_DIR}/Graphics/OpenGLViewer/assimpFiles/libzlibstatic.a)

if(WIN32)
    # Finally, need to deploy Qt
    SET(customQtBin ${customQtRoot}\\bin)
    SET(customQtDeploy ${customQtBin}\\windeployqt)
    SET(customQtDeployLoc ${CMAKE_BINARY_DIR}\\P10)
    add_custom_command(TARGET SimTest POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E env PATH="${customQtBin}"
            ${customQtDeploy} $<TARGET_FILE:SimTest>
            COMMENT "Calling windeployqt...")
endif()

