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
include CMakeFiles/NOI_online_R3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NOI_online_R3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NOI_online_R3.dir/flags.make

CMakeFiles/NOI_online_R3.dir/main.cpp.o: CMakeFiles/NOI_online_R3.dir/flags.make
CMakeFiles/NOI_online_R3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NOI_online_R3.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NOI_online_R3.dir/main.cpp.o -c "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/main.cpp"

CMakeFiles/NOI_online_R3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NOI_online_R3.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/main.cpp" > CMakeFiles/NOI_online_R3.dir/main.cpp.i

CMakeFiles/NOI_online_R3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NOI_online_R3.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/main.cpp" -o CMakeFiles/NOI_online_R3.dir/main.cpp.s

# Object files for target NOI_online_R3
NOI_online_R3_OBJECTS = \
"CMakeFiles/NOI_online_R3.dir/main.cpp.o"

# External object files for target NOI_online_R3
NOI_online_R3_EXTERNAL_OBJECTS =

NOI_online_R3: CMakeFiles/NOI_online_R3.dir/main.cpp.o
NOI_online_R3: CMakeFiles/NOI_online_R3.dir/build.make
NOI_online_R3: CMakeFiles/NOI_online_R3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NOI_online_R3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NOI_online_R3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NOI_online_R3.dir/build: NOI_online_R3

.PHONY : CMakeFiles/NOI_online_R3.dir/build

CMakeFiles/NOI_online_R3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NOI_online_R3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NOI_online_R3.dir/clean

CMakeFiles/NOI_online_R3.dir/depend:
	cd "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug" "/Users/zhangcheng/OneDrive - zhangyiming/OI/code/other/NOI online R3/cmake-build-debug/CMakeFiles/NOI_online_R3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NOI_online_R3.dir/depend

