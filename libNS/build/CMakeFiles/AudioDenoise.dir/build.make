# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build

# Include any dependencies generated for this target.
include CMakeFiles/AudioDenoise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AudioDenoise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AudioDenoise.dir/flags.make

CMakeFiles/AudioDenoise.dir/main.cpp.o: CMakeFiles/AudioDenoise.dir/flags.make
CMakeFiles/AudioDenoise.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AudioDenoise.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AudioDenoise.dir/main.cpp.o -c /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/main.cpp

CMakeFiles/AudioDenoise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AudioDenoise.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/main.cpp > CMakeFiles/AudioDenoise.dir/main.cpp.i

CMakeFiles/AudioDenoise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AudioDenoise.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/main.cpp -o CMakeFiles/AudioDenoise.dir/main.cpp.s

# Object files for target AudioDenoise
AudioDenoise_OBJECTS = \
"CMakeFiles/AudioDenoise.dir/main.cpp.o"

# External object files for target AudioDenoise
AudioDenoise_EXTERNAL_OBJECTS =

AudioDenoise: CMakeFiles/AudioDenoise.dir/main.cpp.o
AudioDenoise: CMakeFiles/AudioDenoise.dir/build.make
AudioDenoise: libNS/libAgNS.a
AudioDenoise: CMakeFiles/AudioDenoise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AudioDenoise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AudioDenoise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AudioDenoise.dir/build: AudioDenoise

.PHONY : CMakeFiles/AudioDenoise.dir/build

CMakeFiles/AudioDenoise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AudioDenoise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AudioDenoise.dir/clean

CMakeFiles/AudioDenoise.dir/depend:
	cd /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build /Users/zhanxiaochao/Desktop/AgVideoDenoise/libNS/build/CMakeFiles/AudioDenoise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AudioDenoise.dir/depend

