# Cmake
Examples of projects with CMake.

<h1>Introduction</h1>

CMake is:
* cross-platform
* free 
* open-source
* compiler-independent

<h2>Compilation with gcc</h2>

When your project contains just three files (main.c code.c code.h), you can easily compily it from the terminal using following commands:

```bash
gcc -Wall -Wextra -Werror -std=c99 -pedantic -g -o exe code.c main.c
```

You have now an executable that you can run, called <i>exe</i>.

<h2>Using Makefiles for compilation</h2>

When working with many files, it becomes nearly impossible to use command line commands for compilation.
Instead you can use configuration files in which you specify which files and with which flags you want to compile.

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

You can run it with the following command:

```bash
make
```

<h2>Using CMake for compilation</h2>

Build systems like <i>Make</i> are usualy platform specific.
You can however use a meta build system like CMake which is platform independent.

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

You can run it with the following commands:

```bash
mkdir build
cd build
cmake..
cmake --build .
```

<h2>Make vs CMake</h2>

Make is a build system.
CMake is a build system generator.
You can use CMake to generate Makefiles, but it can also work with Ninja, KDEvelop and Xcode projects, as well as Visual Studio solutions

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

<h1>Requirements</h1>
 
In order to run our examples you need the following:

* CMake v3.15+
* gcc
* make

<h1>Table of contents</h1>

  - [An executable and libraries](https://github.com/djeada/CMake/tree/main/src/ExecutableAndLibraries). A simple example with three .cpp files and two .h files, all in the same folder.
  - [Subdirectories](https://github.com/djeada/CMake/tree/main/src/Subdirectories). Project with subdirectories, each with individual CMakeList.txt file.
