# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/quanghuy205/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quanghuy205/test/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/CoordMatrix.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/CoordMatrix.cpp.o: ../src/CoordMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/CoordMatrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/CoordMatrix.cpp.o -c /home/quanghuy205/test/src/CoordMatrix.cpp

CMakeFiles/main.dir/src/CoordMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/CoordMatrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/CoordMatrix.cpp > CMakeFiles/main.dir/src/CoordMatrix.cpp.i

CMakeFiles/main.dir/src/CoordMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/CoordMatrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/CoordMatrix.cpp -o CMakeFiles/main.dir/src/CoordMatrix.cpp.s

CMakeFiles/main.dir/src/CoordMatrix.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/CoordMatrix.cpp.o.requires

CMakeFiles/main.dir/src/CoordMatrix.cpp.o.provides: CMakeFiles/main.dir/src/CoordMatrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/CoordMatrix.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/CoordMatrix.cpp.o.provides

CMakeFiles/main.dir/src/CoordMatrix.cpp.o.provides.build: CMakeFiles/main.dir/src/CoordMatrix.cpp.o


CMakeFiles/main.dir/src/LKMatrix.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/LKMatrix.cpp.o: ../src/LKMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/LKMatrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/LKMatrix.cpp.o -c /home/quanghuy205/test/src/LKMatrix.cpp

CMakeFiles/main.dir/src/LKMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/LKMatrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/LKMatrix.cpp > CMakeFiles/main.dir/src/LKMatrix.cpp.i

CMakeFiles/main.dir/src/LKMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/LKMatrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/LKMatrix.cpp -o CMakeFiles/main.dir/src/LKMatrix.cpp.s

CMakeFiles/main.dir/src/LKMatrix.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/LKMatrix.cpp.o.requires

CMakeFiles/main.dir/src/LKMatrix.cpp.o.provides: CMakeFiles/main.dir/src/LKMatrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/LKMatrix.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/LKMatrix.cpp.o.provides

CMakeFiles/main.dir/src/LKMatrix.cpp.o.provides.build: CMakeFiles/main.dir/src/LKMatrix.cpp.o


CMakeFiles/main.dir/src/LPT.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/LPT.cpp.o: ../src/LPT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/LPT.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/LPT.cpp.o -c /home/quanghuy205/test/src/LPT.cpp

CMakeFiles/main.dir/src/LPT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/LPT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/LPT.cpp > CMakeFiles/main.dir/src/LPT.cpp.i

CMakeFiles/main.dir/src/LPT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/LPT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/LPT.cpp -o CMakeFiles/main.dir/src/LPT.cpp.s

CMakeFiles/main.dir/src/LPT.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/LPT.cpp.o.requires

CMakeFiles/main.dir/src/LPT.cpp.o.provides: CMakeFiles/main.dir/src/LPT.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/LPT.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/LPT.cpp.o.provides

CMakeFiles/main.dir/src/LPT.cpp.o.provides.build: CMakeFiles/main.dir/src/LPT.cpp.o


CMakeFiles/main.dir/src/Label.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Label.cpp.o: ../src/Label.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/Label.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Label.cpp.o -c /home/quanghuy205/test/src/Label.cpp

CMakeFiles/main.dir/src/Label.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Label.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/Label.cpp > CMakeFiles/main.dir/src/Label.cpp.i

CMakeFiles/main.dir/src/Label.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Label.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/Label.cpp -o CMakeFiles/main.dir/src/Label.cpp.s

CMakeFiles/main.dir/src/Label.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/Label.cpp.o.requires

CMakeFiles/main.dir/src/Label.cpp.o.provides: CMakeFiles/main.dir/src/Label.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Label.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/Label.cpp.o.provides

CMakeFiles/main.dir/src/Label.cpp.o.provides.build: CMakeFiles/main.dir/src/Label.cpp.o


CMakeFiles/main.dir/src/Solution.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Solution.cpp.o: ../src/Solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/Solution.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Solution.cpp.o -c /home/quanghuy205/test/src/Solution.cpp

CMakeFiles/main.dir/src/Solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Solution.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/Solution.cpp > CMakeFiles/main.dir/src/Solution.cpp.i

CMakeFiles/main.dir/src/Solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Solution.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/Solution.cpp -o CMakeFiles/main.dir/src/Solution.cpp.s

CMakeFiles/main.dir/src/Solution.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/Solution.cpp.o.requires

