cmake_minimum_required( VERSION 2.8 )
PROJECT(helloTriangle)

# use the c++11 standard
set(CMAKE_CXX_FLAGS "-std=c++11")

# link the libraries
LINK_LIBRARIES(glfw)
add_definitions(-ldl)


# add the include
include_directories(../include)
set(helloTriangle_src ${CMAKE_CURRENT_LIST_DIR}/src/hello_Triangle.cpp ../src/glad.c)

add_executable(${PROJECT_NAME} ${helloTriangle_src})
target_link_libraries(${PROJECT_NAME} dl)
