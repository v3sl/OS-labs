# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/v3sl/Desktop/OS/OS-lab7-linux/pipe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build

# Include any dependencies generated for this target.
include CMakeFiles/pipe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipe.dir/flags.make

CMakeFiles/pipe.dir/pipe.cpp.o: CMakeFiles/pipe.dir/flags.make
CMakeFiles/pipe.dir/pipe.cpp.o: ../pipe.cpp
CMakeFiles/pipe.dir/pipe.cpp.o: CMakeFiles/pipe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pipe.dir/pipe.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipe.dir/pipe.cpp.o -MF CMakeFiles/pipe.dir/pipe.cpp.o.d -o CMakeFiles/pipe.dir/pipe.cpp.o -c /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/pipe.cpp

CMakeFiles/pipe.dir/pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pipe.dir/pipe.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/pipe.cpp > CMakeFiles/pipe.dir/pipe.cpp.i

CMakeFiles/pipe.dir/pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pipe.dir/pipe.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/pipe.cpp -o CMakeFiles/pipe.dir/pipe.cpp.s

# Object files for target pipe
pipe_OBJECTS = \
"CMakeFiles/pipe.dir/pipe.cpp.o"

# External object files for target pipe
pipe_EXTERNAL_OBJECTS =

libpipe.a: CMakeFiles/pipe.dir/pipe.cpp.o
libpipe.a: CMakeFiles/pipe.dir/build.make
libpipe.a: CMakeFiles/pipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpipe.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pipe.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipe.dir/build: libpipe.a
.PHONY : CMakeFiles/pipe.dir/build

CMakeFiles/pipe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipe.dir/clean

CMakeFiles/pipe.dir/depend:
	cd /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v3sl/Desktop/OS/OS-lab7-linux/pipe /home/v3sl/Desktop/OS/OS-lab7-linux/pipe /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build /home/v3sl/Desktop/OS/OS-lab7-linux/pipe/build/CMakeFiles/pipe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipe.dir/depend

