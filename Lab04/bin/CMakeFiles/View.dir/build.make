# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/nathan/Área de Trabalho/Lab04"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nathan/Área de Trabalho/Lab04/bin"

# Include any dependencies generated for this target.
include CMakeFiles/View.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/View.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/View.dir/flags.make

CMakeFiles/View.dir/src/View.cpp.o: CMakeFiles/View.dir/flags.make
CMakeFiles/View.dir/src/View.cpp.o: ../src/View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/nathan/Área de Trabalho/Lab04/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/View.dir/src/View.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/View.dir/src/View.cpp.o -c "/home/nathan/Área de Trabalho/Lab04/src/View.cpp"

CMakeFiles/View.dir/src/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/View.dir/src/View.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/nathan/Área de Trabalho/Lab04/src/View.cpp" > CMakeFiles/View.dir/src/View.cpp.i

CMakeFiles/View.dir/src/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/View.dir/src/View.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/nathan/Área de Trabalho/Lab04/src/View.cpp" -o CMakeFiles/View.dir/src/View.cpp.s

# Object files for target View
View_OBJECTS = \
"CMakeFiles/View.dir/src/View.cpp.o"

# External object files for target View
View_EXTERNAL_OBJECTS =

libView.a: CMakeFiles/View.dir/src/View.cpp.o
libView.a: CMakeFiles/View.dir/build.make
libView.a: CMakeFiles/View.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/nathan/Área de Trabalho/Lab04/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libView.a"
	$(CMAKE_COMMAND) -P CMakeFiles/View.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/View.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/View.dir/build: libView.a

.PHONY : CMakeFiles/View.dir/build

CMakeFiles/View.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/View.dir/cmake_clean.cmake
.PHONY : CMakeFiles/View.dir/clean

CMakeFiles/View.dir/depend:
	cd "/home/nathan/Área de Trabalho/Lab04/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nathan/Área de Trabalho/Lab04" "/home/nathan/Área de Trabalho/Lab04" "/home/nathan/Área de Trabalho/Lab04/bin" "/home/nathan/Área de Trabalho/Lab04/bin" "/home/nathan/Área de Trabalho/Lab04/bin/CMakeFiles/View.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/View.dir/depend

