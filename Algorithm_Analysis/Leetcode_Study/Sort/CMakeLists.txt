cmake_minimum_required(VERSION 2.8)
project(SORT_PROGRAM)

set(CMAKE_BUILD_TYPE "Debug")

# use the C++11 standard
set(CMAKE_CXX_FLAGS "-std=c++11")

#设置编译头文件和对应文件
set(PRO_HEARDERS SortTestHelper.h Insertion_Sort.h)
set(PRO_SOURCE Sort_Test.cpp)

add_executable(${PROJECT_NAME} ${PRO_HEADERS} ${PRO_SOURCE})
