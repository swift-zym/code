cmake_minimum_required(VERSION 3.16)
project(NOI_online_R3)

set(CMAKE_CXX_STANDARD 14)

add_executable(NOI_online_R3 main.cpp)
add_executable(kettle kettle.cpp)
add_executable(magic magic.cpp)
add_executable(sequence sequence.cpp)