CMakeFiles/main.dir/src/Solution.cpp.o.provides: CMakeFiles/main.dir/src/Solution.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Solution.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/Solution.cpp.o.provides

CMakeFiles/main.dir/src/Solution.cpp.o.provides.build: CMakeFiles/main.dir/src/Solution.cpp.o


CMakeFiles/main.dir/src/TSPalgorithm.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/TSPalgorithm.cpp.o: ../src/TSPalgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/TSPalgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/TSPalgorithm.cpp.o -c /home/quanghuy205/test/src/TSPalgorithm.cpp

CMakeFiles/main.dir/src/TSPalgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/TSPalgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/TSPalgorithm.cpp > CMakeFiles/main.dir/src/TSPalgorithm.cpp.i

CMakeFiles/main.dir/src/TSPalgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/TSPalgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/TSPalgorithm.cpp -o CMakeFiles/main.dir/src/TSPalgorithm.cpp.s

CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.requires

CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.provides: CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.provides

CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.provides.build: CMakeFiles/main.dir/src/TSPalgorithm.cpp.o


CMakeFiles/main.dir/src/list_customers.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/list_customers.cpp.o: ../src/list_customers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/list_customers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/list_customers.cpp.o -c /home/quanghuy205/test/src/list_customers.cpp

CMakeFiles/main.dir/src/list_customers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/list_customers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/list_customers.cpp > CMakeFiles/main.dir/src/list_customers.cpp.i

CMakeFiles/main.dir/src/list_customers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/list_customers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/list_customers.cpp -o CMakeFiles/main.dir/src/list_customers.cpp.s

CMakeFiles/main.dir/src/list_customers.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/list_customers.cpp.o.requires

CMakeFiles/main.dir/src/list_customers.cpp.o.provides: CMakeFiles/main.dir/src/list_customers.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/list_customers.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/list_customers.cpp.o.provides

CMakeFiles/main.dir/src/list_customers.cpp.o.provides.build: CMakeFiles/main.dir/src/list_customers.cpp.o


CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/quanghuy205/test/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/main.cpp.o.requires

CMakeFiles/main.dir/src/main.cpp.o.provides: CMakeFiles/main.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/main.cpp.o.provides

CMakeFiles/main.dir/src/main.cpp.o.provides.build: CMakeFiles/main.dir/src/main.cpp.o


CMakeFiles/main.dir/src/split.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/split.cpp.o: ../src/split.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/src/split.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/split.cpp.o -c /home/quanghuy205/test/src/split.cpp

CMakeFiles/main.dir/src/split.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/split.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quanghuy205/test/src/split.cpp > CMakeFiles/main.dir/src/split.cpp.i

CMakeFiles/main.dir/src/split.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/split.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quanghuy205/test/src/split.cpp -o CMakeFiles/main.dir/src/split.cpp.s

CMakeFiles/main.dir/src/split.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/split.cpp.o.requires

CMakeFiles/main.dir/src/split.cpp.o.provides: CMakeFiles/main.dir/src/split.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/split.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/split.cpp.o.provides

CMakeFiles/main.dir/src/split.cpp.o.provides.build: CMakeFiles/main.dir/src/split.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/CoordMatrix.cpp.o" \
"CMakeFiles/main.dir/src/LKMatrix.cpp.o" \
"CMakeFiles/main.dir/src/LPT.cpp.o" \
"CMakeFiles/main.dir/src/Label.cpp.o" \
"CMakeFiles/main.dir/src/Solution.cpp.o" \
"CMakeFiles/main.dir/src/TSPalgorithm.cpp.o" \
"CMakeFiles/main.dir/src/list_customers.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/split.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/CoordMatrix.cpp.o
main: CMakeFiles/main.dir/src/LKMatrix.cpp.o
main: CMakeFiles/main.dir/src/LPT.cpp.o
main: CMakeFiles/main.dir/src/Label.cpp.o
main: CMakeFiles/main.dir/src/Solution.cpp.o
main: CMakeFiles/main.dir/src/TSPalgorithm.cpp.o
main: CMakeFiles/main.dir/src/list_customers.cpp.o
main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/split.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quanghuy205/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/CoordMatrix.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/LKMatrix.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/LPT.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/Label.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/Solution.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/TSPalgorithm.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/list_customers.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/split.cpp.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/quanghuy205/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quanghuy205/test /home/quanghuy205/test /home/quanghuy205/test/build /home/quanghuy205/test/build /home/quanghuy205/test/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

