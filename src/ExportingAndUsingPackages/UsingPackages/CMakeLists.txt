cmake_minimum_required(VERSION 3.0.0)

project(MY_PROJECT VERSION 1.0.0)

# Use local complex and vector libraries from ExportingPackages
add_subdirectory("../ExportingPackages/complex" complex_lib)
add_subdirectory("../ExportingPackages/vector" vector_lib)

add_executable(exe main.cpp)
target_link_libraries(exe complex vector)
