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
CMAKE_SOURCE_DIR = /home/tomas/SO/Projeto/somm23-so5g3_test/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomas/SO/Projeto/somm23-so5g3_test/build

# Include any dependencies generated for this target.
include core/sup/CMakeFiles/sup.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/sup/CMakeFiles/sup.dir/compiler_depend.make

# Include the progress variables for this target.
include core/sup/CMakeFiles/sup.dir/progress.make

# Include the compile flags for this target's objects.
include core/sup/CMakeFiles/sup.dir/flags.make

core/sup/CMakeFiles/sup.dir/exception.cpp.o: core/sup/CMakeFiles/sup.dir/flags.make
core/sup/CMakeFiles/sup.dir/exception.cpp.o: /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/exception.cpp
core/sup/CMakeFiles/sup.dir/exception.cpp.o: core/sup/CMakeFiles/sup.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-so5g3_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/sup/CMakeFiles/sup.dir/exception.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/sup/CMakeFiles/sup.dir/exception.cpp.o -MF CMakeFiles/sup.dir/exception.cpp.o.d -o CMakeFiles/sup.dir/exception.cpp.o -c /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/exception.cpp

core/sup/CMakeFiles/sup.dir/exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sup.dir/exception.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/exception.cpp > CMakeFiles/sup.dir/exception.cpp.i

core/sup/CMakeFiles/sup.dir/exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sup.dir/exception.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/exception.cpp -o CMakeFiles/sup.dir/exception.cpp.s

core/sup/CMakeFiles/sup.dir/probing.cpp.o: core/sup/CMakeFiles/sup.dir/flags.make
core/sup/CMakeFiles/sup.dir/probing.cpp.o: /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/probing.cpp
core/sup/CMakeFiles/sup.dir/probing.cpp.o: core/sup/CMakeFiles/sup.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-so5g3_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/sup/CMakeFiles/sup.dir/probing.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/sup/CMakeFiles/sup.dir/probing.cpp.o -MF CMakeFiles/sup.dir/probing.cpp.o.d -o CMakeFiles/sup.dir/probing.cpp.o -c /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/probing.cpp

core/sup/CMakeFiles/sup.dir/probing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sup.dir/probing.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/probing.cpp > CMakeFiles/sup.dir/probing.cpp.i

core/sup/CMakeFiles/sup.dir/probing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sup.dir/probing.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/probing.cpp -o CMakeFiles/sup.dir/probing.cpp.s

core/sup/CMakeFiles/sup.dir/binselection.cpp.o: core/sup/CMakeFiles/sup.dir/flags.make
core/sup/CMakeFiles/sup.dir/binselection.cpp.o: /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/binselection.cpp
core/sup/CMakeFiles/sup.dir/binselection.cpp.o: core/sup/CMakeFiles/sup.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-so5g3_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object core/sup/CMakeFiles/sup.dir/binselection.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/sup/CMakeFiles/sup.dir/binselection.cpp.o -MF CMakeFiles/sup.dir/binselection.cpp.o.d -o CMakeFiles/sup.dir/binselection.cpp.o -c /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/binselection.cpp

core/sup/CMakeFiles/sup.dir/binselection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sup.dir/binselection.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/binselection.cpp > CMakeFiles/sup.dir/binselection.cpp.i

core/sup/CMakeFiles/sup.dir/binselection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sup.dir/binselection.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup/binselection.cpp -o CMakeFiles/sup.dir/binselection.cpp.s

# Object files for target sup
sup_OBJECTS = \
"CMakeFiles/sup.dir/exception.cpp.o" \
"CMakeFiles/sup.dir/probing.cpp.o" \
"CMakeFiles/sup.dir/binselection.cpp.o"

# External object files for target sup
sup_EXTERNAL_OBJECTS =

/home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a: core/sup/CMakeFiles/sup.dir/exception.cpp.o
/home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a: core/sup/CMakeFiles/sup.dir/probing.cpp.o
/home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a: core/sup/CMakeFiles/sup.dir/binselection.cpp.o
/home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a: core/sup/CMakeFiles/sup.dir/build.make
/home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a: core/sup/CMakeFiles/sup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tomas/SO/Projeto/somm23-so5g3_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a"
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && $(CMAKE_COMMAND) -P CMakeFiles/sup.dir/cmake_clean_target.cmake
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/sup/CMakeFiles/sup.dir/build: /home/tomas/SO/Projeto/somm23-so5g3_test/lib/libsup.a
.PHONY : core/sup/CMakeFiles/sup.dir/build

core/sup/CMakeFiles/sup.dir/clean:
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup && $(CMAKE_COMMAND) -P CMakeFiles/sup.dir/cmake_clean.cmake
.PHONY : core/sup/CMakeFiles/sup.dir/clean

core/sup/CMakeFiles/sup.dir/depend:
	cd /home/tomas/SO/Projeto/somm23-so5g3_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomas/SO/Projeto/somm23-so5g3_test/src /home/tomas/SO/Projeto/somm23-so5g3_test/src/core/sup /home/tomas/SO/Projeto/somm23-so5g3_test/build /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup /home/tomas/SO/Projeto/somm23-so5g3_test/build/core/sup/CMakeFiles/sup.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : core/sup/CMakeFiles/sup.dir/depend
