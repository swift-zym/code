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
CMAKE_SOURCE_DIR = "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/star.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/star.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/star.dir/flags.make

CMakeFiles/star.dir/star.cpp.o: CMakeFiles/star.dir/flags.make
CMakeFiles/star.dir/star.cpp.o: ../star.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/star.dir/star.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/star.cpp.o -c "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/star.cpp"

CMakeFiles/star.dir/star.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/star.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/star.cpp" > CMakeFiles/star.dir/star.cpp.i

CMakeFiles/star.dir/star.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/star.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/star.cpp" -o CMakeFiles/star.dir/star.cpp.s

# Object files for target star
star_OBJECTS = \
"CMakeFiles/star.dir/star.cpp.o"

# External object files for target star
star_EXTERNAL_OBJECTS =

star: CMakeFiles/star.dir/star.cpp.o
star: CMakeFiles/star.dir/build.make
star: CMakeFiles/star.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable star"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/star.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/star.dir/build: star

.PHONY : CMakeFiles/star.dir/build

CMakeFiles/star.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/star.dir/cmake_clean.cmake
.PHONY : CMakeFiles/star.dir/clean

CMakeFiles/star.dir/depend:
	cd "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles/star.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/star.dir/depend

