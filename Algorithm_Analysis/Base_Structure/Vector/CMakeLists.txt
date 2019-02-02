cmake_minimum_required(VERSION 2.8)
project(Vector)

# Check CXX11 support
add_definitions(-DCOMPILEDWITHC11)

set(CMAKE_MACOSX_RPATH 0)

# include the directories
include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/include)


#add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR})
#link_directories(${PROJECT_SOUCE_DIR}/build)

add_executable(vector_test vector_test.cc)
#target_link_libraries(vector_test ${PROJECT_NAME})
