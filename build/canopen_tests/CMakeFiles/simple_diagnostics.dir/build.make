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
CMAKE_SOURCE_DIR = /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ub2004/ros2_ws/build/canopen_tests

# Utility rule file for simple_diagnostics.

# Include any custom commands dependencies for this target.
include CMakeFiles/simple_diagnostics.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_diagnostics.dir/progress.make

CMakeFiles/simple_diagnostics:

simple_diagnostics: CMakeFiles/simple_diagnostics
simple_diagnostics: CMakeFiles/simple_diagnostics.dir/build.make
	cd /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests/config/simple_diagnostics && cogen --input-file /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests/config/simple_diagnostics/bus.yml --output-file /home/ub2004/ros2_ws/build/canopen_tests/config/simple_diagnostics/preprocessed_bus.yml
	cd /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests/config/simple_diagnostics && sed 's|@BUS_CONFIG_PATH@|/home/ub2004/ros2_ws/install/canopen_tests/share/canopen_tests/config/simple_diagnostics|g' /home/ub2004/ros2_ws/build/canopen_tests/config/simple_diagnostics/preprocessed_bus.yml > /home/ub2004/ros2_ws/build/canopen_tests/config/simple_diagnostics/bus.yml
	cd /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests/config/simple_diagnostics && dcfgen -v -d /home/ub2004/ros2_ws/build/canopen_tests/config/simple_diagnostics/ -rS /home/ub2004/ros2_ws/build/canopen_tests/config/simple_diagnostics/bus.yml
.PHONY : simple_diagnostics

# Rule to build all files generated by this target.
CMakeFiles/simple_diagnostics.dir/build: simple_diagnostics
.PHONY : CMakeFiles/simple_diagnostics.dir/build

CMakeFiles/simple_diagnostics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_diagnostics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_diagnostics.dir/clean

CMakeFiles/simple_diagnostics.dir/depend:
	cd /home/ub2004/ros2_ws/build/canopen_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests /home/ub2004/ros2_ws/src/ros2_canopen/canopen_tests /home/ub2004/ros2_ws/build/canopen_tests /home/ub2004/ros2_ws/build/canopen_tests /home/ub2004/ros2_ws/build/canopen_tests/CMakeFiles/simple_diagnostics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_diagnostics.dir/depend

