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
CMAKE_SOURCE_DIR = "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/match.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/match.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/match.dir/flags.make

CMakeFiles/match.dir/match.cpp.o: CMakeFiles/match.dir/flags.make
CMakeFiles/match.dir/match.cpp.o: ../match.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/match.dir/match.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/match.dir/match.cpp.o -c "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/match.cpp"

CMakeFiles/match.dir/match.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/match.dir/match.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/match.cpp" > CMakeFiles/match.dir/match.cpp.i

CMakeFiles/match.dir/match.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/match.dir/match.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/match.cpp" -o CMakeFiles/match.dir/match.cpp.s

# Object files for target match
match_OBJECTS = \
"CMakeFiles/match.dir/match.cpp.o"

# External object files for target match
match_EXTERNAL_OBJECTS =

match: CMakeFiles/match.dir/match.cpp.o
match: CMakeFiles/match.dir/build.make
match: CMakeFiles/match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable match"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/match.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/match.dir/build: match

.PHONY : CMakeFiles/match.dir/build

CMakeFiles/match.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/match.dir/cmake_clean.cmake
.PHONY : CMakeFiles/match.dir/clean

CMakeFiles/match.dir/depend:
	cd "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug" "/Users/zhangcheng/OneDrive - ODMAIL/OI/code/other/NOI online R2/cmake-build-debug/CMakeFiles/match.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/match.dir/depend
