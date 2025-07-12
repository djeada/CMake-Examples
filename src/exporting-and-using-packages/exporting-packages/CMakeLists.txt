cmake_minimum_required(VERSION 3.0.0)

project(My_Project VERSION 1.0.0)


add_subdirectory(complex)
add_subdirectory(vector)


add_executable(project
main.cpp)


target_link_libraries(project PRIVATE complex  vector)
message("CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")


