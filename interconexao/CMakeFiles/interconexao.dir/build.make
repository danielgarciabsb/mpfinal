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
include interconexao/CMakeFiles/interconexao.dir/depend.make

# Include the progress variables for this target.
include interconexao/CMakeFiles/interconexao.dir/progress.make

# Include the compile flags for this target's objects.
include interconexao/CMakeFiles/interconexao.dir/flags.make

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o: interconexao/CMakeFiles/interconexao.dir/flags.make
interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o: interconexao/interconexao.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/igor/Área de Trabalho/ProjetoFinal/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/interconexao.dir/interconexao.cpp.o -c "/home/igor/Área de Trabalho/ProjetoFinal/interconexao/interconexao.cpp"

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interconexao.dir/interconexao.cpp.i"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/igor/Área de Trabalho/ProjetoFinal/interconexao/interconexao.cpp" > CMakeFiles/interconexao.dir/interconexao.cpp.i

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interconexao.dir/interconexao.cpp.s"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/igor/Área de Trabalho/ProjetoFinal/interconexao/interconexao.cpp" -o CMakeFiles/interconexao.dir/interconexao.cpp.s

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.requires:
.PHONY : interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.requires

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.provides: interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.requires
	$(MAKE) -f interconexao/CMakeFiles/interconexao.dir/build.make interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.provides.build
.PHONY : interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.provides

interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.provides.build: interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o

# Object files for target interconexao
interconexao_OBJECTS = \
"CMakeFiles/interconexao.dir/interconexao.cpp.o"

# External object files for target interconexao
interconexao_EXTERNAL_OBJECTS =

interconexao/libinterconexao.a: interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o
interconexao/libinterconexao.a: interconexao/CMakeFiles/interconexao.dir/build.make
interconexao/libinterconexao.a: interconexao/CMakeFiles/interconexao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libinterconexao.a"
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && $(CMAKE_COMMAND) -P CMakeFiles/interconexao.dir/cmake_clean_target.cmake
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interconexao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
interconexao/CMakeFiles/interconexao.dir/build: interconexao/libinterconexao.a
.PHONY : interconexao/CMakeFiles/interconexao.dir/build

interconexao/CMakeFiles/interconexao.dir/requires: interconexao/CMakeFiles/interconexao.dir/interconexao.cpp.o.requires
.PHONY : interconexao/CMakeFiles/interconexao.dir/requires

interconexao/CMakeFiles/interconexao.dir/clean:
	cd "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" && $(CMAKE_COMMAND) -P CMakeFiles/interconexao.dir/cmake_clean.cmake
.PHONY : interconexao/CMakeFiles/interconexao.dir/clean

interconexao/CMakeFiles/interconexao.dir/depend:
	cd "/home/igor/Área de Trabalho/ProjetoFinal" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/igor/Área de Trabalho/ProjetoFinal" "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" "/home/igor/Área de Trabalho/ProjetoFinal" "/home/igor/Área de Trabalho/ProjetoFinal/interconexao" "/home/igor/Área de Trabalho/ProjetoFinal/interconexao/CMakeFiles/interconexao.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : interconexao/CMakeFiles/interconexao.dir/depend

