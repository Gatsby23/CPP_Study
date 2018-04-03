cmake_minimum_required( VERSION 2.8 )
project( helloWindow )

# use the relative path
set(CMAKE_CXX_FLAGS "-std=c++11")

# add the include
include_directories(../include)

add_executable(Hello_Window Hello_Window.cpp)
