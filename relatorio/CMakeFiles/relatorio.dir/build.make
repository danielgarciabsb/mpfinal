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
include relatorio/CMakeFiles/relatorio.dir/depend.make

# Include the progress variables for this target.
include relatorio/CMakeFiles/relatorio.dir/progress.make

# Include the compile flags for this target's objects.
include relatorio/CMakeFiles/relatorio.dir/flags.make

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o: relatorio/CMakeFiles/relatorio.dir/flags.make
relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o: relatorio/relatorio.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/igor/Área de Trabalho/mpFelioe/mpfinal/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/relatorio.dir/relatorio.cpp.o -c "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio/relatorio.cpp"

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/relatorio.dir/relatorio.cpp.i"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio/relatorio.cpp" > CMakeFiles/relatorio.dir/relatorio.cpp.i

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/relatorio.dir/relatorio.cpp.s"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio/relatorio.cpp" -o CMakeFiles/relatorio.dir/relatorio.cpp.s

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.requires:
.PHONY : relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.requires

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.provides: relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.requires
	$(MAKE) -f relatorio/CMakeFiles/relatorio.dir/build.make relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.provides.build
.PHONY : relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.provides

relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.provides.build: relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o

# Object files for target relatorio
relatorio_OBJECTS = \
"CMakeFiles/relatorio.dir/relatorio.cpp.o"

# External object files for target relatorio
relatorio_EXTERNAL_OBJECTS =

relatorio/librelatorio.a: relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o
relatorio/librelatorio.a: relatorio/CMakeFiles/relatorio.dir/build.make
relatorio/librelatorio.a: relatorio/CMakeFiles/relatorio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library librelatorio.a"
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && $(CMAKE_COMMAND) -P CMakeFiles/relatorio.dir/cmake_clean_target.cmake
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/relatorio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
relatorio/CMakeFiles/relatorio.dir/build: relatorio/librelatorio.a
.PHONY : relatorio/CMakeFiles/relatorio.dir/build

relatorio/CMakeFiles/relatorio.dir/requires: relatorio/CMakeFiles/relatorio.dir/relatorio.cpp.o.requires
.PHONY : relatorio/CMakeFiles/relatorio.dir/requires

relatorio/CMakeFiles/relatorio.dir/clean:
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" && $(CMAKE_COMMAND) -P CMakeFiles/relatorio.dir/cmake_clean.cmake
.PHONY : relatorio/CMakeFiles/relatorio.dir/clean

relatorio/CMakeFiles/relatorio.dir/depend:
	cd "/home/igor/Área de Trabalho/mpFelioe/mpfinal" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/igor/Área de Trabalho/mpFelioe/mpfinal" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" "/home/igor/Área de Trabalho/mpFelioe/mpfinal" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio" "/home/igor/Área de Trabalho/mpFelioe/mpfinal/relatorio/CMakeFiles/relatorio.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : relatorio/CMakeFiles/relatorio.dir/depend

