# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/yannis/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/yannis/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetToupie.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetToupie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetToupie.dir/flags.make

CMakeFiles/ProjetToupie.dir/main.cpp.o: CMakeFiles/ProjetToupie.dir/flags.make
CMakeFiles/ProjetToupie.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjetToupie.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetToupie.dir/main.cpp.o -c /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/main.cpp

CMakeFiles/ProjetToupie.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetToupie.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/main.cpp > CMakeFiles/ProjetToupie.dir/main.cpp.i

CMakeFiles/ProjetToupie.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetToupie.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/main.cpp -o CMakeFiles/ProjetToupie.dir/main.cpp.s

CMakeFiles/ProjetToupie.dir/Vecteur.cc.o: CMakeFiles/ProjetToupie.dir/flags.make
CMakeFiles/ProjetToupie.dir/Vecteur.cc.o: ../Vecteur.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjetToupie.dir/Vecteur.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetToupie.dir/Vecteur.cc.o -c /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Vecteur.cc

CMakeFiles/ProjetToupie.dir/Vecteur.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetToupie.dir/Vecteur.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Vecteur.cc > CMakeFiles/ProjetToupie.dir/Vecteur.cc.i

CMakeFiles/ProjetToupie.dir/Vecteur.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetToupie.dir/Vecteur.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Vecteur.cc -o CMakeFiles/ProjetToupie.dir/Vecteur.cc.s

CMakeFiles/ProjetToupie.dir/Matrice.cc.o: CMakeFiles/ProjetToupie.dir/flags.make
CMakeFiles/ProjetToupie.dir/Matrice.cc.o: ../Matrice.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjetToupie.dir/Matrice.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetToupie.dir/Matrice.cc.o -c /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Matrice.cc

CMakeFiles/ProjetToupie.dir/Matrice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetToupie.dir/Matrice.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Matrice.cc > CMakeFiles/ProjetToupie.dir/Matrice.cc.i

CMakeFiles/ProjetToupie.dir/Matrice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetToupie.dir/Matrice.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/Matrice.cc -o CMakeFiles/ProjetToupie.dir/Matrice.cc.s

# Object files for target ProjetToupie
ProjetToupie_OBJECTS = \
"CMakeFiles/ProjetToupie.dir/main.cpp.o" \
"CMakeFiles/ProjetToupie.dir/Vecteur.cc.o" \
"CMakeFiles/ProjetToupie.dir/Matrice.cc.o"

# External object files for target ProjetToupie
ProjetToupie_EXTERNAL_OBJECTS =

ProjetToupie: CMakeFiles/ProjetToupie.dir/main.cpp.o
ProjetToupie: CMakeFiles/ProjetToupie.dir/Vecteur.cc.o
ProjetToupie: CMakeFiles/ProjetToupie.dir/Matrice.cc.o
ProjetToupie: CMakeFiles/ProjetToupie.dir/build.make
ProjetToupie: CMakeFiles/ProjetToupie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ProjetToupie"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetToupie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetToupie.dir/build: ProjetToupie

.PHONY : CMakeFiles/ProjetToupie.dir/build

CMakeFiles/ProjetToupie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetToupie.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetToupie.dir/clean

CMakeFiles/ProjetToupie.dir/depend:
	cd /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug /Users/yannis/Desktop/EPFL/ICC2/Exercices/ProjetToupie/cmake-build-debug/CMakeFiles/ProjetToupie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetToupie.dir/depend

