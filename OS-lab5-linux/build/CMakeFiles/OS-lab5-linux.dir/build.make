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
CMAKE_SOURCE_DIR = /home/v3sl/Desktop/Os/OS-lab5-linux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v3sl/Desktop/Os/OS-lab5-linux/build

# Include any dependencies generated for this target.
include CMakeFiles/OS-lab5-linux.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OS-lab5-linux.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OS-lab5-linux.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OS-lab5-linux.dir/flags.make

CMakeFiles/OS-lab5-linux.dir/main.cpp.o: CMakeFiles/OS-lab5-linux.dir/flags.make
CMakeFiles/OS-lab5-linux.dir/main.cpp.o: ../main.cpp
CMakeFiles/OS-lab5-linux.dir/main.cpp.o: CMakeFiles/OS-lab5-linux.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/Os/OS-lab5-linux/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OS-lab5-linux.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OS-lab5-linux.dir/main.cpp.o -MF CMakeFiles/OS-lab5-linux.dir/main.cpp.o.d -o CMakeFiles/OS-lab5-linux.dir/main.cpp.o -c /home/v3sl/Desktop/Os/OS-lab5-linux/main.cpp

CMakeFiles/OS-lab5-linux.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS-lab5-linux.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/Os/OS-lab5-linux/main.cpp > CMakeFiles/OS-lab5-linux.dir/main.cpp.i

CMakeFiles/OS-lab5-linux.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS-lab5-linux.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/Os/OS-lab5-linux/main.cpp -o CMakeFiles/OS-lab5-linux.dir/main.cpp.s

# Object files for target OS-lab5-linux
OS__lab5__linux_OBJECTS = \
"CMakeFiles/OS-lab5-linux.dir/main.cpp.o"

# External object files for target OS-lab5-linux
OS__lab5__linux_EXTERNAL_OBJECTS =

OS-lab5-linux: CMakeFiles/OS-lab5-linux.dir/main.cpp.o
OS-lab5-linux: CMakeFiles/OS-lab5-linux.dir/build.make
OS-lab5-linux: CMakeFiles/OS-lab5-linux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v3sl/Desktop/Os/OS-lab5-linux/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OS-lab5-linux"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OS-lab5-linux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OS-lab5-linux.dir/build: OS-lab5-linux
.PHONY : CMakeFiles/OS-lab5-linux.dir/build

CMakeFiles/OS-lab5-linux.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OS-lab5-linux.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OS-lab5-linux.dir/clean

CMakeFiles/OS-lab5-linux.dir/depend:
	cd /home/v3sl/Desktop/Os/OS-lab5-linux/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v3sl/Desktop/Os/OS-lab5-linux /home/v3sl/Desktop/Os/OS-lab5-linux /home/v3sl/Desktop/Os/OS-lab5-linux/build /home/v3sl/Desktop/Os/OS-lab5-linux/build /home/v3sl/Desktop/Os/OS-lab5-linux/build/CMakeFiles/OS-lab5-linux.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OS-lab5-linux.dir/depend
