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
CMAKE_SOURCE_DIR = /home/swift/Documents/code-new/2020.7.30

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code-new/2020.7.30/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2708-7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2708-7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2708-7.dir/flags.make

CMakeFiles/2708-7.dir/2708-7.cpp.o: CMakeFiles/2708-7.dir/flags.make
CMakeFiles/2708-7.dir/2708-7.cpp.o: ../2708-7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code-new/2020.7.30/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2708-7.dir/2708-7.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2708-7.dir/2708-7.cpp.o -c /home/swift/Documents/code-new/2020.7.30/2708-7.cpp

CMakeFiles/2708-7.dir/2708-7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2708-7.dir/2708-7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code-new/2020.7.30/2708-7.cpp > CMakeFiles/2708-7.dir/2708-7.cpp.i

CMakeFiles/2708-7.dir/2708-7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2708-7.dir/2708-7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code-new/2020.7.30/2708-7.cpp -o CMakeFiles/2708-7.dir/2708-7.cpp.s

# Object files for target 2708-7
2708__7_OBJECTS = \
"CMakeFiles/2708-7.dir/2708-7.cpp.o"

# External object files for target 2708-7
2708__7_EXTERNAL_OBJECTS =

2708-7: CMakeFiles/2708-7.dir/2708-7.cpp.o
2708-7: CMakeFiles/2708-7.dir/build.make
2708-7: CMakeFiles/2708-7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code-new/2020.7.30/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2708-7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2708-7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2708-7.dir/build: 2708-7

.PHONY : CMakeFiles/2708-7.dir/build

CMakeFiles/2708-7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2708-7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2708-7.dir/clean

CMakeFiles/2708-7.dir/depend:
	cd /home/swift/Documents/code-new/2020.7.30/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code-new/2020.7.30 /home/swift/Documents/code-new/2020.7.30 /home/swift/Documents/code-new/2020.7.30/cmake-build-debug /home/swift/Documents/code-new/2020.7.30/cmake-build-debug /home/swift/Documents/code-new/2020.7.30/cmake-build-debug/CMakeFiles/2708-7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2708-7.dir/depend

