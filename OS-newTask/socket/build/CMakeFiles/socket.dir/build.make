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
CMAKE_SOURCE_DIR = /home/v3sl/Desktop/OS-newTask/socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v3sl/Desktop/OS-newTask/socket/build

# Include any dependencies generated for this target.
include CMakeFiles/socket.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/socket.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/socket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/socket.dir/flags.make

CMakeFiles/socket.dir/socket.cpp.o: CMakeFiles/socket.dir/flags.make
CMakeFiles/socket.dir/socket.cpp.o: ../socket.cpp
CMakeFiles/socket.dir/socket.cpp.o: CMakeFiles/socket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/OS-newTask/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/socket.dir/socket.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/socket.dir/socket.cpp.o -MF CMakeFiles/socket.dir/socket.cpp.o.d -o CMakeFiles/socket.dir/socket.cpp.o -c /home/v3sl/Desktop/OS-newTask/socket/socket.cpp

CMakeFiles/socket.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/socket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/OS-newTask/socket/socket.cpp > CMakeFiles/socket.dir/socket.cpp.i

CMakeFiles/socket.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/socket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/OS-newTask/socket/socket.cpp -o CMakeFiles/socket.dir/socket.cpp.s

CMakeFiles/socket.dir/clientSocket.cpp.o: CMakeFiles/socket.dir/flags.make
CMakeFiles/socket.dir/clientSocket.cpp.o: ../clientSocket.cpp
CMakeFiles/socket.dir/clientSocket.cpp.o: CMakeFiles/socket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/OS-newTask/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/socket.dir/clientSocket.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/socket.dir/clientSocket.cpp.o -MF CMakeFiles/socket.dir/clientSocket.cpp.o.d -o CMakeFiles/socket.dir/clientSocket.cpp.o -c /home/v3sl/Desktop/OS-newTask/socket/clientSocket.cpp

CMakeFiles/socket.dir/clientSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/clientSocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/OS-newTask/socket/clientSocket.cpp > CMakeFiles/socket.dir/clientSocket.cpp.i

CMakeFiles/socket.dir/clientSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/clientSocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/OS-newTask/socket/clientSocket.cpp -o CMakeFiles/socket.dir/clientSocket.cpp.s

CMakeFiles/socket.dir/serverSocket.cpp.o: CMakeFiles/socket.dir/flags.make
CMakeFiles/socket.dir/serverSocket.cpp.o: ../serverSocket.cpp
CMakeFiles/socket.dir/serverSocket.cpp.o: CMakeFiles/socket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v3sl/Desktop/OS-newTask/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/socket.dir/serverSocket.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/socket.dir/serverSocket.cpp.o -MF CMakeFiles/socket.dir/serverSocket.cpp.o.d -o CMakeFiles/socket.dir/serverSocket.cpp.o -c /home/v3sl/Desktop/OS-newTask/socket/serverSocket.cpp

CMakeFiles/socket.dir/serverSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/serverSocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v3sl/Desktop/OS-newTask/socket/serverSocket.cpp > CMakeFiles/socket.dir/serverSocket.cpp.i

CMakeFiles/socket.dir/serverSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/serverSocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v3sl/Desktop/OS-newTask/socket/serverSocket.cpp -o CMakeFiles/socket.dir/serverSocket.cpp.s

# Object files for target socket
socket_OBJECTS = \
"CMakeFiles/socket.dir/socket.cpp.o" \
"CMakeFiles/socket.dir/clientSocket.cpp.o" \
"CMakeFiles/socket.dir/serverSocket.cpp.o"

# External object files for target socket
socket_EXTERNAL_OBJECTS =

libsocket.a: CMakeFiles/socket.dir/socket.cpp.o
libsocket.a: CMakeFiles/socket.dir/clientSocket.cpp.o
libsocket.a: CMakeFiles/socket.dir/serverSocket.cpp.o
libsocket.a: CMakeFiles/socket.dir/build.make
libsocket.a: CMakeFiles/socket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v3sl/Desktop/OS-newTask/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsocket.a"
	$(CMAKE_COMMAND) -P CMakeFiles/socket.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/socket.dir/build: libsocket.a
.PHONY : CMakeFiles/socket.dir/build

CMakeFiles/socket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/socket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/socket.dir/clean

CMakeFiles/socket.dir/depend:
	cd /home/v3sl/Desktop/OS-newTask/socket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v3sl/Desktop/OS-newTask/socket /home/v3sl/Desktop/OS-newTask/socket /home/v3sl/Desktop/OS-newTask/socket/build /home/v3sl/Desktop/OS-newTask/socket/build /home/v3sl/Desktop/OS-newTask/socket/build/CMakeFiles/socket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/socket.dir/depend

