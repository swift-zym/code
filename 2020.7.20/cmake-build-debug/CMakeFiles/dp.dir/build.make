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
CMAKE_SOURCE_DIR = /home/swift/Documents/code-new/2020.7.20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code-new/2020.7.20/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dp.dir/flags.make

CMakeFiles/dp.dir/dp.cpp.o: CMakeFiles/dp.dir/flags.make
CMakeFiles/dp.dir/dp.cpp.o: ../dp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code-new/2020.7.20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dp.dir/dp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp.dir/dp.cpp.o -c /home/swift/Documents/code-new/2020.7.20/dp.cpp

CMakeFiles/dp.dir/dp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp.dir/dp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code-new/2020.7.20/dp.cpp > CMakeFiles/dp.dir/dp.cpp.i

CMakeFiles/dp.dir/dp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp.dir/dp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code-new/2020.7.20/dp.cpp -o CMakeFiles/dp.dir/dp.cpp.s

# Object files for target dp
dp_OBJECTS = \
"CMakeFiles/dp.dir/dp.cpp.o"

# External object files for target dp
dp_EXTERNAL_OBJECTS =

dp: CMakeFiles/dp.dir/dp.cpp.o
dp: CMakeFiles/dp.dir/build.make
dp: CMakeFiles/dp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code-new/2020.7.20/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dp.dir/build: dp

.PHONY : CMakeFiles/dp.dir/build

CMakeFiles/dp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dp.dir/clean

CMakeFiles/dp.dir/depend:
	cd /home/swift/Documents/code-new/2020.7.20/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code-new/2020.7.20 /home/swift/Documents/code-new/2020.7.20 /home/swift/Documents/code-new/2020.7.20/cmake-build-debug /home/swift/Documents/code-new/2020.7.20/cmake-build-debug /home/swift/Documents/code-new/2020.7.20/cmake-build-debug/CMakeFiles/dp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dp.dir/depend

