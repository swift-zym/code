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
CMAKE_COMMAND = /home/swift/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/swift/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/swift/Documents/code/2020.6.9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code/2020.6.9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sa.dir/flags.make

CMakeFiles/sa.dir/sa.cpp.o: CMakeFiles/sa.dir/flags.make
CMakeFiles/sa.dir/sa.cpp.o: ../sa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code/2020.6.9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sa.dir/sa.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sa.dir/sa.cpp.o -c /home/swift/Documents/code/2020.6.9/sa.cpp

CMakeFiles/sa.dir/sa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sa.dir/sa.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code/2020.6.9/sa.cpp > CMakeFiles/sa.dir/sa.cpp.i

CMakeFiles/sa.dir/sa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sa.dir/sa.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code/2020.6.9/sa.cpp -o CMakeFiles/sa.dir/sa.cpp.s

# Object files for target sa
sa_OBJECTS = \
"CMakeFiles/sa.dir/sa.cpp.o"

# External object files for target sa
sa_EXTERNAL_OBJECTS =

sa: CMakeFiles/sa.dir/sa.cpp.o
sa: CMakeFiles/sa.dir/build.make
sa: CMakeFiles/sa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code/2020.6.9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sa.dir/build: sa

.PHONY : CMakeFiles/sa.dir/build

CMakeFiles/sa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sa.dir/clean

CMakeFiles/sa.dir/depend:
	cd /home/swift/Documents/code/2020.6.9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code/2020.6.9 /home/swift/Documents/code/2020.6.9 /home/swift/Documents/code/2020.6.9/cmake-build-debug /home/swift/Documents/code/2020.6.9/cmake-build-debug /home/swift/Documents/code/2020.6.9/cmake-build-debug/CMakeFiles/sa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sa.dir/depend

