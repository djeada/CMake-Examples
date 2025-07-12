cmake_minimum_required(VERSION 3.0.0)

project(mpi_project)

find_package(MPI)
if(MPI_FOUND)
    include_directories(${MPI_INCLUDE_PATH})
    add_executable(exe hello_mpi.cpp)
    target_link_libraries(exe ${MPI_LIBRARIES})
endif()
