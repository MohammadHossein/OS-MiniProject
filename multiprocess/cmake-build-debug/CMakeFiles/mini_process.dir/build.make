# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/dragon/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dragon/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dragon/CLionProjects/mini_process

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dragon/CLionProjects/mini_process/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mini_process.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mini_process.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mini_process.dir/flags.make

CMakeFiles/mini_process.dir/main.cpp.o: CMakeFiles/mini_process.dir/flags.make
CMakeFiles/mini_process.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dragon/CLionProjects/mini_process/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mini_process.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mini_process.dir/main.cpp.o -c /home/dragon/CLionProjects/mini_process/main.cpp

CMakeFiles/mini_process.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mini_process.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dragon/CLionProjects/mini_process/main.cpp > CMakeFiles/mini_process.dir/main.cpp.i

CMakeFiles/mini_process.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mini_process.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dragon/CLionProjects/mini_process/main.cpp -o CMakeFiles/mini_process.dir/main.cpp.s

CMakeFiles/mini_process.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/mini_process.dir/main.cpp.o.requires

CMakeFiles/mini_process.dir/main.cpp.o.provides: CMakeFiles/mini_process.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mini_process.dir/build.make CMakeFiles/mini_process.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/mini_process.dir/main.cpp.o.provides

CMakeFiles/mini_process.dir/main.cpp.o.provides.build: CMakeFiles/mini_process.dir/main.cpp.o


# Object files for target mini_process
mini_process_OBJECTS = \
"CMakeFiles/mini_process.dir/main.cpp.o"

# External object files for target mini_process
mini_process_EXTERNAL_OBJECTS =

mini_process: CMakeFiles/mini_process.dir/main.cpp.o
mini_process: CMakeFiles/mini_process.dir/build.make
mini_process: CMakeFiles/mini_process.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dragon/CLionProjects/mini_process/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mini_process"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mini_process.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mini_process.dir/build: mini_process

.PHONY : CMakeFiles/mini_process.dir/build

CMakeFiles/mini_process.dir/requires: CMakeFiles/mini_process.dir/main.cpp.o.requires

.PHONY : CMakeFiles/mini_process.dir/requires

CMakeFiles/mini_process.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mini_process.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mini_process.dir/clean

CMakeFiles/mini_process.dir/depend:
	cd /home/dragon/CLionProjects/mini_process/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dragon/CLionProjects/mini_process /home/dragon/CLionProjects/mini_process /home/dragon/CLionProjects/mini_process/cmake-build-debug /home/dragon/CLionProjects/mini_process/cmake-build-debug /home/dragon/CLionProjects/mini_process/cmake-build-debug/CMakeFiles/mini_process.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mini_process.dir/depend

