# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018

# Include any dependencies generated for this target.
include test/CMakeFiles/runAllTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/runAllTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runAllTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runAllTests.dir/flags.make

test/CMakeFiles/runAllTests.dir/TestBook.cpp.o: test/CMakeFiles/runAllTests.dir/flags.make
test/CMakeFiles/runAllTests.dir/TestBook.cpp.o: test/TestBook.cpp
test/CMakeFiles/runAllTests.dir/TestBook.cpp.o: test/CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runAllTests.dir/TestBook.cpp.o"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runAllTests.dir/TestBook.cpp.o -MF CMakeFiles/runAllTests.dir/TestBook.cpp.o.d -o CMakeFiles/runAllTests.dir/TestBook.cpp.o -c /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/TestBook.cpp

test/CMakeFiles/runAllTests.dir/TestBook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/TestBook.cpp.i"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/TestBook.cpp > CMakeFiles/runAllTests.dir/TestBook.cpp.i

test/CMakeFiles/runAllTests.dir/TestBook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/TestBook.cpp.s"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/TestBook.cpp -o CMakeFiles/runAllTests.dir/TestBook.cpp.s

test/CMakeFiles/runAllTests.dir/booktest.cpp.o: test/CMakeFiles/runAllTests.dir/flags.make
test/CMakeFiles/runAllTests.dir/booktest.cpp.o: test/booktest.cpp
test/CMakeFiles/runAllTests.dir/booktest.cpp.o: test/CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runAllTests.dir/booktest.cpp.o"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runAllTests.dir/booktest.cpp.o -MF CMakeFiles/runAllTests.dir/booktest.cpp.o.d -o CMakeFiles/runAllTests.dir/booktest.cpp.o -c /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/booktest.cpp

test/CMakeFiles/runAllTests.dir/booktest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/booktest.cpp.i"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/booktest.cpp > CMakeFiles/runAllTests.dir/booktest.cpp.i

test/CMakeFiles/runAllTests.dir/booktest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/booktest.cpp.s"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/booktest.cpp -o CMakeFiles/runAllTests.dir/booktest.cpp.s

test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o: test/CMakeFiles/runAllTests.dir/flags.make
test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o: test/catalogtest.cpp
test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o: test/CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o -MF CMakeFiles/runAllTests.dir/catalogtest.cpp.o.d -o CMakeFiles/runAllTests.dir/catalogtest.cpp.o -c /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/catalogtest.cpp

test/CMakeFiles/runAllTests.dir/catalogtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/catalogtest.cpp.i"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/catalogtest.cpp > CMakeFiles/runAllTests.dir/catalogtest.cpp.i

test/CMakeFiles/runAllTests.dir/catalogtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/catalogtest.cpp.s"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/catalogtest.cpp -o CMakeFiles/runAllTests.dir/catalogtest.cpp.s

# Object files for target runAllTests
runAllTests_OBJECTS = \
"CMakeFiles/runAllTests.dir/TestBook.cpp.o" \
"CMakeFiles/runAllTests.dir/booktest.cpp.o" \
"CMakeFiles/runAllTests.dir/catalogtest.cpp.o"

# External object files for target runAllTests
runAllTests_EXTERNAL_OBJECTS =

bin/runAllTests: test/CMakeFiles/runAllTests.dir/TestBook.cpp.o
bin/runAllTests: test/CMakeFiles/runAllTests.dir/booktest.cpp.o
bin/runAllTests: test/CMakeFiles/runAllTests.dir/catalogtest.cpp.o
bin/runAllTests: test/CMakeFiles/runAllTests.dir/build.make
bin/runAllTests: lib/libgmock.a
bin/runAllTests: lib/libgtest.a
bin/runAllTests: lib/libgtest_main.a
bin/runAllTests: src/libsimpleLibrary.a
bin/runAllTests: lib/libgtest.a
bin/runAllTests: /usr/lib64/libm.so
bin/runAllTests: test/CMakeFiles/runAllTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/runAllTests"
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runAllTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runAllTests.dir/build: bin/runAllTests
.PHONY : test/CMakeFiles/runAllTests.dir/build

test/CMakeFiles/runAllTests.dir/clean:
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test && $(CMAKE_COMMAND) -P CMakeFiles/runAllTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runAllTests.dir/clean

test/CMakeFiles/runAllTests.dir/depend:
	cd /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018 /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018 /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test /home/csmajs/rdave009/final-project-rdave009-xlai015-hliu246-aneva018/test/CMakeFiles/runAllTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runAllTests.dir/depend

