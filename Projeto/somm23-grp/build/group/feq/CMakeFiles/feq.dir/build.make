# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/tomas/SO/Projeto/somm23-grp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomas/SO/Projeto/somm23-grp/build

# Include any dependencies generated for this target.
include group/feq/CMakeFiles/feq.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include group/feq/CMakeFiles/feq.dir/compiler_depend.make

# Include the progress variables for this target.
include group/feq/CMakeFiles/feq.dir/progress.make

# Include the compile flags for this target's objects.
include group/feq/CMakeFiles/feq.dir/flags.make

group/feq/CMakeFiles/feq.dir/feq_init.cpp.o: group/feq/CMakeFiles/feq.dir/flags.make
group/feq/CMakeFiles/feq.dir/feq_init.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_init.cpp
group/feq/CMakeFiles/feq.dir/feq_init.cpp.o: group/feq/CMakeFiles/feq.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object group/feq/CMakeFiles/feq.dir/feq_init.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT group/feq/CMakeFiles/feq.dir/feq_init.cpp.o -MF CMakeFiles/feq.dir/feq_init.cpp.o.d -o CMakeFiles/feq.dir/feq_init.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_init.cpp

group/feq/CMakeFiles/feq.dir/feq_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/feq.dir/feq_init.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_init.cpp > CMakeFiles/feq.dir/feq_init.cpp.i

group/feq/CMakeFiles/feq.dir/feq_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/feq.dir/feq_init.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_init.cpp -o CMakeFiles/feq.dir/feq_init.cpp.s

group/feq/CMakeFiles/feq.dir/feq_close.cpp.o: group/feq/CMakeFiles/feq.dir/flags.make
group/feq/CMakeFiles/feq.dir/feq_close.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_close.cpp
group/feq/CMakeFiles/feq.dir/feq_close.cpp.o: group/feq/CMakeFiles/feq.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object group/feq/CMakeFiles/feq.dir/feq_close.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT group/feq/CMakeFiles/feq.dir/feq_close.cpp.o -MF CMakeFiles/feq.dir/feq_close.cpp.o.d -o CMakeFiles/feq.dir/feq_close.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_close.cpp

group/feq/CMakeFiles/feq.dir/feq_close.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/feq.dir/feq_close.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_close.cpp > CMakeFiles/feq.dir/feq_close.cpp.i

group/feq/CMakeFiles/feq.dir/feq_close.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/feq.dir/feq_close.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_close.cpp -o CMakeFiles/feq.dir/feq_close.cpp.s

group/feq/CMakeFiles/feq.dir/feq_print.cpp.o: group/feq/CMakeFiles/feq.dir/flags.make
group/feq/CMakeFiles/feq.dir/feq_print.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_print.cpp
group/feq/CMakeFiles/feq.dir/feq_print.cpp.o: group/feq/CMakeFiles/feq.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object group/feq/CMakeFiles/feq.dir/feq_print.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT group/feq/CMakeFiles/feq.dir/feq_print.cpp.o -MF CMakeFiles/feq.dir/feq_print.cpp.o.d -o CMakeFiles/feq.dir/feq_print.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_print.cpp

group/feq/CMakeFiles/feq.dir/feq_print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/feq.dir/feq_print.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_print.cpp > CMakeFiles/feq.dir/feq_print.cpp.i

group/feq/CMakeFiles/feq.dir/feq_print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/feq.dir/feq_print.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_print.cpp -o CMakeFiles/feq.dir/feq_print.cpp.s

group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o: group/feq/CMakeFiles/feq.dir/flags.make
group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_insert.cpp
group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o: group/feq/CMakeFiles/feq.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o -MF CMakeFiles/feq.dir/feq_insert.cpp.o.d -o CMakeFiles/feq.dir/feq_insert.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_insert.cpp

group/feq/CMakeFiles/feq.dir/feq_insert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/feq.dir/feq_insert.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_insert.cpp > CMakeFiles/feq.dir/feq_insert.cpp.i

group/feq/CMakeFiles/feq.dir/feq_insert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/feq.dir/feq_insert.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_insert.cpp -o CMakeFiles/feq.dir/feq_insert.cpp.s

group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o: group/feq/CMakeFiles/feq.dir/flags.make
group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_pop.cpp
group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o: group/feq/CMakeFiles/feq.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o -MF CMakeFiles/feq.dir/feq_pop.cpp.o.d -o CMakeFiles/feq.dir/feq_pop.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_pop.cpp

group/feq/CMakeFiles/feq.dir/feq_pop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/feq.dir/feq_pop.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_pop.cpp > CMakeFiles/feq.dir/feq_pop.cpp.i

group/feq/CMakeFiles/feq.dir/feq_pop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/feq.dir/feq_pop.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/group/feq/feq_pop.cpp -o CMakeFiles/feq.dir/feq_pop.cpp.s

# Object files for target feq
feq_OBJECTS = \
"CMakeFiles/feq.dir/feq_init.cpp.o" \
"CMakeFiles/feq.dir/feq_close.cpp.o" \
"CMakeFiles/feq.dir/feq_print.cpp.o" \
"CMakeFiles/feq.dir/feq_insert.cpp.o" \
"CMakeFiles/feq.dir/feq_pop.cpp.o"

# External object files for target feq
feq_EXTERNAL_OBJECTS =

/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/feq_init.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/feq_close.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/feq_print.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/feq_insert.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/feq_pop.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/build.make
/home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a: group/feq/CMakeFiles/feq.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library /home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a"
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && $(CMAKE_COMMAND) -P CMakeFiles/feq.dir/cmake_clean_target.cmake
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feq.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
group/feq/CMakeFiles/feq.dir/build: /home/tomas/SO/Projeto/somm23-grp/lib/libfeq.a
.PHONY : group/feq/CMakeFiles/feq.dir/build

group/feq/CMakeFiles/feq.dir/clean:
	cd /home/tomas/SO/Projeto/somm23-grp/build/group/feq && $(CMAKE_COMMAND) -P CMakeFiles/feq.dir/cmake_clean.cmake
.PHONY : group/feq/CMakeFiles/feq.dir/clean

group/feq/CMakeFiles/feq.dir/depend:
	cd /home/tomas/SO/Projeto/somm23-grp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomas/SO/Projeto/somm23-grp/src /home/tomas/SO/Projeto/somm23-grp/src/group/feq /home/tomas/SO/Projeto/somm23-grp/build /home/tomas/SO/Projeto/somm23-grp/build/group/feq /home/tomas/SO/Projeto/somm23-grp/build/group/feq/CMakeFiles/feq.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : group/feq/CMakeFiles/feq.dir/depend
