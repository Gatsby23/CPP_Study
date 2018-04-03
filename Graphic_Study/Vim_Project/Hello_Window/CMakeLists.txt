cmake_minimum_required( VERSION 2.8 )
PROJECT(helloWindow)

# use the relative path
set(CMAKE_CXX_FLAGS "-std=c++11")

# set the complier
# set(CMAKE_CXX_COMPILER "g++")
# set(CMAKE_CXX_FLAGS "-lglfw")


# link the libraries
LINK_LIBRARIES(glfw)

add_definitions("-ldl")
# add the include
include_directories(../include)
set(helloWindow_src ${CMAKE_CURRENT_LIST_DIR}/src/Hello_Window.cpp ./src/glad.c)
# aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src ${helloWindow_src})

add_executable(${PROJECT_NAME} ${helloWindow_src})
target_link_libraries(${PROJECT_NAME} dl)
