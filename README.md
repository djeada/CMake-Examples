# CMake
Examples of projects with CMake.

<h1>Introduction</h1>

CMake is:
* cross-platform
* free 
* open-source
* compiler-independent

<h2>Compilation with gcc</h2>

When your project contains just three files (main.c code.c code.h), you can easily compile it from the terminal using following commands:

```bash
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o exe code.c main.c
```

You have now an executable that you can run, called <i>exe</i>.

<h2>Using Makefiles for compilation</h2>

When dealing with a large number of files, using command line commands for compilation becomes almost impossible.
Instead, you can use configuration files to define which files to compile and with which flags.

Example of Makefile for our project with three files (main.c code.c code.h):

```make
CC=gcc
CFLAGS=-I.
DEPS = code.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

project: main.o code.o 
	$(CC) -o exe main.o code.o 
```

You can use the following commands to run it:

```bash
make
```

<h2>Using CMake for compilation</h2>

Build systems like <i>Make</i> are usualy platform specific.
You can, however, use a platform-independent meta build system such as CMake.

Example of CMakeList.txt for our project with three files (main.c code.c code.h):

```CMake
cmake_minimum_required(VERSION 3.15.0)

project(ExampleProject VERSION 1.0.0)

add_library(code
code.c)

add_executable(executable
main.c)

target_link_libraries(executable code)
```

You can use the following commands to run it:

```bash
mkdir build
cd build
cmake..
cmake --build .
```

<h2>Make vs CMake</h2>

Make is a build system.
CMake is a build system generator.
CMake can create Makefiles, but it also works for Ninja, KDEvelop, and Xcode projects, as well as Visual Studio solutions.

Make will build your project, i.e. it will produce an executable (assuming no errors occur in the process). CMake on the other hand will produce the configuration files for Make or other tool.

<h1>CMake language</h1>

<h2>Variables</h2>

```CMake
set(TEXT "Hello World!")
set(NUMBER 10)

message("Your text: ${TEXT} Your number: ${NUMBER}")
```

<h2>Lists</h2>

Indexed like in every other language: 0...n-1

Negative indexes are counted from the end.

```CMake
set(LIST xx yy zz)
set(LIST2 1 2 3)

message("First list: ${LIST} Second list: ${LIST2}")

list(REMOVE_AT LIST 2)
list(REMOVE_ITEM LIST xx)
list(INSERT LIST 1 gg)
list(APPEND LIST dd)
list(REVERSE LIST)
list(REMOVE_DUPLICATES LIST)
list(SORT LIST)

message("First list: ${LIST} Second list: ${LIST2}")
```

<h2>Strings</h2>

```CMake
set(TEXT "Python boss.")

message("Text: ${TEXT}")

string(APPEND TEXT " and not cpp.")
string(REPLACE "Python" "C" NEW_TEXT ${TEXT} )
string(TOLOWER ${TEXT} NEW_TEXT)
string(TOUPPER ${TEXT} NEW_TEXT)
string(COMPARE EQUAL ${NEW_TEXT} "XXX"  flag)
string(COMPARE GREATER ${NEW_TEXT} ${TEXT}  flag)

message("Text: ${TEXT}")
```

<h2>Conditionals</h2>

```CMake
set(FLAG ON)

if(${FLAG})
	message("You can see this message.")
else()
	message("You will never see that message.")
endif()
```

<h2>Loops</h2>

```CMake
 foreach(LETTER a b c)
 	message(${LETTER})
```

<h2>Functions</h2>

```CMake
function(display NAME)
	message("Provided parameter: ${${NAME}}")

	message("ARGC=	${ARGC}")
	message("ARGV=	${ARGV}")
	message("ARGN=	${ARGN}")
	
	if(DEFINED ARGV0)
		message("ARGV0:	${ARGV0}")
	endif()
	
	if(DEFINED ARGV1)
		message("ARGV1:	${ARGV1}")
	endif()
	
	if(DEFINED ARGV2)
		message("ARGV2:	${ARGV2}")
	endif()
endfunction()
```


<h1>Requirements</h1>
 
To run our examples, you will need the following:

* CMake v3.15+
* gcc
* make

<h1>Table of contents</h1>

  - [An executable and libraries](https://github.com/djeada/CMake/tree/main/src/ExecutableAndLibraries). A simple example with three .cpp files and two .h files, all in the same folder.
  - [Subdirectories](https://github.com/djeada/CMake/tree/main/src/Subdirectories). The project is divided into subdirectories, each with its own CMakeList.txt file.
  - [Exporting and using packages](https://github.com/djeada/CMake/tree/main/src/ExportingAndUsingPackages). Export the library as a package and include it in an entirely unrelated project.
  - [OpenCV](https://github.com/djeada/CMake/tree/main/src/OpenCV). Create a program that reads an image, writes text to it, and saves it using the OpenCV library.
  - Doxygen with CMake.
  - GTest with CMake.
  - Python with CMake.
