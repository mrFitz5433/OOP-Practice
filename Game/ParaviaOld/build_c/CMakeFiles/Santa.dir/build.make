# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Fitz/Desktop/santa-paravia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Fitz/Desktop/santa-paravia/build_c

# Include any dependencies generated for this target.
include CMakeFiles/Santa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Santa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Santa.dir/flags.make

CMakeFiles/Santa.dir/paravia.c.o: CMakeFiles/Santa.dir/flags.make
CMakeFiles/Santa.dir/paravia.c.o: ../paravia.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Fitz/Desktop/santa-paravia/build_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Santa.dir/paravia.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Santa.dir/paravia.c.o   -c /Users/Fitz/Desktop/santa-paravia/paravia.c

CMakeFiles/Santa.dir/paravia.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Santa.dir/paravia.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Fitz/Desktop/santa-paravia/paravia.c > CMakeFiles/Santa.dir/paravia.c.i

CMakeFiles/Santa.dir/paravia.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Santa.dir/paravia.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Fitz/Desktop/santa-paravia/paravia.c -o CMakeFiles/Santa.dir/paravia.c.s

CMakeFiles/Santa.dir/paravia.c.o.requires:

.PHONY : CMakeFiles/Santa.dir/paravia.c.o.requires

CMakeFiles/Santa.dir/paravia.c.o.provides: CMakeFiles/Santa.dir/paravia.c.o.requires
	$(MAKE) -f CMakeFiles/Santa.dir/build.make CMakeFiles/Santa.dir/paravia.c.o.provides.build
.PHONY : CMakeFiles/Santa.dir/paravia.c.o.provides

CMakeFiles/Santa.dir/paravia.c.o.provides.build: CMakeFiles/Santa.dir/paravia.c.o


# Object files for target Santa
Santa_OBJECTS = \
"CMakeFiles/Santa.dir/paravia.c.o"

# External object files for target Santa
Santa_EXTERNAL_OBJECTS =

Santa: CMakeFiles/Santa.dir/paravia.c.o
Santa: CMakeFiles/Santa.dir/build.make
Santa: CMakeFiles/Santa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Fitz/Desktop/santa-paravia/build_c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Santa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Santa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Santa.dir/build: Santa

.PHONY : CMakeFiles/Santa.dir/build

CMakeFiles/Santa.dir/requires: CMakeFiles/Santa.dir/paravia.c.o.requires

.PHONY : CMakeFiles/Santa.dir/requires

CMakeFiles/Santa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Santa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Santa.dir/clean

CMakeFiles/Santa.dir/depend:
	cd /Users/Fitz/Desktop/santa-paravia/build_c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Fitz/Desktop/santa-paravia /Users/Fitz/Desktop/santa-paravia /Users/Fitz/Desktop/santa-paravia/build_c /Users/Fitz/Desktop/santa-paravia/build_c /Users/Fitz/Desktop/santa-paravia/build_c/CMakeFiles/Santa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Santa.dir/depend
