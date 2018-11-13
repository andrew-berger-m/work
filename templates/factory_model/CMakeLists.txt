cmake_minimum_required(VERSION 3.1)
project(factory_model)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE sources "src/*.c" "src/*.cpp")
file(GLOB_RECURSE headers "include/*.h" "include/*.hpp")
include_directories("include")

#does not work, executable will cause segemntation fault
#add_executable(${PROJECT_NAME} ${sources} ${headers})

add_executable(${PROJECT_NAME} "src/Base.cpp" "src/Factory.cpp" "src/main.cpp" "src/Example1.cpp" "src/Example2.cpp" "src/Example3.cpp" ${headers})
