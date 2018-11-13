cmake_minimum_required(VERSION 3.1)
project(variant)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/*.c" "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE headers "${PROJECT_SOURCE_DIR}/*.h" "${PROJECT_SOURCE_DIR}/*.hpp")

include_directories("include/")
add_executable(${PROJECT_NAME} ${sources} ${headers})
