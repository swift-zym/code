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
CMAKE_SOURCE_DIR = /home/swift/Documents/code-new/2020.7.25

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code-new/2020.7.25/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B-dm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B-dm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B-dm.dir/flags.make

CMakeFiles/B-dm.dir/B-dm.cpp.o: CMakeFiles/B-dm.dir/flags.make
CMakeFiles/B-dm.dir/B-dm.cpp.o: ../B-dm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code-new/2020.7.25/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B-dm.dir/B-dm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/B-dm.dir/B-dm.cpp.o -c /home/swift/Documents/code-new/2020.7.25/B-dm.cpp

CMakeFiles/B-dm.dir/B-dm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B-dm.dir/B-dm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code-new/2020.7.25/B-dm.cpp > CMakeFiles/B-dm.dir/B-dm.cpp.i

CMakeFiles/B-dm.dir/B-dm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B-dm.dir/B-dm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code-new/2020.7.25/B-dm.cpp -o CMakeFiles/B-dm.dir/B-dm.cpp.s

# Object files for target B-dm
B__dm_OBJECTS = \
"CMakeFiles/B-dm.dir/B-dm.cpp.o"

# External object files for target B-dm
B__dm_EXTERNAL_OBJECTS =

B-dm: CMakeFiles/B-dm.dir/B-dm.cpp.o
B-dm: CMakeFiles/B-dm.dir/build.make
B-dm: CMakeFiles/B-dm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code-new/2020.7.25/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B-dm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/B-dm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B-dm.dir/build: B-dm

.PHONY : CMakeFiles/B-dm.dir/build

CMakeFiles/B-dm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/B-dm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/B-dm.dir/clean

CMakeFiles/B-dm.dir/depend:
	cd /home/swift/Documents/code-new/2020.7.25/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code-new/2020.7.25 /home/swift/Documents/code-new/2020.7.25 /home/swift/Documents/code-new/2020.7.25/cmake-build-debug /home/swift/Documents/code-new/2020.7.25/cmake-build-debug /home/swift/Documents/code-new/2020.7.25/cmake-build-debug/CMakeFiles/B-dm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B-dm.dir/depend

