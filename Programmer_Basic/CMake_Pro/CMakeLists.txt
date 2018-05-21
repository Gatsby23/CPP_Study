project(CMake_Pro)
cmake_minimum_required(VERSION 2.8)

message(STATUS "The source file loading")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
