# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/igor/Área de Trabalho/mpFelioe/mpfinal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/igor/Área de Trabalho/mpFelioe/mpfinal"

# Include any dependencies generated for this target.
include elemento/CMakeFiles/elemento.dir/depend.make

# Include the progress variables for this target.
include elemento/CMakeFiles/elemento.dir/progress.make

# Include the compile flags for this target's objects.
include elemento/CMakeFiles/elemento.dir/flags.make

elemento/CMakeFiles/elemento.dir/elemento.cpp.o: elemento/CMakeFiles/elemento.dir/flags.make
elemento/CMakeFiles/elemento.dir/elemento.cpp.o: elemento/elemento.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/igor/Área de Trabalho/mpFelioe/mpfinal/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object elemento/CMakeFiles/elemento.dir/elemento.cpp.o"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/elemento.dir/elemento.cpp.o -c "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento/elemento.cpp"

elemento/CMakeFiles/elemento.dir/elemento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/elemento.dir/elemento.cpp.i"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento/elemento.cpp" > CMakeFiles/elemento.dir/elemento.cpp.i

elemento/CMakeFiles/elemento.dir/elemento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/elemento.dir/elemento.cpp.s"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento/elemento.cpp" -o CMakeFiles/elemento.dir/elemento.cpp.s

elemento/CMakeFiles/elemento.dir/elemento.cpp.o.requires:
.PHONY : elemento/CMakeFiles/elemento.dir/elemento.cpp.o.requires

elemento/CMakeFiles/elemento.dir/elemento.cpp.o.provides: elemento/CMakeFiles/elemento.dir/elemento.cpp.o.requires
	$(MAKE) -f elemento/CMakeFiles/elemento.dir/build.make elemento/CMakeFiles/elemento.dir/elemento.cpp.o.provides.build
.PHONY : elemento/CMakeFiles/elemento.dir/elemento.cpp.o.provides

elemento/CMakeFiles/elemento.dir/elemento.cpp.o.provides.build: elemento/CMakeFiles/elemento.dir/elemento.cpp.o

# Object files for target elemento
elemento_OBJECTS = \
"CMakeFiles/elemento.dir/elemento.cpp.o"

# External object files for target elemento
elemento_EXTERNAL_OBJECTS =

elemento/libelemento.a: elemento/CMakeFiles/elemento.dir/elemento.cpp.o
elemento/libelemento.a: elemento/CMakeFiles/elemento.dir/build.make
elemento/libelemento.a: elemento/CMakeFiles/elemento.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libelemento.a"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && $(CMAKE_COMMAND) -P CMakeFiles/elemento.dir/cmake_clean_target.cmake
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/elemento.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
elemento/CMakeFiles/elemento.dir/build: elemento/libelemento.a
.PHONY : elemento/CMakeFiles/elemento.dir/build

elemento/CMakeFiles/elemento.dir/requires: elemento/CMakeFiles/elemento.dir/elemento.cpp.o.requires
.PHONY : elemento/CMakeFiles/elemento.dir/requires

elemento/CMakeFiles/elemento.dir/clean:
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" && $(CMAKE_COMMAND) -P CMakeFiles/elemento.dir/cmake_clean.cmake
.PHONY : elemento/CMakeFiles/elemento.dir/clean

elemento/CMakeFiles/elemento.dir/depend:
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/igor/Área de Trabalho/mpFelioe/mpfinal" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" "/home/igor/Área de Trabalho/mpFelioe/mpfinal" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/elemento/CMakeFiles/elemento.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : elemento/CMakeFiles/elemento.dir/depend

