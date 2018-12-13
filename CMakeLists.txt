cmake_minimum_required( VERSION 3.10 )
project( unit_test )

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopt-info")

#find_package(MPI REQUIRED)
#include_directories(${MPI_INCLUDE_PATH})

#SET(CMAKE_C_COMPILER mpicc)
#SET(CMAKE_CXX_COMPILER mpicxx)

set(SOURCE_FILES main.cpp transaction.cpp)
add_executable(unit_test ${SOURCE_FILES})