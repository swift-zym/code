# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /home/swift/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/swift/Documents/code-new/2020.8.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code-new/2020.8.2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P3857.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P3857.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P3857.dir/flags.make

CMakeFiles/P3857.dir/P3857.cpp.o: CMakeFiles/P3857.dir/flags.make
CMakeFiles/P3857.dir/P3857.cpp.o: ../P3857.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code-new/2020.8.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P3857.dir/P3857.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P3857.dir/P3857.cpp.o -c /home/swift/Documents/code-new/2020.8.2/P3857.cpp

CMakeFiles/P3857.dir/P3857.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P3857.dir/P3857.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code-new/2020.8.2/P3857.cpp > CMakeFiles/P3857.dir/P3857.cpp.i

CMakeFiles/P3857.dir/P3857.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P3857.dir/P3857.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code-new/2020.8.2/P3857.cpp -o CMakeFiles/P3857.dir/P3857.cpp.s

# Object files for target P3857
P3857_OBJECTS = \
"CMakeFiles/P3857.dir/P3857.cpp.o"

# External object files for target P3857
P3857_EXTERNAL_OBJECTS =

P3857: CMakeFiles/P3857.dir/P3857.cpp.o
P3857: CMakeFiles/P3857.dir/build.make
P3857: CMakeFiles/P3857.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code-new/2020.8.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P3857"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P3857.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P3857.dir/build: P3857

.PHONY : CMakeFiles/P3857.dir/build

CMakeFiles/P3857.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P3857.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P3857.dir/clean

CMakeFiles/P3857.dir/depend:
	cd /home/swift/Documents/code-new/2020.8.2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code-new/2020.8.2 /home/swift/Documents/code-new/2020.8.2 /home/swift/Documents/code-new/2020.8.2/cmake-build-debug /home/swift/Documents/code-new/2020.8.2/cmake-build-debug /home/swift/Documents/code-new/2020.8.2/cmake-build-debug/CMakeFiles/P3857.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P3857.dir/depend

