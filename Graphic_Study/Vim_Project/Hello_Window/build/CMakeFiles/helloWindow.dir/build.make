# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build

# Include any dependencies generated for this target.
include CMakeFiles/helloWindow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/helloWindow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloWindow.dir/flags.make

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o: CMakeFiles/helloWindow.dir/flags.make
CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o: ../src/Hello_Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o -c /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/Hello_Window.cpp

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/Hello_Window.cpp > CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.i

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/Hello_Window.cpp -o CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.s

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.requires:

.PHONY : CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.requires

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.provides: CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloWindow.dir/build.make CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.provides.build
.PHONY : CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.provides

CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.provides.build: CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o


CMakeFiles/helloWindow.dir/src/glad.c.o: CMakeFiles/helloWindow.dir/flags.make
CMakeFiles/helloWindow.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/helloWindow.dir/src/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/helloWindow.dir/src/glad.c.o   -c /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/glad.c

CMakeFiles/helloWindow.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/helloWindow.dir/src/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/glad.c > CMakeFiles/helloWindow.dir/src/glad.c.i

CMakeFiles/helloWindow.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/helloWindow.dir/src/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/src/glad.c -o CMakeFiles/helloWindow.dir/src/glad.c.s

CMakeFiles/helloWindow.dir/src/glad.c.o.requires:

.PHONY : CMakeFiles/helloWindow.dir/src/glad.c.o.requires

CMakeFiles/helloWindow.dir/src/glad.c.o.provides: CMakeFiles/helloWindow.dir/src/glad.c.o.requires
	$(MAKE) -f CMakeFiles/helloWindow.dir/build.make CMakeFiles/helloWindow.dir/src/glad.c.o.provides.build
.PHONY : CMakeFiles/helloWindow.dir/src/glad.c.o.provides

CMakeFiles/helloWindow.dir/src/glad.c.o.provides.build: CMakeFiles/helloWindow.dir/src/glad.c.o


# Object files for target helloWindow
helloWindow_OBJECTS = \
"CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o" \
"CMakeFiles/helloWindow.dir/src/glad.c.o"

# External object files for target helloWindow
helloWindow_EXTERNAL_OBJECTS =

helloWindow: CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o
helloWindow: CMakeFiles/helloWindow.dir/src/glad.c.o
helloWindow: CMakeFiles/helloWindow.dir/build.make
helloWindow: CMakeFiles/helloWindow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable helloWindow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloWindow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloWindow.dir/build: helloWindow

.PHONY : CMakeFiles/helloWindow.dir/build

CMakeFiles/helloWindow.dir/requires: CMakeFiles/helloWindow.dir/src/Hello_Window.cpp.o.requires
CMakeFiles/helloWindow.dir/requires: CMakeFiles/helloWindow.dir/src/glad.c.o.requires

.PHONY : CMakeFiles/helloWindow.dir/requires

CMakeFiles/helloWindow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloWindow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloWindow.dir/clean

CMakeFiles/helloWindow.dir/depend:
	cd /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build /home/studentq/CPP_Study/Graphic_Study/Vim_Project/Hello_Window/build/CMakeFiles/helloWindow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloWindow.dir/depend

