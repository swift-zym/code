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
CMAKE_SOURCE_DIR = /home/swift/Documents/code-new/2020.8.9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/swift/Documents/code-new/2020.8.9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CC.dir/flags.make

CMakeFiles/CC.dir/CC.cpp.o: CMakeFiles/CC.dir/flags.make
CMakeFiles/CC.dir/CC.cpp.o: ../CC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/swift/Documents/code-new/2020.8.9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CC.dir/CC.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CC.dir/CC.cpp.o -c /home/swift/Documents/code-new/2020.8.9/CC.cpp

CMakeFiles/CC.dir/CC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CC.dir/CC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/swift/Documents/code-new/2020.8.9/CC.cpp > CMakeFiles/CC.dir/CC.cpp.i

CMakeFiles/CC.dir/CC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CC.dir/CC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/swift/Documents/code-new/2020.8.9/CC.cpp -o CMakeFiles/CC.dir/CC.cpp.s

# Object files for target CC
CC_OBJECTS = \
"CMakeFiles/CC.dir/CC.cpp.o"

# External object files for target CC
CC_EXTERNAL_OBJECTS =

CC: CMakeFiles/CC.dir/CC.cpp.o
CC: CMakeFiles/CC.dir/build.make
CC: CMakeFiles/CC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/swift/Documents/code-new/2020.8.9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CC.dir/build: CC

.PHONY : CMakeFiles/CC.dir/build

CMakeFiles/CC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CC.dir/clean

CMakeFiles/CC.dir/depend:
	cd /home/swift/Documents/code-new/2020.8.9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/swift/Documents/code-new/2020.8.9 /home/swift/Documents/code-new/2020.8.9 /home/swift/Documents/code-new/2020.8.9/cmake-build-debug /home/swift/Documents/code-new/2020.8.9/cmake-build-debug /home/swift/Documents/code-new/2020.8.9/cmake-build-debug/CMakeFiles/CC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CC.dir/depend

