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
CMAKE_SOURCE_DIR = "/home/igor/Área de Trabalho/ProjetoFinal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/igor/Área de Trabalho/ProjetoFinal"

# Include any dependencies generated for this target.
include gerador/CMakeFiles/gerador.dir/depend.make

# Include the progress variables for this target.
include gerador/CMakeFiles/gerador.dir/progress.make

# Include the compile flags for this target's objects.
include gerador/CMakeFiles/gerador.dir/flags.make

gerador/CMakeFiles/gerador.dir/gerador.cpp.o: gerador/CMakeFiles/gerador.dir/flags.make
gerador/CMakeFiles/gerador.dir/gerador.cpp.o: gerador/gerador.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/igor/Área de Trabalho/ProjetoFinal/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gerador/CMakeFiles/gerador.dir/gerador.cpp.o"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gerador.dir/gerador.cpp.o -c "/home/igor/Área de Trabalho/ProjetoFinal/gerador/gerador.cpp"

gerador/CMakeFiles/gerador.dir/gerador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gerador.dir/gerador.cpp.i"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/igor/Área de Trabalho/ProjetoFinal/gerador/gerador.cpp" > CMakeFiles/gerador.dir/gerador.cpp.i

gerador/CMakeFiles/gerador.dir/gerador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gerador.dir/gerador.cpp.s"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/igor/Área de Trabalho/ProjetoFinal/gerador/gerador.cpp" -o CMakeFiles/gerador.dir/gerador.cpp.s

gerador/CMakeFiles/gerador.dir/gerador.cpp.o.requires:
.PHONY : gerador/CMakeFiles/gerador.dir/gerador.cpp.o.requires

gerador/CMakeFiles/gerador.dir/gerador.cpp.o.provides: gerador/CMakeFiles/gerador.dir/gerador.cpp.o.requires
	$(MAKE) -f gerador/CMakeFiles/gerador.dir/build.make gerador/CMakeFiles/gerador.dir/gerador.cpp.o.provides.build
.PHONY : gerador/CMakeFiles/gerador.dir/gerador.cpp.o.provides

gerador/CMakeFiles/gerador.dir/gerador.cpp.o.provides.build: gerador/CMakeFiles/gerador.dir/gerador.cpp.o

# Object files for target gerador
gerador_OBJECTS = \
"CMakeFiles/gerador.dir/gerador.cpp.o"

# External object files for target gerador
gerador_EXTERNAL_OBJECTS =

gerador/libgerador.a: gerador/CMakeFiles/gerador.dir/gerador.cpp.o
gerador/libgerador.a: gerador/CMakeFiles/gerador.dir/build.make
gerador/libgerador.a: gerador/CMakeFiles/gerador.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgerador.a"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && $(CMAKE_COMMAND) -P CMakeFiles/gerador.dir/cmake_clean_target.cmake
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gerador.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gerador/CMakeFiles/gerador.dir/build: gerador/libgerador.a
.PHONY : gerador/CMakeFiles/gerador.dir/build

gerador/CMakeFiles/gerador.dir/requires: gerador/CMakeFiles/gerador.dir/gerador.cpp.o.requires
.PHONY : gerador/CMakeFiles/gerador.dir/requires

gerador/CMakeFiles/gerador.dir/clean:
	cd "/home/igor/Área de Trabalho/ProjetoFinal/gerador" && $(CMAKE_COMMAND) -P CMakeFiles/gerador.dir/cmake_clean.cmake
.PHONY : gerador/CMakeFiles/gerador.dir/clean

gerador/CMakeFiles/gerador.dir/depend:
	cd "/home/igor/Área de Trabalho/ProjetoFinal" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/igor/Área de Trabalho/ProjetoFinal" "/home/igor/Área de Trabalho/ProjetoFinal/gerador" "/home/igor/Área de Trabalho/ProjetoFinal" "/home/igor/Área de Trabalho/ProjetoFinal/gerador" "/home/igor/Área de Trabalho/ProjetoFinal/gerador/CMakeFiles/gerador.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : gerador/CMakeFiles/gerador.dir/depend

