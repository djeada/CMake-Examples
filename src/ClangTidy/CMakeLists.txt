cmake_minimum_required(VERSION 3.15.0)

project(Project_Name VERSION 1.0.0)

add_library(vector  
vector.cpp)

add_library(complex
complex.cpp)

add_executable(executable
main.cpp)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)

target_link_libraries(executable vector complex)

