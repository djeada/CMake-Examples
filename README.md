# CMake
Examples of projects with CMake.

## Introduction

CMake is:
* cross-platform
* free 
* open-source
* compiler-independent

### Compilation with gcc

When your project contains just three files (main.c code.c code.h), you can easily compile it from the terminal using the following commands:

```bash
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o exe code.c main.c
```

You have now an executable that you can run, called <i>exe</i>.

### Using Makefiles for compilation

When dealing with a large number of files, using command line commands for compilation becomes almost impossible.
Instead, you can use configuration files to define which files to compile and with which flags.

An example of Makefile for our project with three files (main.c code.c code.h):

```make
CC=gcc
CFLAGS=-I.
DEPS = code.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

project: main.o code.o 
	$(CC) -o exe main.o code.o 
```

Use the following command to execute it:

```bash
make
```

*  Make maintains a record of the modifications made to the source files.
As a result, everytime you execute it, it will only recompile the files that have changed. 
* Invented at Bell Labs in 1975. It is still one of the most extensively used build managers
* It has it's own programming language.
* Many other tools know how to work with it.

### Using CMake for compilation

Build systems like <i>Make</i> are usualy platform specific.
You can, however, use a platform-independent meta build system such as CMake.

An example of CMakeList.txt for our project with three files (main.c code.c code.h):

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

### Make vs CMake

Make is a build system. CMake is a build system generator. CMake can create Makefiles, but it also works for Ninja, KDEvelop, and Xcode projects, as well as Visual Studio solutions.

Make will build your project, i.e. it will produce an executable (assuming no errors occur in the process). CMake, on the other hand, will produce the configuration files for Make or other tool.

### CMake Workflow

1. Edit files in the source tree.
1. Run cmake to generate or configure native build system files.
1. Open project files from the build tree and use the native build tools.

## CMake language

* All values are strings.
* Commands are case insensitive.
* Arguments passed to the commands are case sensitive and space separated.
* Quoted argument is treated as one value.

### Variables

* Variable names are case sensitive.
* You can use alpha-numerics and underscores.
* You should always initialize a variable with a value.

```CMake
set(TEXT "Hello World!")
set(NUMBER 10)

message("Your text: ${TEXT} Your number: ${NUMBER}")
```

### Lists

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

### Strings

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

### Conditionals

```CMake
set(FLAG ON)

if(${FLAG})
	message("You can see this message.")
else()
	message("You will never see that message.")
endif()
```

### Loops

```CMake
 foreach(LETTER a b c)
 	message(${LETTER})
```

### Functions

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


## Requirements
 
To run our examples, you will need the following:

* CMake v3.15+
* gcc
* make

## Table of contents

  - [An executable and libraries](https://github.com/djeada/CMake/tree/main/src/ExecutableAndLibraries). A simple example with three .cpp files and two .h files, all in the same directory.
  - [Subdirectories](https://github.com/djeada/CMake/tree/main/src/Subdirectories). The project is divided into subdirectories, each with its own CMakeList.txt file.
  - [Exporting and using packages](https://github.com/djeada/CMake/tree/main/src/ExportingAndUsingPackages). Export the library as a package and include it in an entirely unrelated project.
  - [OpenCV](https://github.com/djeada/CMake/tree/main/src/OpenCV). Create a program that reads an image, writes text to it, and saves it using the OpenCV library.
  - [MPI](https://github.com/djeada/CMake/tree/main/src/MPI). Hello world with MPI.
  - [ClangTidy](https://github.com/djeada/CMake/tree/main/src/ClangTidy). Example on how to integrate clang-tidy with CMake.
  - [GTest](https://github.com/djeada/CMake/tree/main/src/GTest ). Run google unit tests (GTest) with CMake.
  - Doxygen with CMake.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
