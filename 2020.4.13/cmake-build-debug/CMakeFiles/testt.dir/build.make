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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/testt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testt.dir/flags.make

CMakeFiles/testt.dir/testt.cpp.o: CMakeFiles/testt.dir/flags.make
CMakeFiles/testt.dir/testt.cpp.o: testt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testt.dir/testt.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testt.dir/testt.cpp.o -c "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/testt.cpp"

CMakeFiles/testt.dir/testt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testt.dir/testt.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/testt.cpp" > CMakeFiles/testt.dir/testt.cpp.i

CMakeFiles/testt.dir/testt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testt.dir/testt.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/testt.cpp" -o CMakeFiles/testt.dir/testt.cpp.s

# Object files for target testt
testt_OBJECTS = \
"CMakeFiles/testt.dir/testt.cpp.o"

# External object files for target testt
testt_EXTERNAL_OBJECTS =

testt: CMakeFiles/testt.dir/testt.cpp.o
testt: CMakeFiles/testt.dir/build.make
testt: CMakeFiles/testt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testt.dir/build: testt

.PHONY : CMakeFiles/testt.dir/build

CMakeFiles/testt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testt.dir/clean

CMakeFiles/testt.dir/depend:
	cd "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/2020.4.13/cmake-build-debug/CMakeFiles/testt.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/testt.dir/depend

