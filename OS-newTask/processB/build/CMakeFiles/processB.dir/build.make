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
CMAKE_SOURCE_DIR = /home/v3sl/Desktop/OS-newTask/processB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v3sl/Desktop/OS-newTask/processB/build

# Include any dependencies generated for this target.
include CMakeFiles/processB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/processB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/processB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processB.dir/flags.make

CMakeFiles/processB.dir/main.cpp.o: CMakeFiles/processB.dir/flags.make
CMakeFiles/processB.dir/main.cpp.o: ../main.cpp
CMakeFiles/processB.dir/main.cpp.o: CMakeFiles/processB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/OS-newTask/processB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/processB.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/processB.dir/main.cpp.o -MF CMakeFiles/processB.dir/main.cpp.o.d -o CMakeFiles/processB.dir/main.cpp.o -c /home/v3sl/Desktop/OS-newTask/processB/main.cpp

CMakeFiles/processB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processB.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/OS-newTask/processB/main.cpp > CMakeFiles/processB.dir/main.cpp.i

CMakeFiles/processB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processB.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/OS-newTask/processB/main.cpp -o CMakeFiles/processB.dir/main.cpp.s

# Object files for target processB
processB_OBJECTS = \
"CMakeFiles/processB.dir/main.cpp.o"

# External object files for target processB
processB_EXTERNAL_OBJECTS =

processB: CMakeFiles/processB.dir/main.cpp.o
processB: CMakeFiles/processB.dir/build.make
processB: ../../pipe/build/libpipe.a
processB: ../../messageQueue/build/libmessageQueue.a
processB: ../../sharedMemory/build/libsharedMemory.a
processB: ../../fileMapping/build/libfileMapping.a
processB: ../../socket/build/libsocket.a
processB: CMakeFiles/processB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v3sl/Desktop/OS-newTask/processB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable processB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processB.dir/build: processB
.PHONY : CMakeFiles/processB.dir/build

CMakeFiles/processB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/processB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/processB.dir/clean

CMakeFiles/processB.dir/depend:
	cd /home/v3sl/Desktop/OS-newTask/processB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v3sl/Desktop/OS-newTask/processB /home/v3sl/Desktop/OS-newTask/processB /home/v3sl/Desktop/OS-newTask/processB/build /home/v3sl/Desktop/OS-newTask/processB/build /home/v3sl/Desktop/OS-newTask/processB/build/CMakeFiles/processB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processB.dir/depend

