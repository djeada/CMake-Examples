
cmake_minimum_required(VERSION 2.8)
PROJECT (Example_OpenCV)
find_package(OpenCV)

if(NOT OpenCV_FOUND)
    message(WARNING "OpenCV not found, skipping OpenCV example build.")
    return()
endif()

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exe main.cpp )

target_link_libraries( exe ${OpenCV_LIBS} )
