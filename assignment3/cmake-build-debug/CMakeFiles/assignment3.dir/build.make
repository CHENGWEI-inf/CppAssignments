# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\cppWork\Assignments\assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\cppWork\Assignments\assignment3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\assignment3.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\assignment3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\assignment3.dir\flags.make

CMakeFiles\assignment3.dir\source\main.cpp.obj: CMakeFiles\assignment3.dir\flags.make
CMakeFiles\assignment3.dir\source\main.cpp.obj: ..\source\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment3.dir/source/main.cpp.obj"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment3.dir\source\main.cpp.obj /FdCMakeFiles\assignment3.dir\ /FS -c E:\cppWork\Assignments\assignment3\source\main.cpp
<<

CMakeFiles\assignment3.dir\source\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment3.dir/source/main.cpp.i"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" > CMakeFiles\assignment3.dir\source\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppWork\Assignments\assignment3\source\main.cpp
<<

CMakeFiles\assignment3.dir\source\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment3.dir/source/main.cpp.s"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment3.dir\source\main.cpp.s /c E:\cppWork\Assignments\assignment3\source\main.cpp
<<

CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.obj: CMakeFiles\assignment3.dir\flags.make
CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.obj: ..\source\plainDotProduct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment3.dir/source/plainDotProduct.cpp.obj"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment3.dir\source\plainDotProduct.cpp.obj /FdCMakeFiles\assignment3.dir\ /FS -c E:\cppWork\Assignments\assignment3\source\plainDotProduct.cpp
<<

CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment3.dir/source/plainDotProduct.cpp.i"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" > CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppWork\Assignments\assignment3\source\plainDotProduct.cpp
<<

CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment3.dir/source/plainDotProduct.cpp.s"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment3.dir\source\plainDotProduct.cpp.s /c E:\cppWork\Assignments\assignment3\source\plainDotProduct.cpp
<<

CMakeFiles\assignment3.dir\source\InputReader.cpp.obj: CMakeFiles\assignment3.dir\flags.make
CMakeFiles\assignment3.dir\source\InputReader.cpp.obj: ..\source\InputReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment3.dir/source/InputReader.cpp.obj"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment3.dir\source\InputReader.cpp.obj /FdCMakeFiles\assignment3.dir\ /FS -c E:\cppWork\Assignments\assignment3\source\InputReader.cpp
<<

CMakeFiles\assignment3.dir\source\InputReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment3.dir/source/InputReader.cpp.i"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" > CMakeFiles\assignment3.dir\source\InputReader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppWork\Assignments\assignment3\source\InputReader.cpp
<<

CMakeFiles\assignment3.dir\source\InputReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment3.dir/source/InputReader.cpp.s"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment3.dir\source\InputReader.cpp.s /c E:\cppWork\Assignments\assignment3\source\InputReader.cpp
<<

CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.obj: CMakeFiles\assignment3.dir\flags.make
CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.obj: ..\source\concurrentDotProduct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assignment3.dir/source/concurrentDotProduct.cpp.obj"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.obj /FdCMakeFiles\assignment3.dir\ /FS -c E:\cppWork\Assignments\assignment3\source\concurrentDotProduct.cpp
<<

CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment3.dir/source/concurrentDotProduct.cpp.i"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" > CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppWork\Assignments\assignment3\source\concurrentDotProduct.cpp
<<

CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment3.dir/source/concurrentDotProduct.cpp.s"
	"D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.s /c E:\cppWork\Assignments\assignment3\source\concurrentDotProduct.cpp
<<

# Object files for target assignment3
assignment3_OBJECTS = \
"CMakeFiles\assignment3.dir\source\main.cpp.obj" \
"CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.obj" \
"CMakeFiles\assignment3.dir\source\InputReader.cpp.obj" \
"CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.obj"

# External object files for target assignment3
assignment3_EXTERNAL_OBJECTS =

assignment3.exe: CMakeFiles\assignment3.dir\source\main.cpp.obj
assignment3.exe: CMakeFiles\assignment3.dir\source\plainDotProduct.cpp.obj
assignment3.exe: CMakeFiles\assignment3.dir\source\InputReader.cpp.obj
assignment3.exe: CMakeFiles\assignment3.dir\source\concurrentDotProduct.cpp.obj
assignment3.exe: CMakeFiles\assignment3.dir\build.make
assignment3.exe: CMakeFiles\assignment3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable assignment3.exe"
	"D:\Clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\assignment3.dir --rc="D:\Windows Kits\10\bin\10.0.17763.0\x64\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.17763.0\x64\mt.exe" --manifests  -- "D:\Visual Studio\VS_setup\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\link.exe" /nologo @CMakeFiles\assignment3.dir\objects1.rsp @<<
 /out:assignment3.exe /implib:assignment3.lib /pdb:E:\cppWork\Assignments\assignment3\cmake-build-debug\assignment3.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\assignment3.dir\build: assignment3.exe

.PHONY : CMakeFiles\assignment3.dir\build

CMakeFiles\assignment3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\assignment3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\assignment3.dir\clean

CMakeFiles\assignment3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\cppWork\Assignments\assignment3 E:\cppWork\Assignments\assignment3 E:\cppWork\Assignments\assignment3\cmake-build-debug E:\cppWork\Assignments\assignment3\cmake-build-debug E:\cppWork\Assignments\assignment3\cmake-build-debug\CMakeFiles\assignment3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\assignment3.dir\depend

