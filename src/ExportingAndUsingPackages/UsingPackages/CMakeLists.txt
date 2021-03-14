cmake_minimum_required(VERSION 3.0.0)

project(MY_PROJECT VERSION 1.0.0)

find_package(complex)

if(my_math_FOUND)
	message("complex library found")
	add_executable(exe main.cpp)
	target_link_libraries(exe complex)	
else()
	message(FATAL_ERROR "my_math library not found")
endif()
