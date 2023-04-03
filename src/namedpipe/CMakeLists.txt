cmake_minimum_required(VERSION 3.5)

project(process1_and_process2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)


# Add executable for process1
add_executable(process1 process1.cpp)

# Add executable for process2
add_executable(process2 process2.cpp)
add_executable(process3 process3.cpp)

# Optionally link any required libraries
#target_link_libraries(process1 PUBLIC mylib1 mylib2)
#target_link_libraries(process2 PUBLIC mylib3 mylib4)