# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Videodenoise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Videodenoise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Videodenoise.dir/flags.make

CMakeFiles/Videodenoise.dir/main.cpp.o: CMakeFiles/Videodenoise.dir/flags.make
CMakeFiles/Videodenoise.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Videodenoise.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Videodenoise.dir/main.cpp.o -c /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/main.cpp

CMakeFiles/Videodenoise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Videodenoise.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/main.cpp > CMakeFiles/Videodenoise.dir/main.cpp.i

CMakeFiles/Videodenoise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Videodenoise.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/main.cpp -o CMakeFiles/Videodenoise.dir/main.cpp.s

CMakeFiles/Videodenoise.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Videodenoise.dir/main.cpp.o.requires

CMakeFiles/Videodenoise.dir/main.cpp.o.provides: CMakeFiles/Videodenoise.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Videodenoise.dir/build.make CMakeFiles/Videodenoise.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Videodenoise.dir/main.cpp.o.provides

CMakeFiles/Videodenoise.dir/main.cpp.o.provides.build: CMakeFiles/Videodenoise.dir/main.cpp.o


# Object files for target Videodenoise
Videodenoise_OBJECTS = \
"CMakeFiles/Videodenoise.dir/main.cpp.o"

# External object files for target Videodenoise
Videodenoise_EXTERNAL_OBJECTS =

Videodenoise: CMakeFiles/Videodenoise.dir/main.cpp.o
Videodenoise: CMakeFiles/Videodenoise.dir/build.make
Videodenoise: CMakeFiles/Videodenoise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Videodenoise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Videodenoise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Videodenoise.dir/build: Videodenoise

.PHONY : CMakeFiles/Videodenoise.dir/build

CMakeFiles/Videodenoise.dir/requires: CMakeFiles/Videodenoise.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Videodenoise.dir/requires

CMakeFiles/Videodenoise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Videodenoise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Videodenoise.dir/clean

CMakeFiles/Videodenoise.dir/depend:
	cd /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug /Users/zhanxiaochao/Desktop/AgVideoDenoise/Videodenoise/cmake-build-debug/CMakeFiles/Videodenoise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Videodenoise.dir/depend

