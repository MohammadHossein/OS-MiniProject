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
CMAKE_SOURCE_DIR = /home/dragon/CLionProjects/mini-thread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dragon/CLionProjects/mini-thread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mini_thread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mini_thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mini_thread.dir/flags.make

CMakeFiles/mini_thread.dir/main.cpp.o: CMakeFiles/mini_thread.dir/flags.make
CMakeFiles/mini_thread.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dragon/CLionProjects/mini-thread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mini_thread.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mini_thread.dir/main.cpp.o -c /home/dragon/CLionProjects/mini-thread/main.cpp

CMakeFiles/mini_thread.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mini_thread.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dragon/CLionProjects/mini-thread/main.cpp > CMakeFiles/mini_thread.dir/main.cpp.i

CMakeFiles/mini_thread.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mini_thread.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dragon/CLionProjects/mini-thread/main.cpp -o CMakeFiles/mini_thread.dir/main.cpp.s

CMakeFiles/mini_thread.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/mini_thread.dir/main.cpp.o.requires

CMakeFiles/mini_thread.dir/main.cpp.o.provides: CMakeFiles/mini_thread.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mini_thread.dir/build.make CMakeFiles/mini_thread.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/mini_thread.dir/main.cpp.o.provides

CMakeFiles/mini_thread.dir/main.cpp.o.provides.build: CMakeFiles/mini_thread.dir/main.cpp.o


# Object files for target mini_thread
mini_thread_OBJECTS = \
"CMakeFiles/mini_thread.dir/main.cpp.o"

# External object files for target mini_thread
mini_thread_EXTERNAL_OBJECTS =

mini_thread: CMakeFiles/mini_thread.dir/main.cpp.o
mini_thread: CMakeFiles/mini_thread.dir/build.make
mini_thread: CMakeFiles/mini_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dragon/CLionProjects/mini-thread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mini_thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mini_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mini_thread.dir/build: mini_thread

.PHONY : CMakeFiles/mini_thread.dir/build

CMakeFiles/mini_thread.dir/requires: CMakeFiles/mini_thread.dir/main.cpp.o.requires

.PHONY : CMakeFiles/mini_thread.dir/requires

CMakeFiles/mini_thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mini_thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mini_thread.dir/clean

CMakeFiles/mini_thread.dir/depend:
	cd /home/dragon/CLionProjects/mini-thread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dragon/CLionProjects/mini-thread /home/dragon/CLionProjects/mini-thread /home/dragon/CLionProjects/mini-thread/cmake-build-debug /home/dragon/CLionProjects/mini-thread/cmake-build-debug /home/dragon/CLionProjects/mini-thread/cmake-build-debug/CMakeFiles/mini_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mini_thread.dir/depend
