cmake_minimum_required(VERSION 2.8)

project(helloShaders)

set(CMAKE_CXX_FLAGS "-std=c++11")

LINK_LIBRARIES(glfw)
add_definitions(-ldl)

# add the include to make the glad into use
include_directories(../include)
set(helloShaders_src ${CMAKE_CURRENT_LIST_DIR}/src/hello_Shaders.cpp ./src/glad.c)

add_executable(${PROJECT_NAME} ${helloShaders_src})
target_link_libraries(${PROJECT_NAME} dl)
