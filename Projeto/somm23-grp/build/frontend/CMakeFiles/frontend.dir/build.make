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
include frontend/CMakeFiles/frontend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include frontend/CMakeFiles/frontend.dir/compiler_depend.make

# Include the progress variables for this target.
include frontend/CMakeFiles/frontend.dir/progress.make

# Include the compile flags for this target's objects.
include frontend/CMakeFiles/frontend.dir/flags.make

frontend/CMakeFiles/frontend.dir/sim.cpp.o: frontend/CMakeFiles/frontend.dir/flags.make
frontend/CMakeFiles/frontend.dir/sim.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/frontend/sim.cpp
frontend/CMakeFiles/frontend.dir/sim.cpp.o: frontend/CMakeFiles/frontend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object frontend/CMakeFiles/frontend.dir/sim.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT frontend/CMakeFiles/frontend.dir/sim.cpp.o -MF CMakeFiles/frontend.dir/sim.cpp.o.d -o CMakeFiles/frontend.dir/sim.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/frontend/sim.cpp

frontend/CMakeFiles/frontend.dir/sim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/frontend.dir/sim.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/frontend/sim.cpp > CMakeFiles/frontend.dir/sim.cpp.i

frontend/CMakeFiles/frontend.dir/sim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/frontend.dir/sim.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/frontend/sim.cpp -o CMakeFiles/frontend.dir/sim.cpp.s

frontend/CMakeFiles/frontend.dir/pct.cpp.o: frontend/CMakeFiles/frontend.dir/flags.make
frontend/CMakeFiles/frontend.dir/pct.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/frontend/pct.cpp
frontend/CMakeFiles/frontend.dir/pct.cpp.o: frontend/CMakeFiles/frontend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object frontend/CMakeFiles/frontend.dir/pct.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT frontend/CMakeFiles/frontend.dir/pct.cpp.o -MF CMakeFiles/frontend.dir/pct.cpp.o.d -o CMakeFiles/frontend.dir/pct.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/frontend/pct.cpp

frontend/CMakeFiles/frontend.dir/pct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/frontend.dir/pct.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/frontend/pct.cpp > CMakeFiles/frontend.dir/pct.cpp.i

frontend/CMakeFiles/frontend.dir/pct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/frontend.dir/pct.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/frontend/pct.cpp -o CMakeFiles/frontend.dir/pct.cpp.s

frontend/CMakeFiles/frontend.dir/feq.cpp.o: frontend/CMakeFiles/frontend.dir/flags.make
frontend/CMakeFiles/frontend.dir/feq.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/frontend/feq.cpp
frontend/CMakeFiles/frontend.dir/feq.cpp.o: frontend/CMakeFiles/frontend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object frontend/CMakeFiles/frontend.dir/feq.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT frontend/CMakeFiles/frontend.dir/feq.cpp.o -MF CMakeFiles/frontend.dir/feq.cpp.o.d -o CMakeFiles/frontend.dir/feq.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/frontend/feq.cpp

frontend/CMakeFiles/frontend.dir/feq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/frontend.dir/feq.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/frontend/feq.cpp > CMakeFiles/frontend.dir/feq.cpp.i

frontend/CMakeFiles/frontend.dir/feq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/frontend.dir/feq.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/frontend/feq.cpp -o CMakeFiles/frontend.dir/feq.cpp.s

frontend/CMakeFiles/frontend.dir/mem.cpp.o: frontend/CMakeFiles/frontend.dir/flags.make
frontend/CMakeFiles/frontend.dir/mem.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/frontend/mem.cpp
frontend/CMakeFiles/frontend.dir/mem.cpp.o: frontend/CMakeFiles/frontend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object frontend/CMakeFiles/frontend.dir/mem.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT frontend/CMakeFiles/frontend.dir/mem.cpp.o -MF CMakeFiles/frontend.dir/mem.cpp.o.d -o CMakeFiles/frontend.dir/mem.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/frontend/mem.cpp

frontend/CMakeFiles/frontend.dir/mem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/frontend.dir/mem.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/frontend/mem.cpp > CMakeFiles/frontend.dir/mem.cpp.i

frontend/CMakeFiles/frontend.dir/mem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/frontend.dir/mem.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/frontend/mem.cpp -o CMakeFiles/frontend.dir/mem.cpp.s

frontend/CMakeFiles/frontend.dir/swp.cpp.o: frontend/CMakeFiles/frontend.dir/flags.make
frontend/CMakeFiles/frontend.dir/swp.cpp.o: /home/tomas/SO/Projeto/somm23-grp/src/frontend/swp.cpp
frontend/CMakeFiles/frontend.dir/swp.cpp.o: frontend/CMakeFiles/frontend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object frontend/CMakeFiles/frontend.dir/swp.cpp.o"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT frontend/CMakeFiles/frontend.dir/swp.cpp.o -MF CMakeFiles/frontend.dir/swp.cpp.o.d -o CMakeFiles/frontend.dir/swp.cpp.o -c /home/tomas/SO/Projeto/somm23-grp/src/frontend/swp.cpp

frontend/CMakeFiles/frontend.dir/swp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/frontend.dir/swp.cpp.i"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomas/SO/Projeto/somm23-grp/src/frontend/swp.cpp > CMakeFiles/frontend.dir/swp.cpp.i

frontend/CMakeFiles/frontend.dir/swp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/frontend.dir/swp.cpp.s"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomas/SO/Projeto/somm23-grp/src/frontend/swp.cpp -o CMakeFiles/frontend.dir/swp.cpp.s

# Object files for target frontend
frontend_OBJECTS = \
"CMakeFiles/frontend.dir/sim.cpp.o" \
"CMakeFiles/frontend.dir/pct.cpp.o" \
"CMakeFiles/frontend.dir/feq.cpp.o" \
"CMakeFiles/frontend.dir/mem.cpp.o" \
"CMakeFiles/frontend.dir/swp.cpp.o"

# External object files for target frontend
frontend_EXTERNAL_OBJECTS =

/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/sim.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/pct.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/feq.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/mem.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/swp.cpp.o
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/build.make
/home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a: frontend/CMakeFiles/frontend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tomas/SO/Projeto/somm23-grp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library /home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a"
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && $(CMAKE_COMMAND) -P CMakeFiles/frontend.dir/cmake_clean_target.cmake
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/frontend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
frontend/CMakeFiles/frontend.dir/build: /home/tomas/SO/Projeto/somm23-grp/lib/libfrontend.a
.PHONY : frontend/CMakeFiles/frontend.dir/build

frontend/CMakeFiles/frontend.dir/clean:
	cd /home/tomas/SO/Projeto/somm23-grp/build/frontend && $(CMAKE_COMMAND) -P CMakeFiles/frontend.dir/cmake_clean.cmake
.PHONY : frontend/CMakeFiles/frontend.dir/clean

frontend/CMakeFiles/frontend.dir/depend:
	cd /home/tomas/SO/Projeto/somm23-grp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomas/SO/Projeto/somm23-grp/src /home/tomas/SO/Projeto/somm23-grp/src/frontend /home/tomas/SO/Projeto/somm23-grp/build /home/tomas/SO/Projeto/somm23-grp/build/frontend /home/tomas/SO/Projeto/somm23-grp/build/frontend/CMakeFiles/frontend.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : frontend/CMakeFiles/frontend.dir/depend

