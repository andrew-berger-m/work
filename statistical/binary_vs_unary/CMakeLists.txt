cmake_minimum_required(VERSION 3.1)
project(binary_vs_unary)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE sources "src/*.c" "src/*.cpp")
file(GLOB_RECURSE headers "include/*.h" "include/*.hpp")
include_directories("include")

add_executable(${PROJECT_NAME} ${sources} ${headers})
