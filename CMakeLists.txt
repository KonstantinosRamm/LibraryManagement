cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)  # Tells CMake to check include/ for headers

file(GLOB SOURCES "src/*.cpp")  # Automatically find all .cpp files
add_executable(LibrarySystem ${SOURCES})
