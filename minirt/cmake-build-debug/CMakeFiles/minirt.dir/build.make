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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/itollett/minirt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/itollett/minirt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minirt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minirt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minirt.dir/flags.make

CMakeFiles/minirt.dir/library.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/library.c.o: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/itollett/minirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minirt.dir/library.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/library.c.o   -c /Users/itollett/minirt/library.c

CMakeFiles/minirt.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/library.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/itollett/minirt/library.c > CMakeFiles/minirt.dir/library.c.i

CMakeFiles/minirt.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/library.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/itollett/minirt/library.c -o CMakeFiles/minirt.dir/library.c.s

CMakeFiles/minirt.dir/srcs/minirt.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/srcs/minirt.c.o: ../srcs/minirt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/itollett/minirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minirt.dir/srcs/minirt.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/srcs/minirt.c.o   -c /Users/itollett/minirt/srcs/minirt.c

CMakeFiles/minirt.dir/srcs/minirt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/srcs/minirt.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/itollett/minirt/srcs/minirt.c > CMakeFiles/minirt.dir/srcs/minirt.c.i

CMakeFiles/minirt.dir/srcs/minirt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/srcs/minirt.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/itollett/minirt/srcs/minirt.c -o CMakeFiles/minirt.dir/srcs/minirt.c.s

# Object files for target minirt
minirt_OBJECTS = \
"CMakeFiles/minirt.dir/library.c.o" \
"CMakeFiles/minirt.dir/srcs/minirt.c.o"

# External object files for target minirt
minirt_EXTERNAL_OBJECTS =

libminirt.a: CMakeFiles/minirt.dir/library.c.o
libminirt.a: CMakeFiles/minirt.dir/srcs/minirt.c.o
libminirt.a: CMakeFiles/minirt.dir/build.make
libminirt.a: CMakeFiles/minirt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/itollett/minirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libminirt.a"
	$(CMAKE_COMMAND) -P CMakeFiles/minirt.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minirt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minirt.dir/build: libminirt.a

.PHONY : CMakeFiles/minirt.dir/build

CMakeFiles/minirt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minirt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minirt.dir/clean

CMakeFiles/minirt.dir/depend:
	cd /Users/itollett/minirt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/itollett/minirt /Users/itollett/minirt /Users/itollett/minirt/cmake-build-debug /Users/itollett/minirt/cmake-build-debug /Users/itollett/minirt/cmake-build-debug/CMakeFiles/minirt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minirt.dir/depend
